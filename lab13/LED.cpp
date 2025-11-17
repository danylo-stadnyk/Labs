#include "LED.h"
#include "Exceptions.h"
#include <iostream>


LED::LED(): OpticalComponent(), forwardVoltage(0.0), luminousIntensity(0.0) {}
LED::LED(int id, const std::string &model, const Spec &s, double vf, double li)
: OpticalComponent(id, model, s), forwardVoltage(vf), luminousIntensity(li) {}
LED::~LED() {}


void LED::print(std::ostream &os) const {
os << "[LED] ";
OpticalComponent::print(os);
os << ", Vf=" << forwardVoltage << "V, I=" << luminousIntensity << "mcd";
}


void LED::serialize(std::ostream &os) const {
os << "LED " << id << " " << model << " " << spec.value << " " << spec.unit
<< " " << forwardVoltage << " " << luminousIntensity << '\n';
}


void LED::deserialize(std::istream &is) {
if (!(is >> id >> model >> spec.value >> spec.unit >> forwardVoltage >> luminousIntensity))
throw InputException("Failed to deserialize LED");
}