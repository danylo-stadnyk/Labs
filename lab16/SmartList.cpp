#include "SmartList.h"

void SmartList::push_back(std::shared_ptr<Microcontroller> mc) {
    auto newNode = std::make_shared<Node>(mc);
    if (!head) {
        head = tail = newNode;
    } else {
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
}

void SmartList::display_forward() const {
    auto current = head;
    std::cout << "Прямий список: ";
    while (current) {
        current->data->display();
        if (current->next) std::cout << " -> ";
        current = current->next;
    }
    std::cout << std::endl;
}

void SmartList::display_backward() const {
    auto current = tail;
    std::cout << "Зворотний список: ";
    while (current) {
        current->data->display();
        if (auto p = current->prev.lock()) std::cout << " -> ";
        current = current->prev.lock();
    }
    std::cout << std::endl;
}
