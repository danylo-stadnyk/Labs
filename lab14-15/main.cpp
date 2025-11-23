#include <iostream>
#include "LinkedList.h"

int main() {
    LinkedList list;

    Microcontroller m1("ARM Cortex-M0", 48, 20);
    Microcontroller m2("AVR", 16, 28);
    Microcontroller m3("PIC", 20, 16);
    Microcontroller m4("ARM Cortex-M4", 168, 40);

    list.push_front(m1);
    list.push_back(m2);
    list.push_back(m3);

    list.display();

    std::cout << "\nВставка після AVR:\n";
    list.insert_after(m2, m4);
    list.display();

    std::cout << "\nВидалення першого елемента:\n";
    list.pop_front();
    list.display();

    std::cout << "\nВидалення останнього елемента:\n";
    list.pop_back();
    list.display();

    std::cout << "\nВидалення елемента PIC:\n";
    list.remove_value(m3);
    list.display();

    return 0;
}
