#ifndef MICROCONTROLLER_H
#define MICROCONTROLLER_H

#include <string>

class Microcontroller {
private:
    std::string architecture;
    double frequency; // в MHz
    int ports;

public:
    
    Microcontroller();

    
    Microcontroller(const std::string& arch, double freq, int portCount);

    
    ~Microcontroller();

    
    void displayInfo() const;

   
    void setArchitecture(const std::string& arch);
    void setFrequency(double freq);
    void setPorts(int portCount);
};


void overclockMicrocontroller(Microcontroller& mcu, double newFreq);

#endif
