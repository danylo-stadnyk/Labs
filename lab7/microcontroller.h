#ifndef MICROCONTROLLER_H
#define MICROCONTROLLER_H

#include <string>
#include <vector>
#include <iostream>

struct Microcontroller {
    int id;
    std::string name;
    std::string architecture; 
    int frequency_mhz;        
    int ports_count;          

    Microcontroller() : id(0), name(""), architecture(""), frequency_mhz(0), ports_count(0) {}
};

class MicrocontrollerManager {
private:
    std::vector<Microcontroller> devices;
    int next_id;

    bool validArchitecture(const std::string &arch) const;
    bool validFrequency(int freq) const;
    bool validPorts(int ports) const;
public:
    MicrocontrollerManager();
    ~MicrocontrollerManager();

    
    Microcontroller createDevice(const std::string &name,
                                 const std::string &architecture,
                                 int frequency_mhz,
                                 int ports_count); 

    bool insertDeviceAt(size_t pos, const Microcontroller &mc); 
    bool removeById(int id); 
    bool swapById(int id1, int id2); 
    void clearAll();

    
    bool updateDevice(int id,
                      const std::string &name,
                      const std::string &architecture,
                      int frequency_mhz,
                      int ports_count);

    
    void printAll() const;
    const Microcontroller* findById(int id) const;
};

#endif 
