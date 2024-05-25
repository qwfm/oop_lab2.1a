#include <iostream>
#include "Menu.h"
#include "Functions.h"

int main() {
    char suppliersFileName[] = "Suppliers.bin";
    char productsFileName[] = "Products.bin";
    char suppliersIndexFileName[] = "SuppliersIndex.bin";
    char productsIndexFileName[] = "ProductsIndex.bin";
    char suppliersGarbageFileName[] = "SuppliersGarbage.bin";
    char productsGarbageFileName[] = "productsGarbage.bin";

    prepareFiles(suppliersFileName,
        productsFileName,
        suppliersIndexFileName,
        productsIndexFileName,
        suppliersGarbageFileName,
        productsGarbageFileName);

    start();
    close(suppliersIndexFileName,
        productsIndexFileName,
        suppliersGarbageFileName,
        productsGarbageFileName);

    return 0;
}