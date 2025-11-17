#ifndef PHOTORESISTOR_H
#define PHOTORESISTOR_H

#include "OpticalComponent.h"

class Photoresistor : public OpticalComponent {
private:
    double resistance;

public:
    Photoresistor() 
        : OpticalComponent("Photoresistor", 0), resistance(0) {}

    Photoresistor(std::string name, double intensity, double resistance)
        : OpticalComponent(name, intensity), resistance(resistance) {}

    ~Photoresistor() {}

    void printInfo() const override {
        std::cout << "Photoresistor: " << data.name 
                  << " | Intensity: " << data.intensity 
                  << " lux | Resistance: " << resistance << " Ohm\n";
    }

    friend class OpticsFriend;
};

#endif
