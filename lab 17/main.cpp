#include <iostream>
#include <string>
#include "Microcontroller.h"
#include "Repository.h"

int main()
{
    

    Microcontroller mcu1("ARM Cortex-M4", 72.0, 48);
    Microcontroller mcu2("AVR", 16.0, 32);

    std::cout << "=== Інформація про мікроконтролери ===\n";
    mcu1.printInfo();
    std::cout << "\n";
    mcu2.printInfo();
    std::cout << "\n\n";

    

    Repository<int> intRepo(10);
    Repository<std::string> stringRepo("Шаблонний рядок");

    std::cout << "=== Загальний шаблон Repository<T> ===\n";
    intRepo.print();
    stringRepo.print();
    std::cout << "\n";

    

    Repository<Microcontroller> mcuRepo(mcu1);

    std::cout << "=== Повна спеціалізація Repository<Microcontroller> ===\n";
    mcuRepo.print();
    std::cout << "\n";

    

    Microcontroller* mcuPtr = &mcu2;
    Repository<Microcontroller*> mcuPtrRepo(mcuPtr);

    std::cout << "=== Часткова спеціалізація Repository<T*> ===\n";
    mcuPtrRepo.print();
    std::cout << "\n";

   

    int a = 5;
    int b = 9;
    double da = 3.14;
    double db = 2.71;

    std::cout << "=== Шаблон функції maxValue<T> ===\n";
    std::cout << "maxValue<int>(" << a << ", " << b << ") = "
              << maxValue(a, b) << "\n\n";

    std::cout << "=== Повна спеціалізація maxValue<double> ===\n";
    double dmax = maxValue(da, db);
    std::cout << "maxValue<double>(" << da << ", " << db << ") = "
              << dmax << "\n";

    return 0;
}
