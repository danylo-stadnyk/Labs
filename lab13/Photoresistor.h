#ifndef PHOTORESISTOR_H
#define PHOTORESISTOR_H


#include "OpticalComponent.h"


class Photoresistor: public OpticalComponent {
double resistanceDark; 
double resistanceLight; 
public:
Photoresistor();
Photoresistor(int id, const std::string &model, const Spec &s, double rd, double rl);
~Photoresistor() override;


void print(std::ostream &os) const override;
void serialize(std::ostream &os) const override;
void deserialize(std::istream &is) override;
};


#endif