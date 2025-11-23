#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"
#include <iostream>

class LinkedList {
private:
    Node* head;

public:
    LinkedList();
    ~LinkedList();

    bool is_empty() const;

    void push_front(const Microcontroller& mc);
    void push_back(const Microcontroller& mc);
    bool insert_after(const Microcontroller& afterMC, const Microcontroller& newMC);

    bool pop_front();
    bool pop_back();
    bool remove_value(const Microcontroller& mc);

    void display() const;
};

#endif
