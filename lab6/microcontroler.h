#ifndef MICROCONTROLER_H
#define MICROCONTROLER_H

#include <iostream>
#include <string>
#include <array>

#define SIZE 5  


struct Microcontroler_s_t {
    std::string architecture; 
    double frequency;         
    int ports;                
};


class Microcontroler {
private:
    std::array<Microcontroler_s_t, SIZE> microcontrolers;
    int count; 

public:
    Microcontroler();  
    ~Microcontroler(); 

    void inputData();   
    void outputData() const;  
    bool isValid(const Microcontroler_s_t &mc) const; 
};

#endif
