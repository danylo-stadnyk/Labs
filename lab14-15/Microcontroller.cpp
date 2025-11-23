#include "Microcontroller.h"

Microcontroller::Microcontroller() : architecture("Unknown"), frequency(0), ports(0) {}

Microcontroller::Microcontroller(std::string arch, double freq, int p)
    : architecture(arch), frequency(freq), ports(p) {}

std::string Microcontroller::getArchitecture() const { return architecture; }
double Microcontroller::getFrequency() const { return frequency; }
int Microcontroller::getPorts() const { return ports; }

void Microcontroller::setArchitecture(const std::string& arch) { architecture = arch; }
void Microcontroller::setFrequency(double freq) { frequency = freq; }
void Microcontroller::setPorts(int p) { ports = p; }

bool Microcontroller::operator==(const Microcontroller& other) const {
    return architecture == other.architecture &&
           frequency == other.frequency &&
           ports == other.ports;
}
