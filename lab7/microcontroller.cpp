#include "microcontroller.h"
#include <algorithm>


bool MicrocontrollerManager::validArchitecture(const std::string &arch) const {
    return !arch.empty();
}
bool MicrocontrollerManager::validFrequency(int freq) const {
    return freq > 0; 
}
bool MicrocontrollerManager::validPorts(int ports) const {
    return ports >= 0; 
}


MicrocontrollerManager::MicrocontrollerManager() : next_id(1) {
    devices.clear();
}

MicrocontrollerManager::~MicrocontrollerManager() {
    
    devices.clear();
}


Microcontroller MicrocontrollerManager::createDevice(const std::string &name,
                                                     const std::string &architecture,
                                                     int frequency_mhz,
                                                     int ports_count) {
    Microcontroller mc;
    mc.id = next_id++;
    mc.name = name;
    mc.architecture = architecture;
    mc.frequency_mhz = (validFrequency(frequency_mhz) ? frequency_mhz : 0);
    mc.ports_count = (validPorts(ports_count) ? ports_count : 0);
    devices.push_back(mc);
    return mc;
}


bool MicrocontrollerManager::insertDeviceAt(size_t pos, const Microcontroller &mc) {
    if (pos > devices.size()) {
        devices.push_back(mc);
        return true;
    }
    devices.insert(devices.begin() + pos, mc);
    return true;
}


bool MicrocontrollerManager::removeById(int id) {
    auto it = std::find_if(devices.begin(), devices.end(), [id](const Microcontroller &m){ return m.id == id; });
    if (it == devices.end()) return false;
    devices.erase(it);
    return true;
}


bool MicrocontrollerManager::swapById(int id1, int id2) {
    if (id1 == id2) return true;
    auto it1 = std::find_if(devices.begin(), devices.end(), [id1](const Microcontroller &m){ return m.id == id1; });
    auto it2 = std::find_if(devices.begin(), devices.end(), [id2](const Microcontroller &m){ return m.id == id2; });
    if (it1 == devices.end() || it2 == devices.end()) return false;
    std::swap(*it1, *it2);
    return true;
}


void MicrocontrollerManager::clearAll() {
    devices.clear();
}


bool MicrocontrollerManager::updateDevice(int id,
                                          const std::string &name,
                                          const std::string &architecture,
                                          int frequency_mhz,
                                          int ports_count) {
    auto it = std::find_if(devices.begin(), devices.end(), [id](const Microcontroller &m){ return m.id == id; });
    if (it == devices.end()) return false;

    
    if (name.empty()) {
        std::cerr << "Помилка: ім'я не може бути порожнім.\n";
        return false;
    }
    if (!validArchitecture(architecture)) {
        std::cerr << "Помилка: архітектура некоректна.\n";
        return false;
    }
    if (!validFrequency(frequency_mhz)) {
        std::cerr << "Помилка: частота має бути > 0.\n";
        return false;
    }
    if (!validPorts(ports_count)) {
        std::cerr << "Помилка: кількість портів має бути >= 0.\n";
        return false;
    }

    it->name = name;
    it->architecture = architecture;
    it->frequency_mhz = frequency_mhz;
    it->ports_count = ports_count;
    return true;
}


void MicrocontrollerManager::printAll() const {
    if (devices.empty()) {
        std::cout << "Список пристроїв порожній.\n";
        return;
    }
    std::cout << "ID\tName\tArchitecture\tFreq(MHz)\tPorts\n";
    std::cout << "----------------------------------------------------------\n";
    for (const auto &d : devices) {
        std::cout << d.id << '\t'
                  << d.name << '\t'
                  << d.architecture << '\t'
                  << d.frequency_mhz << '\t'
                  << d.ports_count << '\n';
    }
}


const Microcontroller* MicrocontrollerManager::findById(int id) const {
    auto it = std::find_if(devices.begin(), devices.end(), [id](const Microcontroller &m){ return m.id == id; });
    if (it == devices.end()) return nullptr;
    return &(*it);
}
