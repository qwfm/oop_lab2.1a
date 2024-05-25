#include "Utilities.h"

void writeProduct(FILE* file, const Product& product) {

    int id = product.getId();
    int supplierId = product.getSupplierId();
    char* brand = product.getBrand();
    char* model = product.getModel();
    char* price = product.getPrice();
    long prevProductAddress = product.getPrevProductAddress();
    long nextProductAddress = product.getNextProductAddress();
    bool state = product.getState();

    fwrite(&id, INT_SIZE, 1, file);
    fwrite(&supplierId, INT_SIZE, 1, file);
    fwrite(brand, CHAR_SIZE, STRING_SIZE, file);
    fwrite(model, CHAR_SIZE, STRING_SIZE, file);
    fwrite(price, CHAR_SIZE, STRING_SIZE, file);
    fwrite(&prevProductAddress, LONG_SIZE, 1, file);
    fwrite(&nextProductAddress, LONG_SIZE, 1, file);
    fwrite(&state, BOOL_SIZE, 1, file);
}

void writeProduct(FILE* file, const Product& product, long address) {
    fseek(file, address, SEEK_SET);
    writeProduct(file, product);
}

Product readProduct(FILE* file) {
    int id;
    int supplierId;
    char* brand = new char[STRING_SIZE];
    char* model = new char[STRING_SIZE];
    char* price = new char[STRING_SIZE];
    long prevProductAddress;
    long nextProductAddress;
    bool state;


    fread(&id, INT_SIZE, 1, file);
    fread(&supplierId, INT_SIZE, 1, file);
    fread(brand, CHAR_SIZE, STRING_SIZE, file);
    fread(model, CHAR_SIZE, STRING_SIZE, file);
    fread(price, CHAR_SIZE, STRING_SIZE, file);
    fread(&prevProductAddress, LONG_SIZE, 1, file);
    fread(&nextProductAddress, LONG_SIZE, 1, file);
    fread(&state, BOOL_SIZE, 1, file);

    return { id, supplierId, brand, model, price, prevProductAddress, nextProductAddress };
}

Product readProduct(FILE* file, long address) {
    fseek(file, address, SEEK_SET);
    return readProduct(file);
}

void writeSupplier(FILE* file, const Supplier& supplier) {
    int id = supplier.getId();
    char* name = supplier.getName();
    char* location = supplier.getLocation();
    long firstProductAddress = supplier.getFirstProductAddress();
    bool state = supplier.getState();

    fwrite(&id, INT_SIZE, 1, file);
    fwrite(name, CHAR_SIZE, STRING_SIZE, file);
    fwrite(location, CHAR_SIZE, STRING_SIZE, file);
    fwrite(&firstProductAddress, LONG_SIZE, 1, file);
    fwrite(&state, BOOL_SIZE, 1, file);

}

void writeSupplier(FILE* file, Supplier supplier, long address) {
    fseek(file, address, SEEK_SET);
    writeSupplier(file, supplier);
}

Supplier readSupplier(FILE* file) {
    int id;
    char* name = new char[STRING_SIZE];
    char* location = new char[STRING_SIZE];
    long firstProductAddress;
    bool state;

    fread(&id, INT_SIZE, 1, file);
    fread(name, CHAR_SIZE, STRING_SIZE, file);
    fread(location, CHAR_SIZE, STRING_SIZE, file);
    fread(&firstProductAddress, LONG_SIZE, 1, file);
    fread(&state, BOOL_SIZE, 1, file);

    return { id, name, location, firstProductAddress, state };
}

Supplier readSupplier(FILE* file, long address) {
    fseek(file, address, SEEK_SET);
    return readSupplier(file);
}

bool isFileEmpty(FILE* file) {
    fseek(file, 0, SEEK_END);
    long address = ftell(file);
    fseek(file, 0, SEEK_SET);
    return address == 0;
}