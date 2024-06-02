#ifndef DBO_LAB1_PUBLISHER_H
#define DBO_LAB1_PUBLISHER_H

#include <string>
#include "Constants.h"

/*!
    \brief Class of a supplier
*/
class Supplier
{
public:
    /*!
    \brief Standart constructor of a supplier
    \param id - supplier's id 
    \param name - supplier's name
    \param address - supplier's adress 
    \param firstProductAddress - adress in memory of suplier's first added product
    \param state - state of supplier (is supplier deleted or not)
    */
    Supplier(int id,
        char* name,
        char* address,
        long firstProductAddress,
        bool state = STATE_ACTIVE);
    
    Supplier() = default;
    /*!
    \brief Method returns some supplier's id
    */
    int getId() const;
    /*!
    \brief Method sets supplier's id
    \param newID - supplier's intended ID, chosen by user
    */
    void setId(int newID);
    /*!
    \brief Method returns some supplier's name
    */
    char* getName() const;
    /*!
    \brief Method sets supplier's name
    \param newName - supplier's intended name
    */
    void setName(char* newName);
    /*!
    \brief Method returns some supplier's adress 
    */
    char* getLocation() const;
    /*!
    \brief Method sets supplier's adress 
    \param newLocation - supplier's intended location
    */
    void setLocation(char* newLocation);
    /*!
    \brief Method returns adress in memory of some suplier's first added product
    */
    long getFirstProductAddress() const;
    /*!
    \brief Method sets adress in memory of suplier's first added product
    */
    void setFirstProductAddress(long newAddress);
    /*!
    \brief Method returns state of some suplier (whether he's deleted(true) or not(false))
    */
    bool getState() const;
    /*!
    \brief Method sets state of suplier 
    */
    void setState(bool newState);
    /*!
    \brief Turns something to string 
    */
    std::string toString();
private:
    int id = -1; /*! \brief supplier's ID */
    char* name = new char[STRING_SIZE]; /*! \brief supplier's name */
    char* location = new char[STRING_SIZE]; /*! \brief supplier's location */
    long firstProductAddress = -1; /*! \brief supplier's memory address */
    bool isRemoved = STATE_ACTIVE; /*! \brief supplier's state */
};

#endif