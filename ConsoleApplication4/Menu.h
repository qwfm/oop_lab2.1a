#ifndef DBO_LAB1_MENU_H
#define DBO_LAB1_MENU_H

#include <iostream>
#include "Constants.h"
#include "Supplier.h"
#include "Product.h"
#include "Functions.h"

int readInt(const char* text);

char* readString(const char* text);

void addSupplierMenu();

void getSupplierMenu();

void removeSupplierMenu();

void updateSupplierName(Supplier& supplier);

void updateSupplierLocation(Supplier& supplier);

void updateSupplierFields(Supplier& supplier);

void updateSupplierMenu();

void addProductMenu();

void getProductMenu();

void removeProductMenu();

void updateProductBrand(Product& product);

void updateProductModel(Product& product);

void updateProductPrice(Product& product);

void updateProductFields(Product& product);

void updateProductMenu();

void countProductsOfSupplierMenu();

void start();

#endif