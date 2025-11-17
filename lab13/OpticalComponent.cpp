#include "OpticalComponent.h"
#include "Exceptions.h"
#include <iostream>


OpticalComponent::OpticalComponent(): id(0), model("Unknown"), spec{0.0, ""} {}
OpticalComponent::OpticalComponent(int id, const std::string &model, const Spec &s)
: id(id), model(model), spec(s) {}
OpticalComponent::~OpticalComponent() {}


void OpticalComponent::print(std::ostream &os) const {
os << "ID: " << id << ", Model: " << model
<< ", Spec: " << spec.value << " " << spec.unit;
}


void OpticalComponent::serialize(std::ostream &os) const {

os << "OPTICAL " << id << " " << model << " " << spec.value << " " << spec.unit << '\n';
}


void OpticalComponent::deserialize(std::istream &is) {

if (!(is >> id >> model >> spec.value >> spec.unit)) {
throw InputException("Failed to deserialize OpticalComponent");
}
}


int OpticalComponent::getId() const { return id; }
std::string OpticalComponent::getModel() const { return model; }


OpticalComponent OpticalComponent::operator+(const OpticalComponent &other) const {

Spec s{ spec.value + other.spec.value, spec.unit };
return OpticalComponent(0, model + "+" + other.model, s);
}


bool OpticalComponent::operator==(const OpticalComponent &other) const {
return id == other.id;
}


std::ostream& operator<<(std::ostream &os, const OpticalComponent &c) {
c.print(os);
return os;
}


std::istream& operator>>(std::istream &is, OpticalComponent &c) {

if (!(is >> c.id >> c.model >> c.spec.value >> c.spec.unit)) {
is.setstate(std::ios::failbit);
}
return is;
}