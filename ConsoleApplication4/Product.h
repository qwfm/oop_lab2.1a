#ifndef DBO_LAB1_BOOK_H
#define DBO_LAB1_BOOK_H

#include <iostream>
#include <string>
#include "Constants.h"

class Product
{
public:
    Product(int id,
        int supplierId,
        char* brand,
        char* model,
        char* price,
        long prevProductAddress,
        long nextProductAddress,
        bool state = STATE_ACTIVE);

    Product() = default;

    int getId() const;

    void setId(int newId);

    int getSupplierId() const;

    void setSupplierId(int newSupplierId);

    char* getBrand() const;

    void setBrand(char* newBrand);

    char* getModel() const;

    void setModel(char* newModel);

    char* getPrice() const;

    void setPrice(char* newPrice);

    long getPrevProductAddress() const;

    void setPrevProductAddress(long newAddress);

    long getNextProductAddress() const;

    void setNextProductAddress(long newAddress);

    bool getState() const;

    void setState(bool newState);

    std::string toString() const;

private:
    int id = -1;
    int supplierId = -1;
    char* brand = new char[STRING_SIZE]; 
    char* model = new char[STRING_SIZE];
    char* price = new char[STRING_SIZE];
    long prevProductAddress = -1;
    long nextProductAddress = -1;
    bool isRemoved = STATE_ACTIVE;
};

#endif 