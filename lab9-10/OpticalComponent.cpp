#include "OpticalComponent.h"


OpticalComponent::OpticalComponent(string n, string t) : name(n), type(t) {}
OpticalComponent::~OpticalComponent() {}

void OpticalComponent::inputData() {
    cout << "Введіть назву компонента: ";
    getline(cin, name);
    cout << "Введіть тип компонента: ";
    getline(cin, type);
}

void OpticalComponent::displayData() const {
    cout << "Назва: " << name << "\nТип: " << type << endl;
}


LED::LED() : OpticalComponent("Світлодіод", "LED"), power(0), brightness(0) {}

void LED::inputData() {
    OpticalComponent::inputData();
    cout << "Введіть потужність (Вт): ";
    cin >> power;
    while (power <= 0) {
        cout << "❌ Некоректне значення! Введіть додатнє число: ";
        cin >> power;
    }
    cout << "Введіть яскравість (лм): ";
    cin >> brightness;
    while (brightness <= 0) {
        cout << "❌ Некоректне значення! Введіть додатнє число: ";
        cin >> brightness;
    }
    cin.ignore();
}

void LED::displayData() const {
    OpticalComponent::displayData();
    cout << "Потужність: " << power << " Вт\n"
         << "Яскравість: " << brightness << " лм\n"
         << "Ефективність: " << getEfficiency() << " лм/Вт\n";
}

double LED::getEfficiency() const {
    return brightness / power;
}


Photoresistor::Photoresistor() : OpticalComponent("Фоторезистор", "Photoresistor"), resistance(0), lightLevel(0) {}

void Photoresistor::inputData() {
    OpticalComponent::inputData();
    cout << "Введіть опір (Ом): ";
    cin >> resistance;
    while (resistance <= 0) {
        cout << "❌ Некоректне значення! Введіть додатнє число: ";
        cin >> resistance;
    }
    cout << "Введіть рівень освітленості (Лк): ";
    cin >> lightLevel;
    while (lightLevel <= 0) {
        cout << "❌ Некоректне значення! Введіть додатнє число: ";
        cin >> lightLevel;
    }
    cin.ignore();
}

void Photoresistor::displayData() const {
    OpticalComponent::displayData();
    cout << "Опір: " << resistance << " Ом\n"
         << "Освітленість: " << lightLevel << " Лк\n"
         << "Ефективність: " << getEfficiency() << " Ом/Лк\n";
}

double Photoresistor::getEfficiency() const {
    return resistance / lightLevel;
}
