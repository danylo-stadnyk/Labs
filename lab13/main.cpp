#include <iostream>
#include <fstream>
#include <sstream>
#include <memory>
#include <string>

#include "Exceptions.h"
#include "OpticalComponent.h"
#include "LED.h"
#include "Photoresistor.h"
#include "ComponentCollection.h"

using namespace std;


void saveAll(const string &filename, const ComponentCollection &col) {
    fstream fs;
    fs.open(filename, ios::out | ios::trunc);
    if (!fs.is_open())
        throw FileException("Cannot open file for writing: " + filename);

    for (size_t i = 0; i < col.size(); ++i) {
        col[i].serialize(fs);   
    }

    fs.close();
}


void appendToFile(const string &filename, const OpticalComponent &comp) {
    fstream fs;
    fs.open(filename, ios::out | ios::app);

    if (!fs.is_open())
        throw FileException("Cannot open file for appending: " + filename);

    comp.serialize(fs);
    fs.close();
}


void loadAll(const string &filename, ComponentCollection &col) {
    fstream fs;
    fs.open(filename, ios::in);

    if (!fs.is_open())
        throw FileException("Cannot open file for reading: " + filename);

    string type;

    while (fs >> type) {

        if (type == "LED") {
            auto led = make_unique<LED>();
            led->deserialize(fs);
            col.add(move(led));

        } else if (type == "PHR") {
            auto phr = make_unique<Photoresistor>();
            phr->deserialize(fs);
            col.add(move(phr));

        } else if (type == "OPTICAL") {
            auto oc = make_unique<OpticalComponent>();
            oc->deserialize(fs);
            col.add(move(oc));

        } else {
            string rest;
            getline(fs, rest); 
            cerr << "Warning: unknown entry type in file: " << type << "\n";
        }
    }

    fs.close();
}


int main() {
    try {
        ComponentCollection col;

        cout << "--- Demo: add LED and Photoresistor ---\n";

        auto led = make_unique<LED>(1, "LED-Red", Spec{2.0, "mm"}, 2.1, 4500.0);
        auto phr = make_unique<Photoresistor>(2, "LDR-10", Spec{10.0, "mm"}, 100000.0, 500.0);

        col.add(move(led));
        col.add(move(phr));

        saveAll("components.txt", col);
        cout << "Saved to file.\n";

        ComponentCollection loadCol;
        loadAll("components.txt", loadCol);
        cout << "Loaded from file.\n";

        cout << "--- Loaded items ---\n";
        for (size_t i = 0; i < loadCol.size(); ++i) {
            
            loadCol[i].print(cout);
            cout << "\n";
        }

    } catch (const FileException &fe) {
        cerr << "FileException: " << fe.what() << "\n";
        return 2;
    } catch (const InputException &ie) {
        cerr << "InputException: " << ie.what() << "\n";
        return 3;
    } catch (const std::exception &ex) {
        cerr << "std::exception: " << ex.what() << "\n";
        return 4;
    } catch (...) {
        cerr << "Unknown error occurred.\n";
        return 5;
    }

    return 0;
}