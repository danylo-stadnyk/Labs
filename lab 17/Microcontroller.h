#ifndef MICROCONTROLLER_H
#define MICROCONTROLLER_H

#include <string>
#include <iostream>


class Microcontroller
{
private:
    std::string architecture; 
    double frequencyMHz;      
    int portCount;            

public:
    
    Microcontroller();

  
    Microcontroller(const std::string& arch, double freqMHz, int ports);

  
    ~Microcontroller();

   
    std::string getArchitecture() const;
    double getFrequencyMHz() const;
    int getPortCount() const;

    
    void setArchitecture(const std::string& arch);
    void setFrequencyMHz(double freqMHz);
    void setPortCount(int ports);

    
    void printInfo() const;
};

#endif 
