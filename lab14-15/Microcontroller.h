#ifndef MICROCONTROLLER_H
#define MICROCONTROLLER_H

#include <string>

class Microcontroller {
private:
    std::string architecture;
    double frequency;
    int ports;

public:
    Microcontroller();
    Microcontroller(std::string arch, double freq, int p);

    std::string getArchitecture() const;
    double getFrequency() const;
    int getPorts() const;

    void setArchitecture(const std::string& arch);
    void setFrequency(double freq);
    void setPorts(int p);

    bool operator==(const Microcontroller& other) const;
};

#endif
