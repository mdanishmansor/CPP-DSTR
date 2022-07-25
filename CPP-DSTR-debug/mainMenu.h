//
// Created by User on 16/7/2022.
//

#include <iostream>
#include <conio.h>
#include <stdlib.h>

#include "product.h"
#include "order.h"

using namespace std;

void logout(string userType);
int Login();
void loginMenu();
void displayMenu();
void searchMenu(string userType);


class mainmenu{
private:
public:

    pLinkedList pLst;
    oLinkedList oLst;

    string static userTypeNav(string userType){
        if (userType == "Admin") {
            return "\tORDER MANAGEMENT"
                   "\n\t [1] Obtain Purchase/Order Data\n\t [2] Create Orders\n\t [3] View Orders\n\t [4] Update Orders\n\n\t"
                   "PRODUCT MANAGEMENT"
                   "\n\t [5] Insert Products\n\t [6] View Products\n\t [7] Update Products\n\n\t"
                   " [8] Generate Report\n\t ";
        } else {
            return "\tORDER MANAGEMENT"
                   "\n\t [1] Obtain Purchase/Order Data\n\t [2] View Orders\n\t [3] Update Orders\n\n\t"
                   "PRODUCT MANAGEMENT"
                   "\n\t [4] View Products\n\t [5] Update Products\n\n\t ";
        }
    }

    string static userTypeName(string userType){
        if (userType == "Admin") {
            return "*                                   LiveOrder IT Online Store Admin Menu                                              *";
        } else {
            return "*                           LiveOrder IT Online Store Sales Order Executive Menu                                      *";
        }
    }

    string static userNavChoice(string userType){
        if (userType == "Admin") {
            return "\t ENTER YOUR CHOICE [1/2/3/4/5/6/7/8/9/0]: ";
        } else {
            return "\t ENTER YOUR CHOICE [1/2/3/4/5/6/7/9/0]: ";
        }
    }

    void mainPageDisplay(string userType){
        char exitOption;

        cout << "***********************************************************************************************************************" << endl;
        cout << "*                                                                                                                     *" << endl;
        cout << "*                                                                                                                     *" << endl;
        cout << userTypeName(userType) << endl;
        cout << "*                                                                                                                     *" << endl;
        cout << "*                                                                                                                     *" << endl;
        cout << "***********************************************************************************************************************" << endl << endl;
        cout << userTypeNav(userType)<< "[9] Search\n\t [0] Logout" << endl << endl;
        cout << userNavChoice(userType);
        mainNavigation(userType);
    }

    void mainNavigation(string userType){
        int userOption = 0;
        cin >> userOption;
        if (cin.fail()) { // To Validate user input that is supposed to be for int value type input
            cin.clear();
            cin.ignore();
            userOption = 6969;
        }
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (userType == "Admin") {
            switch (userOption)
            {
                case 0:
                    logout(userType);
                    break;
                case 1:
                    obtainOrders(userType);
                    break;
                case 2:
                    createOrderMenu(userType);
                    break;
                case 3:
                    displayOrder(userType);
                    break;
                case 4:
                    updateOrder(userType);
                    break;
                case 5:
                    insertProductMenu(userType);
                    break;
                case 6:
                    displayProduct(userType);
                    break;
                case 7:
                    updateProduct(userType);
                    break;
                case 8:
                    generateReport(userType);
                    break;
                case 9:
                    searchMenu(userType);
                    break;
                default:
                    cout << "\n\tPlease choose between 1-9 only" << endl;
                    mainPageDisplay(userType);
            }
        } else {
            switch (userOption)
            {
                case 0:
                    logout(userType);
                    break;
                case 1:
                    obtainOrders(userType);
                    break;
                case 2:
                    displayOrder(userType);
                    break;
                case 3:
                    updateOrder(userType);
                    break;
                case 4:
                    displayProduct(userType);
                    break;
                case 5:
                    updateProduct(userType);
                    break;
                case 9:
                    searchMenu(userType);
                    break;
                default:
                    cout << "\n\tPlease choose between 1/2/3/4/5/9/0 only" << endl;
                    mainPageDisplay(userType);
            }
        }

    }

    void loginMenu(){
        int userOption = 0;
        int menuOption = 0;
        string exitOption;

        cout << endl;
        cout << "***********************************************************************************************************************" << endl;
        cout << "*                                                                                                                     *" << endl;
        cout << "*                                                                                                                     *" << endl;
        cout << "*                                         LiveOrder IT Online Store                                                   *" << endl;
        cout << "*                                                                                                                     *" << endl;
        cout << "*                                                                                                                     *" << endl;
        cout << "***********************************************************************************************************************" << endl << endl;
        cout << "\t [1] Login\n\t [0] EXIT" << endl << endl;
        cout << "\t ENTER YOUR CHOICE [1/0]: ";
        cin >> userOption;
        if (cin.fail()) { // To Validate user input that is supposed to be for int value type input
            cin.clear();
            cin.ignore();
            userOption = 6969;
        }
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (userOption)
        {
            case 1:
                Login();
                break;
            case 0:
                cout << "\n\tProgram terminating. Are you sure? (Y/N): ";
                cin >> exitOption;
                if (cin.fail()) { // To Validate user input that is supposed to be for int value type input
                    cin.clear();
                    cin.ignore();
                    userOption = 6969;
                }
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                if (exitOption == "y" || exitOption == "Y") {

                } else if (exitOption == "n" || exitOption == "N") {
                    loginMenu();
                } else {
                    cout << "\n\tPlease choose between 'Y' or 'N' only" << endl;
                    loginMenu();
                }
                break;
            default:
                cout << "\n\tPlease choose between 1/0 only" << endl;
//                system("pause");
                loginMenu();
                break;
        }

    }

    void obtainOrders(string userType){
        int userOption = 0;
        char exitOption;
        cout << endl;
        cout << "***********************************************************************************************************************" << endl;
        cout << "*                                                                                                                     *" << endl;
        cout << "*                                                                                                                     *" << endl;
        cout << "*                                  Order List Has Been Retrieved From Online Database!                                *" << endl;
        cout << "*                                                                                                                     *" << endl;
        cout << "*                                                                                                                     *" << endl;
        cout << "***********************************************************************************************************************" << endl << endl;
        cout << "\t [1] EXIT" << endl << endl;
        cout << "\t ENTER YOUR CHOICE [1]: ";

        pLst.insertAtEnd("P003", "Supra QuadCopter", "Amazon", "Drone", "17/7/2022", 69, 200.0);
        pLst.insertAtEnd("P001", "64GB Cruzer Pendrive", "Kingston", "Storage Device", "17/7/2022", 57, 32.0);
        pLst.insertAtEnd("P005", "Ipad Mini", "Apple", "Tablet", "17/7/2022", 69, 2000.0);
        pLst.insertAtEnd("P002", "IPhone 69", "Apple", "Phone", "17/7/2022", 20, 690.5);
        pLst.insertAtEnd("P004", "Flamethrower", "Boring Company", "Cooking", "17/7/2022", 5, 420.5);

        oLst.deleteAll();
        oLst.insertAtEnd("R004", "P004", "17/7/2022", 5, 2102.5);
        oLst.insertAtEnd("R005", "P001", "18/7/2022", 3, 96.0);
        oLst.insertAtEnd("R001", "P002", "14/7/2022", 2, 1381.0);
        oLst.insertAtEnd("R003", "P002", "15/7/2022", 3, 2071.5);
        oLst.insertAtEnd("R002", "P005", "16/7/2022", 1, 2000.0);

        cin >> userOption;
        if (cin.fail()) { // To Validate user input that is supposed to be for int value type input
            cin.clear();
            cin.ignore();
            userOption = 6969;
        }
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        switch (userOption)
        {
            case 1:
                mainPageDisplay(userType);
                break;
            default:
                cout << "\n\tERROR WARNING! Dude, Just Pick 1! :^(" << endl;
                obtainOrders(userType);
                break;
        }

    }

    void createOrderMenu(string userType){
        int userOption = 0, selectQuantity;
        string searchKey, selectPID, cont;
        bool PIDstatus = false, quantityStatus = false, exitStatus = false;
        int searchNKey;
        char exitOption;
        cout << endl;
        cout << "***********************************************************************************************************************" << endl;
        cout << "*                                                                                                                     *" << endl;
        cout << "*                                                                                                                     *" << endl;
        cout << "*                                   LiveOrder IT Online Store Create New Order                                        *" << endl;
        cout << "*                                                                                                                     *" << endl;
        cout << "*                                                                                                                     *" << endl;
        cout << "***********************************************************************************************************************" << endl << endl;

        while (PIDstatus == false){
            cout << "\t ENTER PRODUCT ID: ";
            cin >> selectPID;
            PIDstatus = pLst.getProdID(selectPID);
            if(selectPID == "0"){
                quantityStatus = true;
                PIDstatus = true;
            } else if (PIDstatus == false){
                cout << "\n\t PRODUCT ID NOT FOUND! PLEASE TRY AGAIN!";
            } else{

            }

        }
        while (quantityStatus == false){
            cout << "\t ENTER PRODUCT QUANTITY: ";
            cin >> selectQuantity;
            PIDstatus = pLst.getProdQuantity(selectPID, selectQuantity);

            if (PIDstatus == false || selectQuantity < 0) {
                cout << "\n\t PRODUCT QUANTITY INVALID! PRODUCT HAS TO BE IN STOCK AND MORE THAN 0. \n\t Enter 0 to cancel. ";
            } else if (selectQuantity == 0) {
                quantityStatus = true;
                exitStatus = true;
            } else {
                quantityStatus = true;
            }
        }

        if (exitStatus == false) {
            oLst.createOrder(selectPID, selectQuantity, pLst.calcTotal(selectPID, selectQuantity));
            cout << "\n\t ORDER SUCCESSFULLY CREATED. ENTER ANY VALUE TO CONTINUE." << endl;
            cin >> cont;
        }


        mainPageDisplay(userType);
    }

    void insertProductMenu(string userType){
        int userOption = 0, selectQuantity, cont;
        string searchKey, selectPID;
        bool PIDstatus = false, quantityStatus = false, exitStatus = false;
        int searchNKey;
        char exitOption;
        cout << endl;
        cout << "***********************************************************************************************************************" << endl;
        cout << "*                                                                                                                     *" << endl;
        cout << "*                                                                                                                     *" << endl;
        cout << "*                                   LiveOrder IT Online Store Insert New Product                                      *" << endl;
        cout << "*                                                                                                                     *" << endl;
        cout << "*                                                                                                                     *" << endl;
        cout << "***********************************************************************************************************************" << endl << endl;

        pLst.insertProduct();

        cout << "\n New Product Inserted! Do you want insert another product? \n\t [1] Yes \n\t [ANY] No \n\n\t ENTER CHOICE[1/ANY] : \n";
        cin >> cont;
        if (cin.fail()) { // To Validate user input that is supposed to be for int value type input
            cin.clear();
            cin.ignore();
            cont = 0;
        }
        if (cont == 1) {
            insertProductMenu(userType);
        } else {
            mainPageDisplay(userType);
        }

    }

    void displayOrder(string userType){
        cout << endl;
        cout << "***********************************************************************************************************************" << endl;
        cout << "*                                                                                                                     *" << endl;
        cout << "*                                                                                                                     *" << endl;
        cout << "*                                     LiveOrder IT Online Store Order List                                            *" << endl;
        cout << "*                                                                                                                     *" << endl;
        cout << "*                                                                                                                     *" << endl;
        cout << "***********************************************************************************************************************" << endl << endl;
        afterdisplay(userType);

    }

    void afterdisplay(string userType){
        int userOption, userOption2 = 0;

        cout << "\n\t [1] Sort By Order ID \t [2] Sort by Purchased Quantity \t [ANY] Default Sorting" << endl << endl;
        cout << "\t ENTER YOUR CHOICE [1/2/ANY]: ";
        cin >> userOption;
        if (cin.fail()) { // To Validate user input that is supposed to be for int value type input
            cin.clear();
            cin.ignore();
            userOption = 6969;
        }
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << endl << "____________________________________________";
        cout << "\n\t ORDER LIST BY..." << endl;
        cout << "\n\t [1] Ascending Order? \t [2] Descending Order? \t [3] RETURN" << endl << endl;
        cout << "\t ENTER YOUR CHOICE [1/2/3]: ";

        cin >> userOption2;
        if (cin.fail()) { // To Validate user input that is supposed to be for int value type input
            cin.clear();
            cin.ignore();
            userOption2 = 6969;
        }
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << endl;

            switch (userOption2)
            {
                case 1:
                    oLst.selectionSort(userOption, "asc");
                    oLst.show();
                    afterdisplay(userType);
                    break;
                case 2:
                    oLst.selectionSort(userOption, "des");
                    oLst.show();
                    afterdisplay(userType);
                    break;
                case 3:
                    mainPageDisplay(userType);
                    break;
                default:
                    cout << "\n\tERROR WARNING! Please Choose Between 1/2/3 only! :^(" << endl;
                    displayOrder(userType);
                    break;
            }
    }

    void displayProduct(string userType){
        cout << endl;
        cout << "***********************************************************************************************************************" << endl;
        cout << "*                                                                                                                     *" << endl;
        cout << "*                                                                                                                     *" << endl;
        cout << "*                                     LiveOrder IT Online Store Product List                                          *" << endl;
        cout << "*                                                                                                                     *" << endl;
        cout << "*                                                                                                                     *" << endl;
        cout << "***********************************************************************************************************************" << endl << endl;
        afterDisplayProduct(userType);

    }

    void afterDisplayProduct(string userType){
        int userOption, userOption2 = 0;

        cout << "\n\t [1] Sort By Product ID \t [2] Sort by Quantity \t [ANY] Default Sorting" << endl << endl;
        cout << "\t ENTER YOUR CHOICE [1/2/ANY]: ";
        cin >> userOption;
        if (cin.fail()) { // To Validate user input that is supposed to be for int value type input
            cin.clear();
            cin.ignore();
            userOption = 6969;
        }
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << endl << "____________________________________________";
        cout << "\n\t ORDER LIST BY..." << endl;
        cout << "\n\t [1] Ascending Order? \t [2] Descending Order? \t [3] RETURN" << endl << endl;
        cout << "\t ENTER YOUR CHOICE [1/2/3]: ";

        cin >> userOption2;
        if (cin.fail()) { // To Validate user input that is supposed to be for int value type input
            cin.clear();
            cin.ignore();
            userOption2 = 6969;
        }
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << endl;

        switch (userOption2)
        {
            case 1:
                pLst.selectionSort(userOption, "asc");
                pLst.show();
                afterDisplayProduct(userType);
                break;
            case 2:
                pLst.selectionSort(userOption, "des");
                pLst.show();
                afterDisplayProduct(userType);
                break;
            case 3:
                mainPageDisplay(userType);
                break;
            default:
                cout << "\n\tERROR WARNING! Please Choose Between 1/2/3 only! :^(" << endl;
                displayProduct(userType);
                break;
        }
    }

    void updateOrder(string userType){
        string userOption;

        char exitOption;
        cout << endl;
        cout << "***********************************************************************************************************************" << endl;
        cout << "*                                                                                                                     *" << endl;
        cout << "*                                                                                                                     *" << endl;
        cout << "*                                     Insert an Order ID To Update Details                                            *" << endl;
        cout << "*                                                                                                                     *" << endl;
        cout << "*                                                                                                                     *" << endl;
        cout << "***********************************************************************************************************************" << endl << endl;
        cout << "\t [****] Order ID \n\t [1] Return" << endl << endl;
        cout << "\t PROVIDE ORDER ID OR ENTER 1 TO RETURN : ";
        cin >> userOption;
        if (cin.fail()) { // To Validate user input that is supposed to be for int value type input
            cin.clear();
            cin.ignore();
            userOption = 6969;
        }
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (userOption == "1"){
            mainPageDisplay(userType);
        } else {
            oLst.update(userOption, userType);
            updateOrder(userType);

        }


    }

    void updateProduct(string userType){
        string userOption;

        char exitOption;
        cout << endl;
        cout << "***********************************************************************************************************************" << endl;
        cout << "*                                                                                                                     *" << endl;
        cout << "*                                                                                                                     *" << endl;
        cout << "*                                     Insert an Product ID To Update Details                                          *" << endl;
        cout << "*                                                                                                                     *" << endl;
        cout << "*                                                                                                                     *" << endl;
        cout << "***********************************************************************************************************************" << endl << endl;
        cout << "\t [****] Product ID \n\t [1] Return" << endl << endl;
        cout << "\t PROVIDE PRODUCT ID OR ENTER 1 TO RETURN : ";
        cin >> userOption;
        if (cin.fail()) { // To Validate user input that is supposed to be for int value type input
            cin.clear();
            cin.ignore();
            userOption = 6969;
        }
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (userOption == "1"){
            mainPageDisplay(userType);
        } else {
            pLst.update(userOption, userType);
            updateProduct(userType);

        }


    }

    void searchMenu(string userType){
        int userOption = 0;
        string searchKey;
        int searchNKey;
        char exitOption;
        cout << endl;
        cout << "***********************************************************************************************************************" << endl;
        cout << "*                                                                                                                     *" << endl;
        cout << "*                                                                                                                     *" << endl;
        cout << "*                          Please Choose Which Type of Data You Would Like To Search For?                             *" << endl;
        cout << "*                                                                                                                     *" << endl;
        cout << "*                                                                                                                     *" << endl;
        cout << "***********************************************************************************************************************" << endl << endl;
        cout << "\t [1] Order ID \n\t [2] Product ID \n\t [3] Product Stock \n\t [4] EXIT" << endl << endl;
        cout << "\t ENTER YOUR CHOICE [1/2/3/4]: ";

        cin >> userOption;
        if (cin.fail()) { // To Validate user input that is supposed to be for int value type input
            cin.clear();
            cin.ignore();
            userOption = 6969;
        }
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (userOption)
        {
            case 1:
                cout << "\n\t ENTER ORDER ID TO SEARCH:  ";
                oLst.searchID();
                break;
            case 2:
                cout << "\n\t ENTER PRODUCT ID TO SEARCH:  ";
                pLst.searchPID();
                break;
            case 3:
                cout << "\n\t ENTER PRODUCT STOCK TO SEARCH:  ";
                pLst.searchPStock();
                break;
            case 4:
                mainPageDisplay(userType);
                break;
            default:
                cout << "\n\tERROR WARNING! Please Choose Between 1/2/3 only! :^(" << endl;
                searchMenu(userType);
                break;
        }
        cout << "\n\t TRY AGAIN? ";
        cout << "\n\t [1] Yes \n\t [2] No" << endl << endl;
        cout << "\t ENTER YOUR CHOICE [1/2]: ";

        cin >> userOption;
        if (cin.fail()) { // To Validate user input that is supposed to be for int value type input
            cin.clear();
            cin.ignore();
            userOption = 6969;
        }
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (userOption)
        {
            case 1:
                searchMenu(userType);
                break;
            case 2:
                mainPageDisplay(userType);
                break;
            default:
                cout << "\n\tERROR WARNING! Please Choose Between 1/2 only! :^(" << endl;
                searchMenu(userType);
                break;
        }

    }

    void generateReport(string userType){
        int userOption, userOption2 = 0;
        cout << endl;
        cout << "***********************************************************************************************************************" << endl;
        cout << "*                                                                                                                     *" << endl;
        cout << "*                                                                                                                     *" << endl;
        cout << "*                                LiveOrder IT Online Store Summary Report Generator                                   *" << endl;
        cout << "*                                                                                                                     *" << endl;
        cout << "*                                                                                                                     *" << endl;
        cout << "***********************************************************************************************************************" << endl << endl;
        cout << "\t [1] Sort By Order ID \t [2] Sort by Purchased Quantity \t [ANY] Default Sorting" << endl << endl;
        cout << "\t ENTER YOUR CHOICE [1/2/ANY]: ";

        cin >> userOption;
        if (cin.fail()) { // To Validate user input that is supposed to be for int value type input
            cin.clear();
            cin.ignore();
            userOption = 6969;
        }
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        cout << endl << "____________________________________________";
        cout << "\n\t ORDER LIST BY..." << endl;
        cout << "\n\t [1] Ascending Order? \t [2] Descending Order? \t [3] RETURN" << endl << endl;
        cout << "\t ENTER YOUR CHOICE [1/2/3]: ";

        cin >> userOption2;
        if (cin.fail()) { // To Validate user input that is supposed to be for int value type input
            cin.clear();
            cin.ignore();
            userOption2 = 6969;
        }
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << endl;

        switch (userOption2)
        {
            case 1:
                oLst.selectionSort(userOption, "asc");
                oLst.createReport();
                cout << "\n\t Press 'Enter' To Return To The Main Menu" << endl;
                getchar();
                mainPageDisplay(userType);
                break;
            case 2:
                oLst.selectionSort(userOption, "des");
                oLst.createReport();
                cout << "\n\t Press 'Enter' To Return To The Main Menu" << endl;
                getchar();
                mainPageDisplay(userType);
                break;
            case 3:
                mainPageDisplay(userType);
                break;
            default:
                cout << "\n\tERROR WARNING! Please Choose Between 1/2/3 only! :^(" << endl;
                generateReport(userType);
                break;
        }
    }
};


