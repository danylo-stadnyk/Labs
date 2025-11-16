#include "OpticsFriend.h"
#include <iostream>

int main() {
    std::vector<OpticalComponent*> components;
    OpticsFriend friendObj;

    friendObj.inputComponents(components);
    friendObj.printAll(components);

    double total = friendObj.computeTotalValue(components);
    std::cout << "\nTotal value (sum of lux/mW): " << total << "\n";

    for (auto c : components) delete c;

    return 0;
}
