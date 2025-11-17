#ifndef LED_H
#define LED_H

#include "OpticalComponent.h"

class LED : public OpticalComponent {
private:
    double wavelength;

public:
    LED() : OpticalComponent("LED", 0), wavelength(0) {}

    LED(std::string name, double intensity, double wavelength)
        : OpticalComponent(name, intensity), wavelength(wavelength) {}

    ~LED() {}

    void printInfo() const override {
        std::cout << "LED: " << data.name 
                  << " | Intensity: " << data.intensity 
                  << " lux | Wavelength: " << wavelength << " nm\n";
    }

    friend class OpticsFriend;
};

#endif
