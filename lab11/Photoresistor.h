#ifndef PHOTORESISTOR_H
#define PHOTORESISTOR_H

#include "OpticalComponent.h"

class Photoresistor : public OpticalComponent {
private:
    double resistance;

public:
    Photoresistor() 
        : OpticalComponent("Photoresistor", 0), resistance(0) {}

    Photoresistor(std::string name, double lux, double resistance)
        : OpticalComponent(name, lux), resistance(resistance) {}

    ~Photoresistor() {}

    void printInfo() const override {
        std::cout << "Photoresistor: " << data.name 
                  << " | Lux: " << data.value 
                  << " | Resistance: " << resistance << " Ohm\n";
    }

    friend class OpticsFriend;
};

#endif
