#pragma once
#include "Microcontroller.h"
#include <memory>
#include <iostream>

class SmartList {
private:
    struct Node {
        std::shared_ptr<Microcontroller> data;
        std::shared_ptr<Node> next;
        std::weak_ptr<Node> prev;
        Node(std::shared_ptr<Microcontroller> mc) : data(mc), next(nullptr) {}
    };

    std::shared_ptr<Node> head;
    std::shared_ptr<Node> tail;

public:
    SmartList() : head(nullptr), tail(nullptr) {}
    void push_back(std::shared_ptr<Microcontroller> mc);
    void display_forward() const;
    void display_backward() const;
};
