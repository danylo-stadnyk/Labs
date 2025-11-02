#include "microcontroller.h"
#include <iostream>


Microcontroller::Microcontroller() {
    architecture = "Unknown";
    frequency = 0.0;
    ports = 0;
    std::cout << "Викликано конструктор за замовчуванням\n";
}


Microcontroller::Microcontroller(const std::string& arch, double freq, int portCount) {
    if (freq < 0) freq = 0;
    if (portCount < 0) portCount = 0;

    architecture = arch;
    frequency = freq;
    ports = portCount;

    std::cout << "Викликано конструктор з параметрами\n";
}


Microcontroller::~Microcontroller() {
    std::cout << "Звільнення об’єкта мікроконтролера\n";
}


void Microcontroller::displayInfo() const {
    std::cout << "Архітектура: " << architecture
              << "\nЧастота: " << frequency << " MHz"
              << "\nКількість портів: " << ports << std::endl;
}


void Microcontroller::setArchitecture(const std::string& arch) {
    if (!arch.empty()) architecture = arch;
    else std::cout << "Помилка: архітектура не може бути порожньою!\n";
}


void Microcontroller::setFrequency(double freq) {
    if (freq > 0) frequency = freq;
    else std::cout << "Помилка: частота має бути додатною!\n";
}


void Microcontroller::setPorts(int portCount) {
    if (portCount >= 0) ports = portCount;
    else std::cout << "Помилка: кількість портів не може бути від’ємною!\n";
}


void overclockMicrocontroller(Microcontroller& mcu, double newFreq) {
    std::cout << "\nЗміна частоти мікроконтролера через посилання...\n";
    mcu.setFrequency(newFreq);
}
