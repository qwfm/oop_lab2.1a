#ifndef DBO_LAB1_PUBLISHER_H
#define DBO_LAB1_PUBLISHER_H

#include <string>
#include "Constants.h"


class Supplier
{
public:
    Supplier(int id,
        char* name,
        char* address,
        long firstProductAddress,
        bool state = STATE_ACTIVE);

    Supplier() = default;

    int getId() const;

    void setId(int newID);

    char* getName() const;

    void setName(char* newName);

    char* getLocation() const;

    void setLocation(char* newLocation);

    long getFirstProductAddress() const;

    void setFirstProductAddress(long newAddress);

    bool getState() const;

    void setState(bool newState);

    std::string toString();
private:
    int id = -1;
    char* name = new char[STRING_SIZE];
    char* location = new char[STRING_SIZE];
    long firstProductAddress = -1;
    bool isRemoved = STATE_ACTIVE;
};

#endif