#ifndef DBO_LAB1_FUNCTIONS_H
#define DBO_LAB1_FUNCTIONS_H

#include "Utilities.h"
#include "Supplier.h"
#include "Product.h"
#include "ListNode.h"
#include "Queue.h"
#include "Menu.h"

long getSupplierAddress(int id);

Supplier getSupplier(int id);

void getAllSuppliers();

void countSuppliers();

long getProductAddress(int id);

Product getProduct(int id);

void getAllProducts();

void countProducts();

int countProductsOfSupplier(int id);

bool removeSupplier(int id);

bool removeProduct(int id);

bool insertSupplier(const Supplier& newSupplier);

bool insertProduct(Product& newProduct);

bool updateSupplier(int id, const Supplier& newSupplier);

bool updateProduct(int id, const Product& newProduct);

bool checkSupplierId(int id);

bool checkProductId(int id);

void loadIndex(char* filePath, ListNode** head);

void loadGarbage(char* filePath, Queue** garbage);

bool checkSupplierGarbageId(int id);

bool checkProductGarbageId(int id);

void prepareFiles(char* suppliersPath,
    char* productsPath,
    char* suppliersIndexPath,
    char* productsIndexPath,
    char* suppliersGarbagePath,
    char* productsGarbagePath);

void close(char* suppliersIndexPath, char* productsIndexPath, char* suppliersGarbagePath, char* productsGarbagePath);
#endif