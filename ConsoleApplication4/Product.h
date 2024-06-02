#ifndef DBO_LAB1_BOOK_H
#define DBO_LAB1_BOOK_H

#include <iostream>
#include <string>
#include "Constants.h"

/*!
    \brief Class of a product
*/
class Product
{
public:
    /*!
    \brief Standart constructor of a product
    \param id - product's id
    \param supplierId - product's supplierID
    \param brand - product's brand
    \param model - product's model
    \param price - product's price
    \param prevProductAddress - adress in memory of previously added product
    \param nextProductAddress - adress in memory of product added afterwords
    \param state - state of product (is product deleted or not)
    */
    Product(int id,
        int supplierId,
        char* brand,
        char* model,
        char* price,
        long prevProductAddress,
        long nextProductAddress,
        bool state = STATE_ACTIVE);

    Product() = default;
    /*!
    \brief Method returns some product's id
    */
    int getId() const;
    /*!
    \brief Method sets product's id
    \param newID - product's intended ID, chosen by user
    */
    void setId(int newId);
    /*!
    \brief Method returns product's supplierID
    */
    int getSupplierId() const;
    /*!
    \brief Method sets product's supplierID
    \param newID - product's intended supplierID, chosen by user
    */
    void setSupplierId(int newSupplierId);
    /*!
    \brief Method returns some product's brand
    */
    char* getBrand() const;
    /*!
    \brief Method sets product's brand
    \param newBrand - product's intended brand
    */
    void setBrand(char* newBrand);
    /*!
    \brief Method returns some product's model
    */
    char* getModel() const;
    /*!
    \brief Method sets product's model
    \param newModel - product's intended model
    */
    void setModel(char* newModel);
    /*!
    \brief Method returns some product's price
    */
    char* getPrice() const;
    /*!
    \brief Method sets product's price
    \param newPrice - product's intended price
    */
    void setPrice(char* newPrice);
    /*!
    \brief Method returns adress in memory of previously added product
    */
    long getPrevProductAddress() const;
    /*!
    \brief Method returns adress in memory of previously added product
    */
    void setPrevProductAddress(long newAddress);
    /*!
    \brief Method returns adress in memory of product added afterwords  
    */
    long getNextProductAddress() const;
    /*!
    \brief Method sets adress in memory of product added afterwords
    */
    void setNextProductAddress(long newAddress);
    /*!
    \brief Method returns state of product
    */
    bool getState() const;
    /*!
    \brief Method sets state of product
    */
    void setState(bool newState);
    /*!
    \brief Turns something to string
    */
    std::string toString() const;

private:
    int id = -1; /*! \brief products's ID */
    int supplierId = -1; /*! \brief product's supplierID */
    char* brand = new char[STRING_SIZE];  /*! \brief product's brand */
    char* model = new char[STRING_SIZE];  /*! \brief product's model */
    char* price = new char[STRING_SIZE];  /*! \brief product's price */
    long prevProductAddress = -1; /*! \brief adress in memory of previously added product */
    long nextProductAddress = -1; /*! \brief adress in memory of product added afterwords */
    bool isRemoved = STATE_ACTIVE;  /*! \brief product's state */
};

#endif 