#include "Microcontroller.h"


Microcontroller::Microcontroller()
    : architecture("Unknown"), frequencyMHz(0.0), portCount(0)
{
}


Microcontroller::Microcontroller(const std::string& arch, double freqMHz, int ports)
    : architecture(arch), frequencyMHz(freqMHz), portCount(ports)
{
}


Microcontroller::~Microcontroller()
{
    
}


std::string Microcontroller::getArchitecture() const
{
    return architecture;
}

double Microcontroller::getFrequencyMHz() const
{
    return frequencyMHz;
}

int Microcontroller::getPortCount() const
{
    return portCount;
}


void Microcontroller::setArchitecture(const std::string& arch)
{
    architecture = arch;
}

void Microcontroller::setFrequencyMHz(double freqMHz)
{
    frequencyMHz = freqMHz;
}

void Microcontroller::setPortCount(int ports)
{
    portCount = ports;
}


void Microcontroller::printInfo() const
{
    std::cout << "Мікроконтролер:\n";
    std::cout << "  Архітектура : " << architecture << "\n";
    std::cout << "  Частота     : " << frequencyMHz << " МГц\n";
    std::cout << "  Порти       : " << portCount << "\n";
}
