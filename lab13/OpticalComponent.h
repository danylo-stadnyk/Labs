#ifndef OPTICAL_COMPONENT_H
#define OPTICAL_COMPONENT_H


#include <string>
#include <ostream>
#include <istream>


struct Spec {
double value;
std::string unit;
};


class OpticalComponent {
protected:
int id;
std::string model;
Spec spec;
public:
OpticalComponent();
OpticalComponent(int id, const std::string &model, const Spec &s);
virtual ~OpticalComponent();


virtual void print(std::ostream &os) const;
virtual void serialize(std::ostream &os) const; 
virtual void deserialize(std::istream &is); 



int getId() const;
std::string getModel() const;



OpticalComponent operator+(const OpticalComponent &other) const;



bool operator==(const OpticalComponent &other) const;


friend std::ostream& operator<<(std::ostream &os, const OpticalComponent &c);
friend std::istream& operator>>(std::istream &is, OpticalComponent &c);
};


#endif