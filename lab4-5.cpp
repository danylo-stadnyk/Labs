#include <iostream>
#include <string>
#include <vector>
#include <limits> 

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
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
        std::cout << "Enter architecture: ";
        std::getline(std::cin, architecture);

        
        std::cout << "Enter frequency (MHz): ";
        while (!(std::cin >> frequency) || frequency < 0) {
            std::cout << "Invalid input. Enter positive number: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        
        std::cout << "Enter number of ports: ";
        while (!(std::cin >> ports) || ports < 0) {
            std::cout << "Invalid input. Enter positive number: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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
    while (!(std::cin >> n) || n <= 0) {
        std::cout << "Invalid input. Enter positive integer: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

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
    while (!(std::cin >> minFreq) || minFreq < 0) {
        std::cout << "Invalid input. Enter positive number: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

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
