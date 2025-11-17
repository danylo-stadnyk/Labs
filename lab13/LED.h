#ifndef LED_H
#define LED_H


#include "OpticalComponent.h"


class LED: public OpticalComponent {
double forwardVoltage; 
double luminousIntensity; 
public:
LED();
LED(int id, const std::string &model, const Spec &s, double vf, double li);
~LED() override;


void print(std::ostream &os) const override;
void serialize(std::ostream &os) const override;
void deserialize(std::istream &is) override;
};


#endif