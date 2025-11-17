#ifndef COMPONENT_COLLECTION_H
#define COMPONENT_COLLECTION_H


#include <vector>
#include <memory>
#include "OpticalComponent.h"
#include "Exceptions.h"



class ComponentCollection {
std::vector<std::unique_ptr<OpticalComponent>> items;
public:
ComponentCollection() = default;
~ComponentCollection() = default;


void add(std::unique_ptr<OpticalComponent> &&comp) {
items.push_back(std::move(comp));
}


size_t size() const { return items.size(); }



OpticalComponent& operator[](size_t idx) {
if (idx >= items.size()) throw InputException("Index out of range in ComponentCollection");
return *items[idx];
}


const OpticalComponent& operator[](size_t idx) const {
if (idx >= items.size()) throw InputException("Index out of range in ComponentCollection (const)");
return *items[idx];
}
};


#endif