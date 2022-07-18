#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>
#include <unistd.h>
#include <ctime>


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

    int searchID() {
        string searchKey;
        cin >> searchKey;
        ORDER *searchNode = head;
        while(searchNode!=NULL){
            if(searchNode->oID==searchKey){
                    cout<< "\n\t RESULT FOUND!" << endl
                        << "_________________________________________________________________" << endl
                        << "ORDER ID" << spacePrinter(33)
                        << "PRODUCT ID" << spacePrinter(32)
                        << "DATE" << spacePrinter(30)
                        << "QUANTITY" << spacePrinter(33)
                        << "TOTAL PRICE" << spacePrinter(30) << endl
                        << "_________________________________________________________________" << endl;

                    cout.precision(4);
                    cout << searchNode->oID << spacePrinter(30) + "  "
                         << searchNode->pID<< "\t"
                         << searchNode->oDate<< spacePrinter(33)
                         << searchNode->oQuantity<< spacePrinter(26)
                         << searchNode->oTotalPrice<< endl
                         << "_________________________________________________________________" << endl;

                return 1;
            }

            searchNode=searchNode->next;
//            key[0];

        }
        cout<< "______________________________________________________________" << endl
            << "\n\t RESULT NOT FOUND!" << endl
            << "_________________________________________________________________" << endl;
        return 0;
    }

    void createReport()
    {
        time_t now = time(0);
        tm *ltm = localtime(&now);

        int year = 1900 + ltm->tm_year;
        int month = 1 + ltm->tm_mon;
        int day = ltm->tm_mday;
        int hour = ltm->tm_hour;
        int minute = ltm->tm_min;
        int second = ltm->tm_sec;

        char tmp[256];
        getcwd(tmp, 256);

        string dir = strcat(tmp,"\\Generated_Reports\\report_");
        dir = dir + to_string(day) + "_"
              + to_string(month) + "_"
              + to_string(year) + "_"
              + to_string(hour) + "-"
              + to_string(minute) + "-"
              + to_string(second) + ".txt";

        int totalQuantity = 0;
        double totalPrice = 0.0;
        cout.precision(4);
        ORDER * curr = head;
        ORDER * curr2 = head;

        while( curr != nullptr)
        {
            totalQuantity = totalQuantity + curr->oQuantity;
            totalPrice = totalPrice + curr->oTotalPrice;
            curr = curr->next;
        }
        cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl
             << "+                                                                                                                     +" << endl
             << "+                                       LiveOrder IT Order Summary Sales Report                                       +" << endl
             << "+                                                                                                                     +" << endl
             << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
        cout    << "______________________________________________________________________________________________________________________" << endl
                << "ORDER ID" << spacePrinter(33)
                << "PRODUCT ID" << spacePrinter(32)
                << "DATE" << spacePrinter(-25)
                << "QUANTITY" << spacePrinter(33)
                << "TOTAL PRICE" << spacePrinter(30) << endl
                << "______________________________________________________________________________________________________________________" << endl;

        while( curr2 != nullptr)
        {
            cout.precision(4);
            cout << curr2->oID << spacePrinter(30) + "  "
                 << curr2->pID<< "\t"
                 << curr2->oDate<< spacePrinter(-25)
                 << curr2->oQuantity<< spacePrinter(26)
                 << curr2->oTotalPrice<< endl;
            curr2 = curr2->next;
        }
        cout.precision(4);
        cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl
             << "+                                                                                        + Total Sold : " << totalQuantity << endl
             << "+                                                                                        + Total Price: RM" << totalPrice << endl
             << "+                                                                                        +                             " << endl
             << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl
             << "Generated Report On The: " << to_string(day) + "/"
                                                  + to_string(month) + "/"
                                                  + to_string(year) + "\t"
                                                  + to_string(hour) + ":"
                                                  + to_string(minute) + ":"
                                                  + to_string(second)<< endl;
        printReport();
    }

    void printReport(){

        time_t now = time(0);
        tm *ltm = localtime(&now);

        int year = 1900 + ltm->tm_year;
        int month = 1 + ltm->tm_mon;
        int day = ltm->tm_mday;
        int hour = ltm->tm_hour;
        int minute = ltm->tm_min;
        int second = ltm->tm_sec;

        char tmp[256];
        getcwd(tmp, 256);

        string dir = strcat(tmp,"\\Generated_Reports\\report_");
        dir = dir + to_string(day) + "_"
              + to_string(month) + "_"
              + to_string(year) + "_"
              + to_string(hour) + "-"
              + to_string(minute) + "-"
              + to_string(second) + ".txt";

        ofstream fw(dir, std::ofstream::out);
//        cout << tmp << endl;
//        cout << put_time(localtime(&now), "%F %T") <<  endl;

        int totalQuantity = 0;
        double totalPrice = 0.0;
        cout.precision(4);
        ORDER * curr = head;
        ORDER * curr2 = head;

        while( curr != nullptr)
        {
            totalQuantity = totalQuantity + curr->oQuantity;
            totalPrice = totalPrice + curr->oTotalPrice;
            curr = curr->next;
        }

        if (fw.is_open())
        {
            fw << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl
                 << "+                                                                                                                     +" << endl
                 << "+                                       LiveOrder IT Order Summary Sales Report                                       +" << endl
                 << "+                                                                                                                     +" << endl
                 << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
            fw    << "______________________________________________________________________________________________________________________" << endl
                    << "ORDER ID" << spacePrinter(33)
                    << "PRODUCT ID" << spacePrinter(32)
                    << "DATE" << spacePrinter(-25)
                    << "QUANTITY" << spacePrinter(33)
                    << "TOTAL PRICE" << spacePrinter(30) << endl
                    << "______________________________________________________________________________________________________________________" << endl;

            while( curr2 != nullptr)
            {
                fw.precision(4);
                fw << curr2->oID << spacePrinter(30) + "  "
                     << curr2->pID<< "\t"
                     << curr2->oDate<< spacePrinter(-25)
                     << curr2->oQuantity<< spacePrinter(26)
                     << curr2->oTotalPrice<< endl;
                curr2 = curr2->next;
            }
            fw.precision(4);
            fw << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl
                 << "+                                                                                        + Total Sold : " << totalQuantity << endl
                 << "+                                                                                        + Total Price: RM" << totalPrice << endl
                 << "+                                                                                        +                             " << endl
                 << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl
                 << "Generated Report On The: " << to_string(day) + "/"
                    + to_string(month) + "/"
                    + to_string(year) + "\t"
                    + to_string(hour) + ":"
                    + to_string(minute) + ":"
                    + to_string(second)<< endl;

            fw.close();
        }
        else cout << "Problem with opening file";
        fw.close();
        cout << endl << "Report File Created and Saved Successfully at Directory: '" << dir << "'" << endl;

    }


};
