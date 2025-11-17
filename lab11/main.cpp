#include "OpticsFriend.h"
#include <iostream>

int main() {
    std::vector<OpticalComponent*> components;
    OpticsFriend friendObj;

    friendObj.inputComponents(components);
    friendObj.printAll(components);

    double total = friendObj.computeTotalIntensity(components);
    std::cout << "\nTotal intensity (lux): " << total << "\n";

    for (auto c : components) delete c;

    return 0;
}
