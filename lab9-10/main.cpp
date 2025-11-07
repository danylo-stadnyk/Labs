#include <iostream>
#include <vector>
#include "OpticalComponent.h"
using namespace std;

int main() {
    vector<OpticalComponent*> components;
    int choice;

    do {
        cout << "\n=== Оптичні компоненти ===\n";
        cout << "1. Додати світлодіод\n";
        cout << "2. Додати фоторезистор\n";
        cout << "3. Вивести всі компоненти\n";
        cout << "0. Вихід\n";
        cout << "Ваш вибір: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            LED* led = new LED();
            led->inputData();
            components.push_back(led);
        } 
        else if (choice == 2) {
            Photoresistor* pr = new Photoresistor();
            pr->inputData();
            components.push_back(pr);
        } 
        else if (choice == 3) {
            cout << "\n=== Список компонентів ===\n";
            for (auto c : components) {
                c->displayData();
                cout << "-------------------------\n";
            }
        }
    } while (choice != 0);

    for (auto c : components)
        delete c;

    cout << "Роботу завершено.\n";
    return 0;
}
