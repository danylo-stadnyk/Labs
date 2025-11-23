#ifndef NODE_H
#define NODE_H

#include "Microcontroller.h"

struct Node {
    Microcontroller data;
    Node* next;

    Node(const Microcontroller& mc) : data(mc), next(nullptr) {}
};

#endif
