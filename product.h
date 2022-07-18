#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// Data struct for PRODUCT

string spacePrinter(int length)
{
    string spaces =" ";
    int spaceNum = 35 - length;
    for(int i=0; i<spaceNum; i++){
        spaces.append(" ");
    }
    return spaces;
}

struct PRODUCT {
    string pID, pName, pSupplier, pCategory, pRegisterDate;
    int pStock;
    double pPrice;
    PRODUCT* next;
};

struct pLinkedList{
    PRODUCT * head;
    int size;
    pLinkedList()
    {
        cout << "--- Constructing the LinkedList object ---" << endl;
        this->size = 0;
        this->head = nullptr;
    }

    void insertAtEnd(string productID,
                     string productName,
                     string productSupplier,
                     string productCategory,
                     string productRegisterDate,
                     int productStock,
                     double productPrice){
        PRODUCT * nextProduct = new PRODUCT;
        nextProduct->pID = productID;
        nextProduct->pName = productName;
        nextProduct->pSupplier = productSupplier;
        nextProduct->pCategory = productCategory;
        nextProduct->pRegisterDate = productRegisterDate;
        nextProduct->pStock = productStock;
        nextProduct->pPrice = productPrice;

        nextProduct->next = nullptr;
        if ( head == nullptr ) {
            head = nextProduct;
        } else {
            PRODUCT * last = head;
            while( last->next != nullptr )
                last = last->next;
            last->next = nextProduct;
        }
        size++;
    }

    void show()
    {
        PRODUCT * curr = head;
        cout    << "______________________________________________________________________________" << endl
                << "ID" << spacePrinter(30)
                << "NAME" << spacePrinter(18)
                << "SUPPLIER" << spacePrinter(33)
                << "CATEGORY" << spacePrinter(30)
                << "DATE" << spacePrinter(25)
                << "QTY" << spacePrinter(34)
                << "PRICE" << spacePrinter(40) << endl
                << "_______________________________________________________________________________" << endl;

        while( curr != nullptr)
        {
            cout.precision(4);
            cout << curr->pID << spacePrinter(curr->pID.size())
                 << curr->pName<< spacePrinter(curr->pName.size())
                 << curr->pSupplier<< spacePrinter(curr->pSupplier.size())
                 << curr->pCategory<< spacePrinter(curr->pCategory.size())
                 << curr->pRegisterDate<<spacePrinter(curr->pRegisterDate.size())
                 << curr->pStock<< spacePrinter(30)
                 << curr->pPrice<< endl;
            ;
            curr = curr->next;
        }
    }
};
