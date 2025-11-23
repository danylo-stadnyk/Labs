#include "LinkedList.h"

LinkedList::LinkedList() : head(nullptr) {}

LinkedList::~LinkedList() {
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
    head = nullptr;
}

bool LinkedList::is_empty() const {
    return head == nullptr;
}

void LinkedList::push_front(const Microcontroller& mc) {
    Node* newNode = new Node(mc);
    newNode->next = head;
    head = newNode;
}

void LinkedList::push_back(const Microcontroller& mc) {
    Node* newNode = new Node(mc);
    if (is_empty()) {
        head = newNode;
        return;
    }
    Node* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }
    current->next = newNode;
}

bool LinkedList::insert_after(const Microcontroller& afterMC, const Microcontroller& newMC) {
    Node* current = head;
    while (current != nullptr) {
        if (current->data == afterMC) {
            Node* newNode = new Node(newMC);
            newNode->next = current->next;
            current->next = newNode;
            return true;
        }
        current = current->next;
    }
    return false;
}

bool LinkedList::pop_front() {
    if (is_empty()) return false;
    Node* temp = head;
    head = head->next;
    delete temp;
    return true;
}

bool LinkedList::pop_back() {
    if (is_empty()) return false;

    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return true;
    }

    Node* current = head;
    while (current->next->next != nullptr) {
        current = current->next;
    }

    delete current->next;
    current->next = nullptr;
    return true;
}

bool LinkedList::remove_value(const Microcontroller& mc) {
    if (is_empty()) return false;

    if (head->data == mc) {
        pop_front();
        return true;
    }

    Node* current = head;
    while (current->next != nullptr) {
        if (current->next->data == mc) {
            Node* temp = current->next;
            current->next = temp->next;
            delete temp;
            return true;
        }
        current = current->next;
    }
    return false;
}

void LinkedList::display() const {
    if (is_empty()) {
        std::cout << "Список порожній.\n";
        return;
    }

    Node* current = head;
    std::cout << "Список мікроконтролерів:\n";
    while (current != nullptr) {
        std::cout << "Архітектура: " << current->data.getArchitecture()
                  << ", Частота: " << current->data.getFrequency()
                  << " МГц, Порти: " << current->data.getPorts() << "\n";

        current = current->next;
    }
}
