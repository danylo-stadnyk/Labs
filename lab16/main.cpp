#include "Microcontroller.h"
#include "SmartList.h"
#include <memory>
#include <iostream>

int main() {
    
    std::unique_ptr<Microcontroller> mc1 = std::make_unique<Microcontroller>("ARM Cortex-M0", 48, 20);
    auto mc2 = std::move(mc1);
    if (!mc1) std::cout << "mc1 тепер nullptr\n";

    
    std::shared_ptr<Microcontroller> smc1 = std::make_shared<Microcontroller>("AVR", 16, 28);
    std::shared_ptr<Microcontroller> smc2 = smc1;
    std::cout << "Кількість посилань: " << smc1.use_count() << "\n";

    
    std::weak_ptr<Microcontroller> wmc = smc1;
    std::cout << "weak_ptr не збільшує use_count: " << smc1.use_count() << "\n";

    
    SmartList list;
    list.push_back(std::make_shared<Microcontroller>("PIC", 20, 16));
    list.push_back(std::make_shared<Microcontroller>("ARM Cortex-M4", 168, 40));
    list.display_forward();
    list.display_backward();

    return 0;
}

