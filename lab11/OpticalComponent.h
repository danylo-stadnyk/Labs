#ifndef OPTICALCOMPONENT_H
#define OPTICALCOMPONENT_H

#include <iostream>
#include <string>

struct ComponentData {
    std::string name;
    double value;
};

class OpticalComponent {
protected:
    ComponentData data;

public:
    OpticalComponent() : data({"unnamed", 0}) {}

    OpticalComponent(std::string name, double value) {
        data.name = name;
        data.value = value;
    }

    virtual ~OpticalComponent() {}

    virtual void printInfo() const {
        std::cout << "Component: " << data.name 
                  << " | Value: " << data.value << "\n";
    }

    friend class OpticsFriend;
};

#endif
