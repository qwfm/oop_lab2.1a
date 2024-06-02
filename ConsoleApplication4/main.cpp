#include <iostream>
#include "Menu.h"
#include "Functions.h"

/**
* \mainpage Documentation
* This is documentation of a laboratory work about an internet shop DBSM, which lets user locally add/delete/show/change suppliers and products of said shop.
* 
* The documentation is created for a purpose of completing lab 1 in second semester.
*
* To see UML diagrams, go to \ref UML "UML diagrams" page here.
*/

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