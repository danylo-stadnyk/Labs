#include "microcontroler.h"


Microcontroler::Microcontroler() {
    count = 0;
    std::cout << "Об'єкт класу Microcontroler створено." << std::endl;
}


Microcontroler::~Microcontroler() {
    std::cout << "Об'єкт класу Microcontroler знищено." << std::endl;
}


bool Microcontroler::isValid(const Microcontroler_s_t &mc) const {
    if (mc.architecture.empty()) {
        std::cout << "Помилка: архітектура не може бути порожньою!" << std::endl;
        return false;
    }
    if (mc.frequency <= 0) {
        std::cout << "Помилка: частота повинна бути більшою за 0!" << std::endl;
        return false;
    }
    if (mc.ports < 0) {
        std::cout << "Помилка: кількість портів не може бути від’ємною!" << std::endl;
        return false;
    }
    return true;
}


void Microcontroler::inputData() {
    std::cout << "Скільки мікроконтролерів ви хочете ввести (макс " << SIZE << "): ";
    std::cin >> count;

    if (count > SIZE) {
        std::cout << "Ви перевищили максимальну кількість! Буде використано " << SIZE << "." << std::endl;
        count = SIZE;
    }

    std::cin.ignore(); 

    for (int i = 0; i < count; i++) {
        Microcontroler_s_t temp;

        std::cout << "\nВведіть дані для мікроконтролера #" << i + 1 << std::endl;
        std::cout << "Архітектура: ";
        std::getline(std::cin, temp.architecture);

        std::cout << "Частота (MHz): ";
        std::cin >> temp.frequency;

        std::cout << "Кількість портів: ";
        std::cin >> temp.ports;
        std::cin.ignore();

        if (isValid(temp)) {
            microcontrolers.at(i) = temp;
        } else {
            std::cout << "Некоректні дані, цей запис пропущено." << std::endl;
        }
    }
}


void Microcontroler::outputData() const {
    std::cout << "\n=== Дані про мікроконтролери ===" << std::endl;
    for (int i = 0; i < count; i++) {
        const Microcontroler_s_t &mc = microcontrolers.at(i);
        std::cout << "Мікроконтролер #" << i + 1 << std::endl;
        std::cout << "  Архітектура: " << mc.architecture << std::endl;
        std::cout << "  Частота: " << mc.frequency << " MHz" << std::endl;
        std::cout << "  Кількість портів: " << mc.ports << std::endl;
        std::cout << "-----------------------------" << std::endl;
    }
}
