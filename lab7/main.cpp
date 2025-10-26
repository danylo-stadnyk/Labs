#include "microcontroller.h"
#include <iostream>
#include <windows.h>

int main() {
    SetConsoleOutputCP(65001);

    MicrocontrollerManager mgr;

    
    auto m1 = mgr.createDevice("STM32F407", "ARM Cortex-M4", 168, 96);
    auto m2 = mgr.createDevice("ATmega328P", "AVR", 16, 23);
    auto m3 = mgr.createDevice("ESP32", "Tensilica Xtensa", 240, 40);

    std::cout << "Початковий список пристроїв:\n";
    mgr.printAll();
    std::cout << "\n";

    
    Microcontroller inserted;
    inserted.id = 999; 
    inserted.name = "PIC16F877A";
    inserted.architecture = "PIC";
    inserted.frequency_mhz = 20;
    inserted.ports_count = 35;
    mgr.insertDeviceAt(1, inserted);

    std::cout << "Після вставки на позицію 1:\n";
    mgr.printAll();
    std::cout << "\n";

   
    bool ok = mgr.updateDevice(m1.id, "STM32F407VG", "ARM Cortex-M4", 168, 112);
    std::cout << "Оновлення STM32: " << (ok ? "успіх" : "помилка") << "\n\n";

   
    mgr.swapById(m2.id, m3.id);
    std::cout << "Після обміну ATmega <-> ESP32:\n";
    mgr.printAll();
    std::cout << "\n";

    
    mgr.removeById(m2.id);
    std::cout << "Після видалення (id=" << m2.id << "):\n";
    mgr.printAll();
    std::cout << "\n";

    
    bool bad = mgr.updateDevice(m3.id, "ESP32-Dev", "Tensilica Xtensa", 0, 38);
    std::cout << "Спроба некоректного оновлення (частота=0): " << (bad ? "успіх" : "помилка") << "\n\n";

    
    mgr.clearAll();
    std::cout << "Після очищення:\n";
    mgr.printAll();

    return 0;
}
