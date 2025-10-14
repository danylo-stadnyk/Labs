#include <iostream>
#include <string>
#include <vector>

class mc {
private:
    std::string architecture;
    int frequency;
    int ports;

public:
    mc() {
        architecture = "ARM";
        frequency = 16;
        ports = 23;
    }

    void input() {
        std::cout << "Enter architecture: ";
        std::cin >> architecture;

        std::cout << "Enter frequency (MHz): ";
        std::cin >> frequency;
        while (frequency < 0) {
            std::cout << "Invalid, enter again: ";
            std::cin >> frequency;
        }

        std::cout << "Enter number of ports: ";
        std::cin >> ports;
        while (ports < 0) {
            std::cout << "Invalid, enter again: ";
            std::cin >> ports;
        }
    }

    void show() const {
        std::cout << "Architecture: " << architecture << '\n';
        std::cout << "Frequency (MHz): " << frequency << '\n';
        std::cout << "Ports: " << ports << "\n\n";
    }

    int getFrequency() const { return frequency; }
    std::string getArchitecture() const { return architecture; }
};


int main() {
    int n;
    std::cout << "Enter number of microcontrollers: ";
    std::cin >> n;

    std::vector<mc> controllers(n);
    for (int i = 0; i < n; ++i) {
        std::cout << "\n--- Controller " << i + 1 << " ---\n";
        controllers[i].input();
    }

    std::cout << "\nAll entered controllers:\n";
    for (const auto& c : controllers)
        c.show();

    int minFreq;
    std::cout << "Enter minimum frequency to search for: ";
    std::cin >> minFreq;

    bool found = false;
    std::cout << "\nControllers with frequency >= " << minFreq << " MHz:\n";
    for (const auto& c : controllers) {
        if (c.getFrequency() >= minFreq) {
            c.show();
            found = true;
        }
    }

    if (!found) {
        std::cout << "No controllers match the criterion.\n";
    }

    return 0;
}