#include "Product.h"

Product::Product(int id,
    int supplierId,
    char* brand,
    char* model,
    char* price,
    long prevProductAddress,
    long nextProductAddress,
    bool isRemoved) {
    this->id = id;
    this->supplierId = supplierId;
    this->brand = brand;
    this->model = model;
    this->price = price;
    this->prevProductAddress = prevProductAddress;
    this->nextProductAddress = nextProductAddress;
    this->isRemoved = isRemoved;
}
int Product::getId() const {
    return this->id;
}

void Product::setId(int newId) {
    this->id = newId;
}

int Product::getSupplierId() const {
    return this->supplierId;
}

void Product::setSupplierId(int newSupplierId) {
    this->supplierId = newSupplierId;
}

char* Product::getBrand() const {
    return this->brand;
}

void Product::setBrand(char* newBrand) {
    this->brand = newBrand;
}

char* Product::getModel() const {
    return this->model;
}

void Product::setModel(char* newModel) {
    this->model = newModel;
}

char* Product::getPrice() const {
    return this->price;
}

void Product::setPrice(char* newPrice) {
    this->price = newPrice;
}

long Product::getPrevProductAddress() const {
    return this->prevProductAddress;
}

void Product::setPrevProductAddress(long newAddress) {
    this->prevProductAddress = newAddress;
}

long Product::getNextProductAddress() const {
    return this->nextProductAddress;
}

void Product::setNextProductAddress(long newAddress) {
    this->nextProductAddress = newAddress;
}

bool Product::getState() const {
    return this->isRemoved;
}

void Product::setState(bool newState) {
    this->isRemoved = newState;
}

std::string Product::toString() const {
    return "ID: " + std::to_string(this->id) +
        "; Supplier ID: " + std::to_string(this->supplierId) +
        "; Brand: " + this->brand +
        "; Model: " + this->model +
        "; Price: " + this->price +
        "; Previous product address " + std::to_string(this->prevProductAddress) +
        "; Next product address " + std::to_string(this->nextProductAddress) +
        "; State: " + std::to_string(this->isRemoved) + '\n';
}
