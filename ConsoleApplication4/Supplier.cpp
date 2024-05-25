#include "Supplier.h"

Supplier::Supplier(int id,
    char* name,
    char* location,
    long firstProductAddress,
    bool isRemoved) {
    this->id = id;
    this->name = name;
    this->location = location;
    this->firstProductAddress = firstProductAddress;
    this->isRemoved = isRemoved;
}

int Supplier::getId() const {
    return this->id;
}

void Supplier::setId(int newId) {
    this->id = newId;
}

char* Supplier::getName() const {
    return this->name;
}

void Supplier::setName(char* newName) {
    this->name = newName;
}

char* Supplier::getLocation() const {
    return this->location;
}

void Supplier::setLocation(char* newLocation) {
    this->location = newLocation;
}

long Supplier::getFirstProductAddress() const {
    return this->firstProductAddress;
}

void Supplier::setFirstProductAddress(long newAddress) {
    this->firstProductAddress = newAddress;
}

bool Supplier::getState() const {
    return this->isRemoved;
}

void Supplier::setState(bool newState) {
    this->isRemoved = newState;
}

std::string Supplier::toString() {
    return "ID: " + std::to_string(this->id) +
        "; Name: " + this->name +
        "; Location: " + this->location +
        "; First product address: " + std::to_string(this->firstProductAddress) +
        "; State:" + std::to_string(this->isRemoved);
}