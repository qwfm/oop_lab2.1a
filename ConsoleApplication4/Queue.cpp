#include "Queue.h"

bool Queue::isEmpty() const {
    return this->head == nullptr;
}

void Queue::push(long address) {
    if (address < 0) {
        //std::cerr << "Address is out of range.\n";
        return;
    }

    QueueNode* newNode = new QueueNode;
    newNode->address = address;
    if (this->isEmpty()) {
        head = tail = newNode;
    }
    tail->next = newNode;
    tail = newNode;
}

long Queue::removeAddress(long address) {
    if (isEmpty()) {
        return -1;
    }

    QueueNode* current = head;
    QueueNode* prev = nullptr;

    while (current->address != address) {
        prev = current;
        current = current->next;
    }

    if (prev == nullptr) {
        head = nullptr;
    }
    else {
        prev->next = current->next;
    }

    if (current == tail) {
        tail = prev;
    }

    long removedAddress = current->address;

    current = nullptr;

    return removedAddress;
}


long Queue::pop() {
    if (isEmpty()) {
        return -1;
    }
    QueueNode* temp = this->head;
    long address = temp->address;

    this->head = this->head->next;
    if (this->head == tail) {
        this->tail = nullptr;
        this->head = nullptr;
    } else
        delete temp;
    return address;
}