#include <iostream>
#include "microcontroller.h"

int main() {
    
    Microcontroller mcu1("ARM Cortex-M4", 72.0, 40);

    std::cout << "\nПочаткова інформація:\n";
    mcu1.displayInfo();

    
    overclockMicrocontroller(mcu1, 100.0);

    std::cout << "\nОновлена інформація:\n";
    mcu1.displayInfo();

    return 0;
}
