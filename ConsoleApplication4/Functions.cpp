#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include "Functions.h"

FILE* suppliersF;
FILE* productsF;

ListNode* suppliersIndex = new ListNode;
ListNode* suppliersGarbageIndex = new ListNode;
Queue* suppliersGarbage = new Queue;

ListNode* productsIndex = new ListNode;
ListNode* productsGarbageIndex = new ListNode;
Queue* productsGarbage = new Queue;

long getSupplierAddress(int id) {
    return getAddress(id, suppliersIndex);
}

Supplier getSupplier(int id) {
    long address = getSupplierAddress(id);
    if (address == -1) {
        return Supplier();
    }
    return readSupplier(suppliersF, address);
}

void getAllSuppliers() {
    if (suppliersIndex->id == -1) {
        std::cout << "No suppliers.\n";
        return;
    }

    ListNode* temp = suppliersIndex;
    while (temp) {
        int id = temp->id;
        Supplier supplier = getSupplier(id);
        std::cout << supplier.toString() << '\n';
        temp = temp->next;
    }
}

void countSuppliers() {
    std::cout << "Total suppliers: " << getSize(suppliersIndex) << '\n';
}

long getProductAddress(int id) {
    return getAddress(id, productsIndex);
}

Product getProduct(int id) {
    long address = getProductAddress(id);
    if (address == -1) {
        std::cerr << "No product with such ID.\n";
        return Product();
    }
    return readProduct(productsF, address);
}

void getAllProducts() {
    if (productsIndex->id == -1) {
        std::cout << "No products.\n";
        return;
    }

    ListNode* temp = productsIndex;
    while (temp) {
        int id = temp->id;
        Product product = getProduct(id);
        std::cout << product.toString() << '\n';
        temp = temp->next;
    }
}

void countProducts() {
    std::cout << "Total products: " << getSize(productsIndex) << '\n';
    ListNode* temp = suppliersIndex;
    while (temp) {
        std::cout << std::to_string(temp->id) + "'s supplier has: ";
        std::cout << std::to_string(countProductsOfSupplier(temp->id)) + " products\n";
        temp = temp->next;
    }
}

int countProductsOfSupplier(int id) {
    Supplier supplier = getSupplier(id);
    long address = supplier.getFirstProductAddress();

    int count = 0;
    while (address != -1) {
        Product product = readProduct(productsF, address);
        ++count;
        address = product.getNextProductAddress();
    }
    return count;
}

bool removeSupplier(int id) {
    Supplier supplier = getSupplier(id);
    if (supplier.getId() == -1) {
        return false;
    }
    supplier.setState(STATE_REMOVED);

    long address = getSupplierAddress(id);
    writeSupplier(suppliersF, supplier, address);

    suppliersGarbage->push(address);
    addListNode(id, address, &suppliersGarbageIndex);
    //deleteListNode(id, &suppliersIndex);

    // deleting all sub records
    long productAddress = supplier.getFirstProductAddress();

    while (productAddress != -1) {
        Product product = readProduct(productsF, productAddress);
        product.setState(STATE_REMOVED);
        writeProduct(productsF, product, productAddress);
        productsGarbage->push(productAddress);
        deleteListNode(product.getId(), &productsIndex);
        productAddress = product.getNextProductAddress();
    }
    return true;
}

bool insertSupplier(const Supplier& newSupplier) {
    int id = newSupplier.getId();
    Supplier supplier = getSupplier(id);
    Queue* asf = suppliersGarbage;
    long address;
    if (!checkSupplierGarbageId(id)) {
        address = getSupplierAddress(id);
        deleteListNode(id, &suppliersGarbageIndex);
        deleteListNode(id, &suppliersIndex);
        suppliersGarbage->removeAddress(address);
    }
    else
        if (checkSupplierGarbageId(id) && suppliersGarbageIndex->id != -1) {
            address = getSupplierAddress(suppliersGarbageIndex->id);
            deleteListNode(suppliersGarbageIndex->id, &suppliersIndex);
            deleteListNode(suppliersGarbageIndex->id, &suppliersGarbageIndex);
            suppliersGarbage->removeAddress(address);
        }
        else address = -1;

    if (address == -1) {
        fseek(suppliersF, 0, SEEK_END);
        address = ftell(suppliersF);
    }
    addListNode(id, address, &suppliersIndex);
    ListNode* asfq = suppliersIndex;
    sortList(&suppliersIndex);
     asfq = suppliersIndex;
    writeSupplier(suppliersF, newSupplier, address);
    return true;
}

bool removeProduct(int id) {
    Product product = getProduct(id);
    if (product.getId() == -1) {
        return false;
    }
    product.setState(STATE_REMOVED);

    long prevProductAddress = product.getPrevProductAddress();
    long nextProductAddress = product.getNextProductAddress();

    if (prevProductAddress != -1) {
       // changing relations between products
        Product prevProduct = readProduct(productsF, prevProductAddress);
        prevProduct.setNextProductAddress(nextProductAddress);
        writeProduct(productsF, prevProduct, prevProductAddress);

        if (nextProductAddress != -1) {
            Product nextProduct = readProduct(productsF, nextProductAddress);
            nextProduct.setPrevProductAddress(prevProductAddress);
            writeProduct(productsF, nextProduct, nextProductAddress);
        }
    }
    else {
        // setting supplier first product to the next one
        int supplierId = product.getSupplierId();
        Supplier supplier = getSupplier(supplierId);
        supplier.setFirstProductAddress(nextProductAddress);
        updateSupplier(supplierId, supplier);
    }

    long address = getProductAddress(id);
    if (address == -1) {
        return false;
    }

    writeProduct(productsF, product, address);
    productsGarbage->push(address);
    deleteListNode(id, &productsIndex);
    return true;
}

bool insertProduct(Product& newProduct) {
    int supplierId = newProduct.getSupplierId();

    long address = productsGarbage->pop();
    if (address == -1) {
        fseek(productsF, 0, SEEK_END);
        address = ftell(productsF);
    }

    Supplier supplier = getSupplier(supplierId);
    long productAddress = supplier.getFirstProductAddress();

    if (productAddress == -1) {
        supplier.setFirstProductAddress(address);

        long supplierAddress = getSupplierAddress(supplierId);
        writeSupplier(suppliersF, supplier, supplierAddress);
    }
    else {
        Product product = readProduct(productsF, productAddress);
        while (product.getNextProductAddress() != -1) {
            productAddress = product.getNextProductAddress();
            product = readProduct(productsF, productAddress);
        }
        product.setNextProductAddress(address);
        newProduct.setPrevProductAddress(productAddress);

        writeProduct(productsF, product, productAddress);
    }

    addListNode(newProduct.getId(), address, &productsIndex);
    sortList(&productsIndex);

    writeProduct(productsF, newProduct, address);
    return true;
}

bool updateSupplier(int id, const Supplier& newSupplier) {
    long address = getSupplierAddress(id);
    if (address == -1) {
        //std::cerr << "No supplier with such ID\n";
        return false;
    }
    writeSupplier(suppliersF, newSupplier, address);
    return true;
}

bool updateProduct(int id, const Product& newProduct) {
    long address = getProductAddress(id);
    if (address == 1) {
        std::cerr << "No product with such ID\n";
        return false;
    }
    writeProduct(productsF, newProduct, address);
    return true;
}

bool checkSupplierId(int id) {
    return isIdFree(id, suppliersIndex);
}

bool checkSupplierGarbageId(int id) {
    return isIdFree(id, suppliersGarbageIndex);
}

bool checkProductId(int id) {
    return isIdFree(id, productsIndex);
}

bool checkProductGarbageId(int id) {
    return isIdFree(id, productsGarbageIndex);
}

void loadIndex(char* filePath, ListNode** head) {
    FILE* file = fopen(filePath, "rb+");
    if (!file) {
        file = fopen(filePath, "wb+");
    }

    if (!isFileEmpty(file)) {
        int id;
        long address;

        do {
            fread(&id, INT_SIZE, 1, file);
            fread(&address, LONG_SIZE, 1, file);
            addListNode(id, address, head);
        } while (!feof(file));
    }
    sortList(head);
    fclose(file);
}

void writeIndex(char* filePath, ListNode* head) {
    FILE* file = fopen(filePath, "wb+");

    ListNode* temp = head;
    if (temp->id == -1) {
        return;
    }

    while (temp) {
        fwrite(&temp->id, INT_SIZE, 1, file);
        fwrite(&temp->address, LONG_SIZE, 1, file);
        temp = temp->next;
    }
    fclose(file);
}

void loadGarbage(char* filePath, Queue** garbage) {
    FILE* file = fopen(filePath, "rb+");
    if (!file) {
        file = fopen(filePath, "wb+");
    }

    if (!isFileEmpty(file)) {
        long address;
        do {
            fread(&address, LONG_SIZE, 1, file);
            (*garbage)->push(address);
        } while (!feof(file));
    }
    fclose(file);
}

void writeGarbage(char* filePath, Queue* garbage) {
    FILE* file = fopen(filePath, "wb+");

    while (!garbage->isEmpty()) {
        long address = garbage->pop();
        fwrite(&address, LONG_SIZE, 1, file);
    }
    fclose(file);
}

void prepareFiles(char* suppliersPath, char* productsPath, char* suppliersIndexPath, char* productsIndexPath, char* suppliersGarbagePath, char* productsGarbagePath) {
    suppliersF = fopen(suppliersPath, "rb+");
    if (!suppliersF) {
        suppliersF = fopen(suppliersPath, "wb+");
    }

    productsF = fopen(productsPath, "rb+");
    if (!productsF) {
        productsF = fopen(productsPath, "wb+");
    }

    // loading indexes
    loadIndex(suppliersIndexPath, &suppliersIndex);
    loadIndex(productsIndexPath, &productsIndex);

    // loading garbage
    loadGarbage(suppliersGarbagePath, &suppliersGarbage);
    loadGarbage(productsGarbagePath, &productsGarbage);
}

void close(char* suppliersIndexPath, char* productsIndexPath, char* suppliersGarbagePath, char* productsGarbagePath) {
    fclose(suppliersF);
    writeIndex(suppliersIndexPath, suppliersIndex);
    writeGarbage(suppliersGarbagePath, suppliersGarbage);

    fclose(productsF);
    writeIndex(productsIndexPath, productsIndex);
    writeGarbage(productsGarbagePath, productsGarbage);
}