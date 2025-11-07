#ifndef OPTICALCOMPONENT_H
#define OPTICALCOMPONENT_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;


class OpticalComponent {
protected:
    string name;
    string type;

public:
    OpticalComponent(string n = "Невідомо", string t = "Оптичний компонент");
    virtual ~OpticalComponent();

    virtual void inputData();
    virtual void displayData() const;
    virtual double getEfficiency() const = 0; 
};


class LED : public OpticalComponent {
private:
    double power;       
    double brightness;  

public:
    LED();
    void inputData() override;
    void displayData() const override;
    double getEfficiency() const override;
};


class Photoresistor : public OpticalComponent {
private:
    double resistance;  
    double lightLevel;  

public:
    Photoresistor();
    void inputData() override;
    void displayData() const override;
    double getEfficiency() const override;
};

#endif
