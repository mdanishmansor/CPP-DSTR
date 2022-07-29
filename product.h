// Including various C++ packages and libraries
#include <iostream>
#include <iomanip>
#include <string>

// Usage of preprocessor directive for single compilation
#pragma once

using namespace std;

// Function for data display
string spacePrinter(int length)
{
    string spaces =" ";
    int spaceNum = 35 - length;
    for(int i=0; i<spaceNum; i++){
        spaces.append(" ");
    }
    return spaces;
}

// Data struct for PRODUCT
struct PRODUCT {
    string pID, pName, pSupplier, pCategory, pRegisterDate;
    int pStock;
    double pPrice;
    PRODUCT* next;
};

// Struct for PRODUCT Linkedlist
struct pLinkedList{
    PRODUCT * head;
    int size;
    pLinkedList()
    {
        this->size = 0;
        this->head = nullptr;
    }

    // Function for returning the size of the current Linkedlist
    int getSize()
    {
        return size;
    }

    // Function for deleting all data
    void deleteAll(){
        this->size = 0;
        this->head = nullptr;

    }

    // Function to identify if the Product ID exists
    bool getProdID(string prodID){
        PRODUCT * curr = head;
        while( curr != nullptr)
        {
            if(prodID == curr->pID) {
                curr = nullptr;
                return true;
            } else {
                curr = curr->next;
            }

        }
        return false;
    }

    // Function to identify if the Product Quantity is enough to create a new order
    bool getProdQuantity(string prodID, int prodQuantity){
        int currentQuantity;
        PRODUCT * curr = head;
        while( curr != nullptr)
        {
            if(prodID == curr->pID) {
                currentQuantity =  curr->pStock - prodQuantity;
                if (currentQuantity >= 0){
                    curr->pStock = currentQuantity;
                    return true;
                }
                curr = nullptr;
                return false;
            } else {
                curr = curr->next;
            }

        }
        return false;
    }

    // Function to insert hardcoded data at the end of the PRODUCT Linkedlist
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

    // Function to generate a new ID for new product insertion
    string generateID(){
        int currentID = getSize() + 1;
        string generatedID;


        std::string str = to_string(currentID);
        size_t n = 3;

        std::ostringstream ss;
        ss << std::setw(n) << std::setfill('0') << str;
        std::string s = ss.str();

        generatedID = "P" + s;

        return generatedID;
    }

    // Function to insert new data at the end of the PRODUCT Linkedlist
    void insertProduct(){
        PRODUCT * nextProduct = new PRODUCT;
        string productID, productName, productSupplier, productCategory, productRegisterDate;
        int productStock;
        double productPrice;
        time_t now = time(0);
        tm *ltm = localtime(&now);

        int year = 1900 + ltm->tm_year;
        int month = 1 + ltm->tm_mon;
        int day = ltm->tm_mday;

        productID = generateID();
        cout << "Product Name: ";
        cin >> productName;
        cout << "\nProduct Supplier: ";
        cin >> productSupplier;
        cout << "\nProduct Category: ";
        cin >> productCategory;
        productRegisterDate = to_string(year) + "/" + to_string(month) + "/" + to_string(day);
        cout << "\nProduct Stock: ";
        cin >> productStock;
        if (cin.fail()) { // To Validate user input that is supposed to be for int value type input
            cin.clear();
            cin.ignore();
            productStock = 0;
        }
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        while (productStock <= 0){
            cout << "\nERROR:STOCK HAS TO BE MORE THAN 0 \nProduct Stock: ";
            cin >> productStock;
        }

        cout << "\nProduct Price: RM";
        cin >> productPrice;

        if (cin.fail()) { // To Validate user input that is supposed to be for int value type input
            cout << "\nInvalid input! Resetting value to RM0.00";
            cin.clear();
            cin.ignore();
            productStock = -1;
        }
        while (productPrice <= 0){
            cout << "\nERROR:PRICE HAS TO BE MORE THAN 0 \nProduct Price: ";
            cin >> productStock;
        }
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

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

    // Function to search for Product ID within PRODUCT Linkedlist
    int searchPID() {
        string searchKey;
        cin >> searchKey;
        PRODUCT *searchNode = head;
        while(searchNode!=NULL){
            if(searchNode->pID==searchKey){
                cout << searchNode->pID.size() << endl;
                cout<< "\n\t RESULT FOUND!" << endl
                    << "________________________________________________________________________________________________________________" << endl
                    << "ID" << spacePrinter(30)
                    << "NAME" << spacePrinter(4)
                    << "SUPPLIER" << spacePrinter(30)
                    << "CATEGORY" << spacePrinter(25)
                    << "REGISTER DATE" << "\t"
                    << "STOCK" << spacePrinter(30)
                    << "PRICE" << spacePrinter(30) << endl
                    << "_______________________________________________________________________________________________________________" << endl;

                cout.precision(4);
                cout << searchNode->pID << "\t"
                     << searchNode->pName<< spacePrinter(searchNode->pName.size())
                     << searchNode->pSupplier<< spacePrinter(searchNode->pSupplier.size() + 22)
                     << searchNode->pCategory<< spacePrinter(searchNode->pCategory.size() + 17)
                     << searchNode->pRegisterDate<< spacePrinter(searchNode->pRegisterDate.size() + 17)
                     << searchNode->pStock<< spacePrinter(27)
                     << searchNode->pPrice<< endl
                     << "______________________________________________________________________________________________________________" << endl;

                return 1;
            }
            searchNode=searchNode->next;
        }
        cout<< "______________________________________________________________" << endl
            << "\n\t PRODUCT ID NOT FOUND!" << endl
            << "_________________________________________________________________" << endl;
        return 0;
    }

    // Function to search for Product Quantity within PRODUCT Linkedlist
    int searchPStock() {
        int searchKey;
        cin >> searchKey;
        PRODUCT *searchNode = head;
        cout<< "\n\t STOCK SEARCH RESULT!" << endl
            << "________________________________________________________________________________________________________________" << endl
            << "ID" << spacePrinter(30)
            << "NAME" << spacePrinter(4)
            << "SUPPLIER" << spacePrinter(30)
            << "CATEGORY" << spacePrinter(25)
            << "REGISTER DATE" << "\t"
            << "STOCK" << spacePrinter(30)
            << "PRICE" << spacePrinter(30) << endl
            << "_______________________________________________________________________________________________________________" << endl;
        while(searchNode!=NULL){
            if(searchNode->pStock==searchKey){
                cout.precision(4);
                cout << searchNode->pID << "\t"
                     << searchNode->pName<< spacePrinter(searchNode->pName.size())
                     << searchNode->pSupplier<< spacePrinter(searchNode->pSupplier.size() + 22)
                     << searchNode->pCategory<< spacePrinter(searchNode->pCategory.size() + 17)
                     << searchNode->pRegisterDate<< spacePrinter(searchNode->pRegisterDate.size() + 17)
                     << searchNode->pStock<< spacePrinter(27)
                     << "RM" << searchNode->pPrice<< endl
                     << "______________________________________________________________________________________________________________" << endl;

            }
            searchNode=searchNode->next;
        }
        cout << "\n\t SEARCH COMPLETED!" << endl;
        return 0;
    }

    // Function to calculate for total price for based on product quantity for a new ORDER creation
    int calcTotal(string prodID, int quantity){
        double totalPrice;
        PRODUCT * curr = head;
        while( curr != nullptr)
        {
            if(prodID == curr->pID) {
                totalPrice = curr->pPrice * quantity;
                curr = nullptr;
                return totalPrice;

            } else {
                curr = curr->next;
            }
        }
        return 0;
    }

    // Function for displaying PRODUCT details in a table form
    void show()
    {
        PRODUCT * curr = head;
        cout << "_____________________________________________________________________________________________________________________" << endl
            << "ID" << spacePrinter(30)
            << "NAME" << spacePrinter(4)
            << "SUPPLIER" << spacePrinter(30)
            << "CATEGORY" << spacePrinter(25)
            << "REGISTER DATE" << "\t"
            << "STOCK" << spacePrinter(30)
            << "PRICE" << spacePrinter(30) << endl
            << "_____________________________________________________________________________________________________________________" << endl;

        while( curr != nullptr)
        {
            cout.precision(4);
            cout << curr->pID << "\t"
                 << curr->pName<< spacePrinter(curr->pName.size())
                 << curr->pSupplier<< spacePrinter(curr->pSupplier.size() + 22)
                 << curr->pCategory<< spacePrinter(curr->pCategory.size() + 17)
                 << curr->pRegisterDate<< spacePrinter(curr->pRegisterDate.size() + 17)
                 << curr->pStock<< spacePrinter(27)
                 << "RM" << setprecision(2) << fixed << curr->pPrice<< endl;

            curr = curr->next;
        }
    }

    // Function for handling sorting processes
    void selectionSort(int productType, string arrangeType)
    {
        string selectedSort = "default";

        PRODUCT * sortProduct = head;

        // Traverse the List
        while (sortProduct) {
            PRODUCT* min = sortProduct;
            PRODUCT* r = sortProduct->next;

            if (arrangeType == "des"){
                if (productType == 1){
                    // Traverse the unsorted sublist
                    while (r) {
                        if (min->pID < r->pID)
                            min = r;

                        r = r->next;
                    }

                    // Swap Data
                    string tempPID = sortProduct->pID;
                    string tempName = sortProduct->pName;
                    string tempSupplier = sortProduct->pSupplier;
                    string tempCategory = sortProduct->pCategory;
                    string tempRegisterDate= sortProduct->pRegisterDate;
                    int tempStock = sortProduct->pStock;
                    double tempPrice = sortProduct->pPrice;

                    sortProduct->pID = min->pID;
                    sortProduct->pName = min->pName;
                    sortProduct->pSupplier = min->pSupplier;
                    sortProduct->pCategory = min->pCategory;
                    sortProduct->pRegisterDate = min->pRegisterDate;
                    sortProduct->pStock = min->pStock;
                    sortProduct->pPrice = min->pPrice;

                    min->pID = tempPID;
                    min->pName = tempName;
                    min->pSupplier = tempSupplier;
                    min->pCategory = tempCategory;
                    min->pRegisterDate = tempRegisterDate;
                    min->pStock = tempStock;
                    min->pPrice = tempPrice;

                    sortProduct = sortProduct->next;

                } else if (productType == 2){
                    while (r) {
                        if (min->pStock < r->pStock)
                            min = r;

                        r = r->next;
                    }

                    // Swap Data
                    string tempPID = sortProduct->pID;
                    string tempName = sortProduct->pName;
                    string tempSupplier = sortProduct->pSupplier;
                    string tempCategory = sortProduct->pCategory;
                    string tempRegisterDate= sortProduct->pRegisterDate;
                    int tempStock = sortProduct->pStock;
                    double tempPrice = sortProduct->pPrice;

                    sortProduct->pID = min->pID;
                    sortProduct->pName = min->pName;
                    sortProduct->pSupplier = min->pSupplier;
                    sortProduct->pCategory = min->pCategory;
                    sortProduct->pRegisterDate = min->pRegisterDate;
                    sortProduct->pStock = min->pStock;
                    sortProduct->pPrice = min->pPrice;

                    min->pID = tempPID;
                    min->pName = tempName;
                    min->pSupplier = tempSupplier;
                    min->pCategory = tempCategory;
                    min->pRegisterDate = tempRegisterDate;
                    min->pStock = tempStock;
                    min->pPrice = tempPrice;

                    sortProduct = sortProduct->next;

                } else {
                    // No sorting here
                    sortProduct = nullptr;
                }
            } else {  // WHEN USER CHOOSES DESCENDING ORDER
                if (productType == 1){
                    // Traverse the unsorted sublist
                    while (r) {
                        if (min->pID > r->pID)
                            min = r;

                        r = r->next;
                    }

                    // Swap Data
                    string tempPID = sortProduct->pID;
                    string tempName = sortProduct->pName;
                    string tempSupplier = sortProduct->pSupplier;
                    string tempCategory = sortProduct->pCategory;
                    string tempRegisterDate= sortProduct->pRegisterDate;
                    int tempStock = sortProduct->pStock;
                    double tempPrice = sortProduct->pPrice;

                    sortProduct->pID = min->pID;
                    sortProduct->pName = min->pName;
                    sortProduct->pSupplier = min->pSupplier;
                    sortProduct->pCategory = min->pCategory;
                    sortProduct->pRegisterDate = min->pRegisterDate;
                    sortProduct->pStock = min->pStock;
                    sortProduct->pPrice = min->pPrice;

                    min->pID = tempPID;
                    min->pName = tempName;
                    min->pSupplier = tempSupplier;
                    min->pCategory = tempCategory;
                    min->pRegisterDate = tempRegisterDate;
                    min->pStock = tempStock;
                    min->pPrice = tempPrice;

                    sortProduct = sortProduct->next;

                } else if (productType == 2){
                    while (r) {
                        if (min->pStock > r->pStock)
                            min = r;

                        r = r->next;
                    }

                    // Swap Data
                    string tempPID = sortProduct->pID;
                    string tempName = sortProduct->pName;
                    string tempSupplier = sortProduct->pSupplier;
                    string tempCategory = sortProduct->pCategory;
                    string tempRegisterDate= sortProduct->pRegisterDate;
                    int tempStock = sortProduct->pStock;
                    double tempPrice = sortProduct->pPrice;

                    sortProduct->pID = min->pID;
                    sortProduct->pName = min->pName;
                    sortProduct->pSupplier = min->pSupplier;
                    sortProduct->pCategory = min->pCategory;
                    sortProduct->pRegisterDate = min->pRegisterDate;
                    sortProduct->pStock = min->pStock;
                    sortProduct->pPrice = min->pPrice;

                    min->pID = tempPID;
                    min->pName = tempName;
                    min->pSupplier = tempSupplier;
                    min->pCategory = tempCategory;
                    min->pRegisterDate = tempRegisterDate;
                    min->pStock = tempStock;
                    min->pPrice = tempPrice;

                    sortProduct = sortProduct->next;

                } else {
                    sortProduct = nullptr;
                }
            }


        }
    }

    // Function for handling PRODUCT update process
    void update(string prodID, string userType)
    {
        string productID, productName, productSupplier, productCategory, productRegisterDate, eProdName, eProdSupplier, eProdCategory;
        int productStock, choice1, choice2, eProdStock;
        double productPrice, eProdPrice;

        PRODUCT * editProduct = head;

        while( editProduct != nullptr)
        {
            if (prodID == editProduct->pID){
                cout << "\n________________________________________________________________________________________________________________" << endl
                     << "ID" << spacePrinter(30)
                     << "NAME" << spacePrinter(4)
                     << "SUPPLIER" << spacePrinter(30)
                     << "CATEGORY" << spacePrinter(25)
                     << "REGISTER DATE" << "\t"
                     << "STOCK" << spacePrinter(30)
                     << "PRICE" << spacePrinter(30) << endl
                     << "_______________________________________________________________________________________________________________" << endl;
                cout.precision(4);
                cout << editProduct->pID << "\t"
                     << editProduct->pName<< spacePrinter(editProduct->pName.size())
                     << editProduct->pSupplier<< spacePrinter(editProduct->pSupplier.size() + 22)
                     << editProduct->pCategory<< spacePrinter(editProduct->pCategory.size() + 17)
                     << editProduct->pRegisterDate<< spacePrinter(editProduct->pRegisterDate.size() + 17)
                     << editProduct->pStock<< spacePrinter(27)
                     << editProduct->pPrice<< endl
                     << "\n\t DO YOU WANT TO EDIT THIS ORDER?" << endl
                     << "\t [1] Yes \n\t [2] No" << endl << endl
                     << "\t ENTER YOUR CHOICE [1/2]: ";
                cin >> choice1;
                cout << "_______________________________________________" << endl;

                switch (choice1)
                {
                    case 1:
                        cout << "\t WHICH DETAILS DO YOU WANT TO EDIT?"<< endl
                             << "\t [1] Product Name \n\t [2] Product Supplier \n\t [3] Product Category \n\t [4] Product Stock \n\t [5] Product Price \n\t [6] RETURN" << endl << endl
                             << "\t ENTER YOUR CHOICE [1/2/3/4/5/6]: ";
                        cin >> choice2;
                        cout << "_______________________________________________" << endl;

                        cout << "Please Update The Details and Do Dot Leave the Details Empty!" << endl;
                        switch (choice2) {
                            case 1:
                                cout << "\t PRODUCT NAME (Current name: " << editProduct->pName << "): ";
                                cin >> eProdName;
                                editProduct->pName = eProdName;
                                cout << "\nPRODUCT NAME Succesfully Updated!" << endl;

                                break;
                            case 2:
                                cout << "\t PRODUCT SUPPLIER (Current supplier: " << editProduct->pSupplier << "): ";
                                cin >> eProdSupplier;
                                editProduct->pSupplier = eProdSupplier;
                                cout << "\nQUANTITY Succesfully Updated!" << endl;
                                break;
                            case 3:
                                cout << "\t PRODUCT CATEGORY (Current category: " << editProduct->pCategory << "): ";
                                cin >> eProdCategory;
                                editProduct->pCategory = eProdCategory;
                                cout << "\nPRODUCT CATEGORY Succesfully Updated!" << endl;
                                break;
                            case 4:
                                cout << "\t PRODUCT STOCK (Current stock: " << editProduct->pStock << "): ";
                                cin >> eProdStock;

                                if (cin.fail()) { // To Validate user input that is supposed to be for int value type input
                                    cin.clear();
                                    cin.ignore();
                                    eProdStock = 0;
                                }
                                cin.clear();
                                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                                while (eProdStock <= 0){
                                    cout << "\nERROR:STOCK HAS TO BE MORE THAN 0 \nProduct Stock: ";
                                    cin >> eProdStock;
                                }

                                editProduct->pStock = eProdStock;
                                cout << "\nPRODUCT STOCK Succesfully Updated!" << endl;
                                break;
                            case 5:
                                cout << "\t PRODUCT PRICE (Current price: " << editProduct->pPrice << "): ";
                                cin >> eProdPrice;

                                if (cin.fail()) { // To Validate user input that is supposed to be for int value type input
                                    cin.clear();
                                    cin.ignore();
                                    eProdStock = 0;
                                }
                                cin.clear();
                                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                                while (eProdPrice <= 0){
                                    cout << "\nERROR:STOCK HAS TO BE MORE THAN 0 \nProduct Stock: ";
                                    cin >> eProdPrice;
                                }

                                editProduct->pPrice = eProdPrice;
                                cout << "\nPRODUCT PRICE Succesfully Updated!" << endl;
                                break;
                            case 6:
                                update(prodID, userType);
                                break;
                            default:
                                break;
                                cout << "\n\tERROR WARNING! Please Choose Between 1/2/3/4/5/6 only! :^(" << endl;
                                update(prodID, userType);
                                break;
                        }
                        break;

                    case 2:
                        break;

                    default:
                        cout << "\n\tERROR WARNING! Please Choose Between 1/2 only! :^(" << endl;
                        update(prodID, userType);
                        break;
                }

                editProduct = nullptr;

            } else {
                editProduct = editProduct->next;
            }
        }
        cout << "\n\t PRODUCT ID NOT FOUND!" << endl;

    }
};

