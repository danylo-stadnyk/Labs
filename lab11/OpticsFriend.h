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

        for (int i = 0; i < n; i++) {
            int type;
            std::cout << "1 - LED, 2 - Photoresistor: ";
            std::cin >> type;

            if (type == 1) {
                std::string name; 
                double power, wavelength;
                std::cout << "LED name: ";
                std::cin >> name;
                std::cout << "Power(mW): ";
                std::cin >> power;
                std::cout << "Wavelength(nm): ";
                std::cin >> wavelength;

                arr.push_back(new LED(name, power, wavelength));
            }
            else {
                std::string name;
                double lux, resistance;
                std::cout << "Photoresistor name: ";
                std::cin >> name;
                std::cout << "Lux: ";
                std::cin >> lux;
                std::cout << "Resistance(Ohm): ";
                std::cin >> resistance;

                arr.push_back(new Photoresistor(name, lux, resistance));
            }
        }
    }

    void printAll(const std::vector<OpticalComponent*>& arr) {
        std::cout << "\n--- Components List ---\n";
        for (auto c : arr) 
            c->printInfo();
    }

    double computeTotalValue(const std::vector<OpticalComponent*>& arr) {
        double total = 0;
        for (auto c : arr)
            total += c->data.value;   
        return total;
    }
};

#endif
