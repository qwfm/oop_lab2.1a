#include "Menu.h"

const char* MAIN_MENU_OPTIONS_TEXT = "0 - Exit\n"
"1 - insert-m\n"
"2 - get-m\n"
"3 - del-m\n"
"4 - update-m\n"
"5 - insert-s\n"
"6 - get-s\n"
"7 - del-s\n"
"8 - update-s\n"
"9 - calc-m\n"
"10 - calc-s\n"
"11 - ut-m\n"
"12 - ut-s\n";

const char* MAIN_MENU_WRONG_INPUT = "Enter value between 0 and 4\n";

const char* SUPPLIER_ID_REQUEST_TEXT = "Enter supplierID (only positive integers).\n";
const char* SUPPLIER_NAME_REQUEST_TEXT = "Enter supplier name.\n";
const char* SUPPLIER_LOCATION_REQUEST_TEXT = "Enter supplier location.\n";

const char* SUPPLIER_INSERTED_TEXT = "Supplier has been successfully inserted.\n";
const char* SUPPLIER_REMOVED_TEXT = "Supplier has been successfully removed.\n";

const char* SUPPLIER_SELECT_FIELD_TO_UPDATE = "0 - Stop updating\n1 - Name\n2 - Location\n";
const char* SUPPLIER_UPDATED_TEXT = "Supplier has been successfully updated.\n";

const char* SUPPLIER_INVALID_ID_TEXT = "No supplier with such ID.\n";
const char* SUPPLIER_ID_IS_TAKEN_TEXT = "This ID is already taken.\n";
const char* SUPPLIER_NOT_REMOVED_TEXT = "Error while removing the supplier.\n";
const char* SUPPLIER_NOT_UPDATED_TEXT = "Error while updating the supplier.\n";

const char* PRODUCT_ID_REQUEST_TEXT = "Enter product ID.\n";
const char* PRODUCT_SUPPLIER_ID_REQUEST_TEXT = "Enter product's supplier ID.\n";
const char* PRODUCT_BRAND_REQUEST_TEXT = "Enter product brand.\n";
const char* PRODUCT_MODEL_REQUEST_TEXT = "Enter product model.\n";
const char* PRODUCT_PRICE_REQUEST_TEXT = "Enter product price.\n";

const char* PRODUCT_INVALID_ID_TEXT = "No product with such ID\n";
const char* PRODUCT_ID_IS_TAKEN_TEXT = "This ID is already taken.\n";
const char* PRODUCT_NOT_REMOVED_TEXT = "Error while removing the product.\n";
const char* PRODUCT_NOT_UPDATED_TEXT = "Error while updating the product\n";

const char* PRODUCT_INSERTED_TEXT = "Product has been successfully inserted.\n";
const char* PRODUCT_REMOVED_TEXT = "Product has been successfully removed.\n";

const char* PRODUCT_SELECT_FIELDS_TO_UPDATE_TEXT = "0 - Stop updating\n1 - Brand\n2 - Model\n3 - Price\n";
const char* PRODUCT_UPDATED_TEXT = "Product has been successfully updated.\n";

const char* SUPPLIER_COUNT_RESULT_TEXT = "Suppliers count: ";
const char* PRODUCT_COUNT_RESULT_TEXT = "Products count: ";
const char* SUPPLIERS_PRODUCTS_COUNT_RESULT_TEXT = "Supplier's products count: ";

int readInt(const char* text)
{
    int value;
    std::cout << text;
    std::cin >> value;
    return value;
}

char* readString(const char* text)
{
    char* string = new char[STRING_SIZE];
    std::cout << text;
    std::cin >> string;
    return string;
}

void addSupplierMenu()
{
    int id;
    while (true)
    {
        id = readInt(SUPPLIER_ID_REQUEST_TEXT);

        if (!checkSupplierGarbageId(id)) {
            break;
        }
        if (!checkSupplierId(id))
        {
            
                std::cout << SUPPLIER_ID_IS_TAKEN_TEXT;
                continue;
           
        }

        break;
    }

    char* name = readString(SUPPLIER_NAME_REQUEST_TEXT);
    char* location = readString(SUPPLIER_LOCATION_REQUEST_TEXT);

    Supplier supplier(id, name, location, -1);
    insertSupplier(supplier);

    std::cout << SUPPLIER_INSERTED_TEXT;
}

void getSupplierMenu()
{
    int id = readInt(SUPPLIER_ID_REQUEST_TEXT);

    Supplier supplier = getSupplier(id);
    if (supplier.getId() == -1) {
        std::cout << SUPPLIER_INVALID_ID_TEXT;
        return;
    }

    std::cout << supplier.toString();
}

void removeSupplierMenu()
{
    int id = readInt(SUPPLIER_ID_REQUEST_TEXT);
    bool success = removeSupplier(id);
    if (!success)
    {
        std::cout << SUPPLIER_NOT_REMOVED_TEXT;
        return;
    }
    std::cout << SUPPLIER_REMOVED_TEXT;
}

void updateSupplierName(Supplier& supplier)
{
    char* name = readString(SUPPLIER_NAME_REQUEST_TEXT);
    supplier.setName(name);
}

void updateSupplierLocation(Supplier& supplier)
{
    char* location = readString(SUPPLIER_LOCATION_REQUEST_TEXT);
    supplier.setLocation(location);
}

void updateSupplierFields(Supplier& supplier)
{
    int option;
    do
    {
        option = readInt(SUPPLIER_SELECT_FIELD_TO_UPDATE);
        switch (option)
        {
        case 0:
            break;
        case 1:
            updateSupplierName(supplier);
            break;
        case 2:
            updateSupplierLocation(supplier);
            break;
        default:
            break;
        }
    } while (option != 0);
}

void updateSupplierMenu()
{
    int id = readInt(SUPPLIER_ID_REQUEST_TEXT);
    Supplier supplier = getSupplier(id);

    if (supplier.getId() == -1) {
        std::cout << SUPPLIER_INVALID_ID_TEXT;
        return;
    }

    updateSupplierFields(supplier);

    bool success = updateSupplier(id, supplier);
    if (!success)
    {
        std::cout << SUPPLIER_NOT_UPDATED_TEXT;
        return;
    }

    std::cout << SUPPLIER_UPDATED_TEXT;
}

void addProductMenu()
{
    int id;
    while (true)
    {
        id = readInt(PRODUCT_ID_REQUEST_TEXT);
        if (!checkProductId(id))
        {
            std::cout << PRODUCT_ID_IS_TAKEN_TEXT;
            continue;
        }
        break;
    }

    int supplierId = readInt(PRODUCT_SUPPLIER_ID_REQUEST_TEXT);
    Supplier supplier = getSupplier(supplierId);
    if (supplier.getId() == -1) {
        std::cout << SUPPLIER_INVALID_ID_TEXT;
        return;
    }

    char* brand = readString(PRODUCT_BRAND_REQUEST_TEXT);
    char* model = readString(PRODUCT_MODEL_REQUEST_TEXT);
    char* price = readString(PRODUCT_PRICE_REQUEST_TEXT);

    Product product(id, supplierId, brand, model, price, -1, -1);
    insertProduct(product);

    std::cout << PRODUCT_INSERTED_TEXT;
}

void getProductMenu()
{
    int id = readInt(PRODUCT_ID_REQUEST_TEXT);

    Product product = getProduct(id);
    if (product.getId() == -1)
    {
        std::cout << PRODUCT_INVALID_ID_TEXT;
        return;
    }

    std::cout << product.toString();
}

void removeProductMenu()
{
    int id = readInt(PRODUCT_ID_REQUEST_TEXT);
    bool success = removeProduct(id);
    if (!success)
    {
        std::cout << PRODUCT_NOT_REMOVED_TEXT;
        return;
    }
    std::cout << PRODUCT_REMOVED_TEXT;
}

void updateProductBrand(Product& product)
{
    char* brand = readString(PRODUCT_BRAND_REQUEST_TEXT);
    product.setBrand(brand);
}

void updateProductModel(Product& product)
{
    char* model = readString(PRODUCT_MODEL_REQUEST_TEXT);
    product.setModel(model);
}

void updateProductPrice(Product& product) {
    char* price = readString(PRODUCT_PRICE_REQUEST_TEXT);
    product.setPrice(price);
}

void updateProductFields(Product& product)
{
    int options;
    do
    {
        options = readInt(PRODUCT_SELECT_FIELDS_TO_UPDATE_TEXT);
        switch (options)
        {
        case 1:
            updateProductBrand(product);
            break;
        case 2:
            updateProductModel(product);
            break;
        case 3:
            updateProductPrice(product);
            break;
        default:
            break;
        }
    } while (options != 0);
}

void updateProductMenu()
{
    int id = readInt(PRODUCT_ID_REQUEST_TEXT);

    Product product = getProduct(id);
    if (product.getId() == -1)
    {
        std::cout << PRODUCT_INVALID_ID_TEXT;
        return;
    }

    updateProductFields(product);
    updateProduct(id, product);
}

void countProductsOfSupplierMenu() {
    int id = readInt(SUPPLIER_ID_REQUEST_TEXT);

    Supplier supplier = getSupplier(id);
    if (supplier.getId() == -1) {
        std::cout << SUPPLIER_INVALID_ID_TEXT;
        return;
    }

    std::cout << "Total products of this supplier: " << countProductsOfSupplier(id);
}

void start()
{
    int option;
    do
    {
        std::cout << "\n\n";
        option = readInt(MAIN_MENU_OPTIONS_TEXT);
        switch (option)
        {
        case 0:
            break;
        case 1:
            addSupplierMenu();
            break;
        case 2:
            getSupplierMenu();
            break;
        case 3:
            removeSupplierMenu();
            break;
        case 4:
            updateSupplierMenu();
            break;
        case 5:
            addProductMenu();
            break;
        case 6:
            getProductMenu();
            break;
        case 7:
            removeProductMenu();
            break;
        case 8:
            updateProductMenu();
            break;
        case 9:
            countSuppliers();
            break;
        case 10:
            countProducts();
            break;
        case 11:
            getAllSuppliers();
            break;
        case 12:
            getAllProducts();
            break;
        default:
            std::cout << MAIN_MENU_WRONG_INPUT;
            break;
        }
    } while (option != 0);
}