//
// Created by User on 16/7/2022.
//

#include <iostream>
#include <conio.h>
#include <iomanip>
#include <stdlib.h>
#include "mainmenu.h"

// Data struct for PRODUCT
struct PRODUCT {
    string pID, pName, pSupplier, pCategory, pRegisterDate;
    int pStock;
    double price;
    PRODUCT* nextProduct;
};

// Data struct for ORDER
struct ORDER {
    string oID, oDate, pID;
    int pQuantity;
    double oTotalPrice;
    ORDER * nextOrder;
};

// Function to create a new pointer for order
ORDER* readOrder(
        string oID,
        string oDate,
        string pSupplier,
        string pCategory,
        string pRegisterDate,
        int pQuantity,
        double oTotalPrice) {
    ORDER * newONode = new ORDER;
    return newONode;
}

// Function to add a new product to the list
PRODUCT* addProduct(PRODUCT* prod, PRODUCT p) {
    static int id = 1;
    p.pID = to_string(id++);
    PRODUCT* newProduct = new PRODUCT(p);
    newProduct->nextProduct = prod;
    prod = newProduct;
    return prod;
}

// Function to initilize the list using hard coded values
PRODUCT* initializeProducts(PRODUCT* prod) {
    PRODUCT p = {"0", "Samsung", "Samsung", "Phone", "01-02-2020", 10, 800};
    prod = addProduct(prod, p);

    p = {"0", "Apple", "Apple", "Phone", "20-01-2020", 14, 1000};
    prod = addProduct(prod, p);

    p = {"0", "iOS cable", "Apple", "Accessories", "10-04-2020", 50, 25};
    prod = addProduct(prod, p);

    p = {"0", "USB-C", "Samsung", "Accessories", "12-03-2020", 80, 15};
    prod = addProduct(prod, p);

    p = {"0", "Drone", "DJI", "Camera", "01-06-2021", 4, 1200};
    prod = addProduct(prod, p);

    return prod;
}

// Function to display a product
void displayProduct(PRODUCT* prod) {
    cout << left << setw(4) << prod->pID;
    cout << setw(12) << prod->pName;
    cout << setw(16) << prod->pSupplier;
    cout << setw(16) << prod->pCategory;
    cout << setw(12) << prod->pRegisterDate;
    cout << setw(8) << prod->pStock;
    cout << prod->price << endl;
}

// Function to display an order
void displayOrder(ORDER* ord) {
    cout << left << setw(4) << ord->oID;
    cout << setw(12) << ord->oDate;
    cout << setw(8) << ord->pQuantity;
    cout << ord->oTotalPrice << endl;
}

// Function to display all the products
void displayProducts(PRODUCT* prod) {
    PRODUCT* cur = prod;

    cout << "ID  NAME        SUPPLIER        CATEGORY        DATE        QTY     PRICE" << endl;
    cout << "-------------------------------------------------------------------------" << endl;
    while (cur) {
        displayProduct(cur);
        cur = cur->nextProduct;
    }
    cout << "-------------------------------------------------------------------------" << endl;
}

// Function to display all the orders
void displayOrders(ORDER* ord) {
    ORDER* cur = ord;

    cout << "ID  DATE        QTY     PRICE" << endl;
    cout << "--------------------------------" << endl;
    while (cur) {
        displayOrder(cur);
        cur = cur->nextOrder;
    }
    cout << "--------------------------------" << endl;
}

// Function to add a new order to the list
ORDER* buyProduct(PRODUCT* products, ORDER* orders) {
    displayProducts(products);
    static int id = 1;

    string ID;

    // find the product
    cout << endl << "Enter the ID of the product you want to buy: ";
    cin >> ID;
    PRODUCT* cur = products;
    while (cur) {
        if (cur->pID == ID) {
            break;
        }
        cur = cur->nextProduct;
    }

    // Create a new order
    ORDER* newOrder = new ORDER;
    newOrder->oID = to_string(id++);
    newOrder->pID = cur->pID;

    cout << "Enter the date: ";
    cin >> newOrder->oDate;
    cout << "Enter the quantity you want to buy: ";
    cin >> newOrder->pQuantity;
    newOrder->oTotalPrice = newOrder->pQuantity * cur->price;
    cur->pStock -= newOrder->pQuantity;

    // Add to the list
    newOrder->nextOrder = orders;
    orders = newOrder;
    return orders;
}

// Main function
int main() {
    PRODUCT *products = nullptr;
    ORDER* orders = nullptr;
    products = initializeProducts(products);
    int choice;

    while (1) {
        // display menu and get user choice


        cout << "1. Display Products." << endl;
        cout << "2. Order a product." << endl;
        cout << "3. Display orders." << endl;
        cout << "4. Exit" << endl;
        cout << endl << "Enter your choice: ";
        cin >> choice;
        cout << endl;

        switch(choice) {
            case 1:
                displayProducts(products);
                break;
            case 2:
                orders = buyProduct(products, orders);
                break;
            case 3:
                displayOrders(orders);
                break;
            case 4:
                return 0;
        }
    }
}