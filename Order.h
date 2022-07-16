//
// Created by User on 16/7/2022.
//

#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include "mainmenu.h"

using namespace std;

struct PRODUCT {
    string pID, pName, pSupplier, pCategory, pRegisterDate;
    int pStock;
    double pPrice;
    PRODUCT * nextProduct;
};

struct ORDER{
    string oID, oDate, pID;
    int pQuantity;
    double oTotalPrice;
    ORDER * nextOrder;
};