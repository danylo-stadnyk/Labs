#pragma once
#include <iostream>
#include <string>

class Microcontroller {
private:
    std::string architecture;
    int frequency;
    int ports;
public:
    Microcontroller(const std::string& arch, int freq, int prts)
        : architecture(arch), frequency(freq), ports(prts) {
        std::cout << "Microcontroller створено: " << architecture << std::endl;
    }
    ~Microcontroller() {
        std::cout << "Microcontroller знищено: " << architecture << std::endl;
    }

    void display() const {
        std::cout << architecture << ", частота: " << frequency
                  << " МГц, порти: " << ports;
    }
};
