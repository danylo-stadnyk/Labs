#ifndef OPTICSFRIEND_H
#define OPTICSFRIEND_H

#include "OpticalComponent.h"
#include "LED.h"
#include "Photoresistor.h"
#include <vector>
#include <iostream>

class OpticsFriend {
public:
    OpticsFriend() {}
    ~OpticsFriend() {}

    void inputComponents(std::vector<OpticalComponent*>& arr) {
        int n;
        std::cout << "How many components? ";
        std::cin >> n;
        std::cin.ignore(); 

        for (int i = 0; i < n; i++) {
            int type;
            std::cout << "\n1 - LED, 2 - Photoresistor: ";
            std::cin >> type;
            std::cin.ignore(); 

            std::string name;
            double intensity;

            std::cout << "Name: ";
            std::getline(std::cin, name);

            std::cout << "Intensity (lux): ";
            std::cin >> intensity;

            if (type == 1) {
                double wavelength;
                std::cout << "Wavelength (nm): ";
                std::cin >> wavelength;

                arr.push_back(new LED(name, intensity, wavelength));
            }
            else {
                double resistance;
                std::cout << "Resistance (Ohm): ";
                std::cin >> resistance;

                arr.push_back(new Photoresistor(name, intensity, resistance));
            }
            std::cin.ignore();
        }
    }

    void printAll(const std::vector<OpticalComponent*>& arr) {
        std::cout << "\n--- Components List ---\n";
        for (auto c : arr)
            c->printInfo();
    }

    double computeTotalIntensity(const std::vector<OpticalComponent*>& arr) {
        double total = 0;
        for (auto c : arr)
            total += c->data.intensity;
        return total;
    }
};

#endif
