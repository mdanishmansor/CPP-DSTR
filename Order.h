//
// Created by User on 16/7/2022.
//

#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <iomanip>
#include <string>

//#include "product.h"
#include "userLogin.h"

using namespace std;

// Data struct for PRODUCT

struct ORDER{
    string oID, oDate, pID;
    int oQuantity;
    double oTotalPrice;
    ORDER * next;
};

struct oLinkedList{
    ORDER * head;
    int size;
    oLinkedList()
    {
        cout << "--- Constructing the LinkedList object ---" << endl;
        this->size = 0;
        this->head = nullptr;
    }

    void deleteAll(){
        this->size = 0;
        this->head = nullptr;

    }

    void insertAtEnd(string orderID,
                     string productID,
                     string orderDate,
                     int productQuantity,
                     double orderTotalPrice){
        ORDER * nextOrder = new ORDER;
        nextOrder->oID = orderID;
        nextOrder->pID = productID;
        nextOrder->oDate = orderDate;
        nextOrder->oQuantity = productQuantity;
        nextOrder->oTotalPrice = orderTotalPrice;

        nextOrder->next = nullptr;
        if ( head == nullptr ) {
            head = nextOrder;
        } else {
            ORDER * last = head;
            while( last->next != nullptr )
                last = last->next;
            last->next = nextOrder;
        }
        size++;
    }

    void show()
    {
        ORDER * curr = head;
        cout    << "_________________________________________________________________" << endl
                << "ORDER ID" << spacePrinter(33)
                << "PRODUCT ID" << spacePrinter(32)
                << "DATE" << spacePrinter(30)
                << "QUANTITY" << spacePrinter(33)
                << "TOTAL PRICE" << spacePrinter(30) << endl
                << " _________________________________________________________________" << endl;

        while( curr != nullptr)
        {
            cout.precision(4);
            cout << curr->oID << spacePrinter(30) + "  "
                 << curr->pID<< "\t"
                 << curr->oDate<< spacePrinter(33)
                 << curr->oQuantity<< spacePrinter(26)
                 << curr->oTotalPrice<< endl;
            curr = curr->next;
        }
    }

    void update(string orderID, string userType)
    {
        string productID, orderDate, editedDate;
        int productQuantity, choice1, choice2, editedQuantity;
        double orderTotalPrice, editedTPrice;

        ORDER * editOrder = head;

        while( editOrder != nullptr)
        {
            if (orderID == editOrder->oID){
                cout    << "____________________________________________________________" << endl
                        << "ORDER ID" << spacePrinter(33)
                        << "PRODUCT ID" << spacePrinter(32)
                        << "DATE" << spacePrinter(30)
                        << "QUANTITY" << spacePrinter(33)
                        << "TOTAL PRICE" << spacePrinter(30) << endl
                        << " ___________________________________________________________" << endl;
                cout.precision(4);
                cout << editOrder->oID << spacePrinter(30) + "  "
                     << editOrder->pID<< "\t"
                     << editOrder->oDate<< spacePrinter(33)
                     << editOrder->oQuantity<< spacePrinter(26)
                     << editOrder->oTotalPrice<< endl << endl << endl
                     << "\t DO YOU WANT TO EDIT THIS ORDER?" << endl
                     << "\t [1] Yes \n\t [2] No" << endl << endl
                     << "\t ENTER YOUR CHOICE [1/2]: ";
                     cin >> choice1;
                cout << "_______________________________________________" << endl;

                switch (choice1)
                {
                    case 1:
                        cout << "\t WHICH DETAILS DO YOU WANT TO EDIT?"<< endl
                             << "\t [1] Order Date \n\t [2] Quantity \n\t [3] Total Price \n\t [4] RETURN" << endl << endl
                             << "\t ENTER YOUR CHOICE [1/2/3/4]: ";
                        cin >> choice2;
                        cout << "_______________________________________________" << endl;

                        cout << "Please Update The Details and Do Dot Leave the Details Empty!" << endl;
                        switch (choice2) {
                            case 1:
                                cout << "\t ORDER DATE (Current value: " << editOrder->oDate << "): ";
                                cin >> editedDate;
                                editOrder->oDate = editedDate;
                                cout << "ORDER DATE Succesfully Updated!" << endl;

                                break;
                            case 2:
                                cout << "\t QUANTITY (Current value" << editOrder->oQuantity << "): ";
                                cin >> editedQuantity;
                                editOrder->oDate = editedDate;
                                cout << "QUANTITY Succesfully Updated!" << endl;
                                break;
                            case 3:
                                cout << "\t TOTAL PRICE (Current value" << editOrder->oTotalPrice << "): ";
                                cin >> editedTPrice;
                                editOrder->oDate = editedDate;
                                cout << "TOTAL PRICE Succesfully Updated!" << endl;
                                break;
                            case 4:
                                update(orderID, userType);
                                break;
                            default:
                                break;
                                cout << "\n\tERROR WARNING! Please Choose Between 1/2/3/4 only! :^(" << endl;
                                update(orderID, userType);
                                break;
                        }
                        break;

                    case 2:
                        break;

                    default:
                        cout << "\n\tERROR WARNING! Please Choose Between 1/2 only! :^(" << endl;
                        update(orderID, userType);
                        break;
                }

                editOrder = nullptr;

            } else {
                editOrder = editOrder->next;
            }
        }
    }

    void selectionSort(int orderType, string arrangeType)
    {
        string selectedSort = "default";

        ORDER * sortOrder = head;

        // Traverse the List
        while (sortOrder) {
            ORDER* min = sortOrder;
            ORDER* r = sortOrder->next;

            if (arrangeType == "des"){
                if (orderType == 1){
                    // Traverse the unsorted sublist
                    while (r) {
                        if (min->oID < r->oID)
                            min = r;

                        r = r->next;
                    }

                    // Swap Data
                    string x = sortOrder->oID;
                    sortOrder->oID = min->oID;
                    min->oID = x;
                    sortOrder = sortOrder->next;

                } else if (orderType == 2){
                    while (r) {
                        if (min->oQuantity < r->oQuantity)
                            min = r;

                        r = r->next;
                    }

                    // Swap Data
                    int x = sortOrder->oQuantity;
                    sortOrder->oQuantity = min->oQuantity;
                    min->oQuantity = x;
                    sortOrder = sortOrder->next;

                } else {
                    // No sorting here
                    sortOrder = nullptr;
                }
            } else {  // WHEN USER CHOOSES DESCENDING ORDER
                if (orderType == 1){
                    // Traverse the unsorted sublist
                    while (r) {
                        if (min->oID > r->oID)
                            min = r;

                        r = r->next;
                    }

                    // Swap Data
                    string x = sortOrder->oID;
                    sortOrder->oID = min->oID;
                    min->oID = x;
                    sortOrder = sortOrder->next;

                } else if (orderType == 2){
                    while (r) {
                        if (min->oQuantity > r->oQuantity)
                            min = r;

                        r = r->next;
                    }

                    // Swap Data
                    int x = sortOrder->oQuantity;
                    sortOrder->oQuantity = min->oQuantity;
                    min->oQuantity = x;
                    sortOrder = sortOrder->next;

                } else {
                    sortOrder = nullptr;
                }
            }


        }
    }


};
