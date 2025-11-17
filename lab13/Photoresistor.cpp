#include "Photoresistor.h"
#include "Exceptions.h"
#include <iostream>


Photoresistor::Photoresistor(): OpticalComponent(), resistanceDark(0.0), resistanceLight(0.0) {}
Photoresistor::Photoresistor(int id, const std::string &model, const Spec &s, double rd, double rl)
: OpticalComponent(id, model, s), resistanceDark(rd), resistanceLight(rl) {}
Photoresistor::~Photoresistor() {}


void Photoresistor::print(std::ostream &os) const {
os << "[Photoresistor] ";
OpticalComponent::print(os);
os << ", R_dark=" << resistanceDark << "\u03A9, R_light=" << resistanceLight << "\u03A9";
}


void Photoresistor::serialize(std::ostream &os) const {
os << "PHR " << id << " " << model << " " << spec.value << " " << spec.unit
<< " " << resistanceDark << " " << resistanceLight << '\n';
}


void Photoresistor::deserialize(std::istream &is) {
if (!(is >> id >> model >> spec.value >> spec.unit >> resistanceDark >> resistanceLight))
throw InputException("Failed to deserialize Photoresistor");
}