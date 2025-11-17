#ifndef OPTICALCOMPONENT_H
#define OPTICALCOMPONENT_H

#include <iostream>
#include <string>

struct ComponentData {
    std::string name;
    double intensity;   // спільний фізичний параметр
};

class OpticalComponent {
protected:
    ComponentData data;

public:
    OpticalComponent() : data({"unnamed", 0}) {}

    OpticalComponent(std::string name, double intensity) {
        data.name = name;
        data.intensity = intensity;
    }

    virtual ~OpticalComponent() {}

    virtual void printInfo() const {
        std::cout << "Component: " << data.name 
                  << " | Intensity: " << data.intensity << " lux\n";
    }

    friend class OpticsFriend;
};

#endif
