#ifndef DBO_LAB1_UTILITIES_H
#define DBO_LAB1_UTILITIES_H

#include "Product.h"
#include "Supplier.h"

void writeProduct(FILE* file, const Product& product);

void writeProduct(FILE* file, const Product& product, long address);

Product readProduct(FILE* file);

Product readProduct(FILE* file, long address);

void writeSupplier(FILE* file, const Supplier& publisher);

void writeSupplier(FILE* file, Supplier publisher, long address);

Supplier readSupplier(FILE* file);

Supplier readSupplier(FILE* file, long address);

bool isFileEmpty(FILE* file);
#endif