//
// Created by User on 16/7/2022.
//

#include <iostream>
#include <conio.h>
#include <stdlib.h>

//#include "userLogin.h";
using namespace std;
int logout();
int Login();
void displayMenu();
void searchMenu();

class mainmenu{
private:
public:
    void SOEmenu(){


        int userOption = 0;
        char exitOption;


        cout << "***********************************************************************************************************************" << endl;
        cout << "*                                                                                                                     *" << endl;
        cout << "*                                                                                                                     *" << endl;
        cout << "*                           LiveOrder IT Online Store Sales Order Executive Menu                                      *" << endl;
        cout << "*                                                                                                                     *" << endl;
        cout << "*                                                                                                                     *" << endl;
        cout << "***********************************************************************************************************************" << endl << endl;
        cout << "\t [1] Obtain Purchase/Order Data\n\t [2] View Orders\n\t [3] Modify Orders\n\t [4] Search Orders\n\t [5] Logout" << endl << endl;
        cout << "\t ENTER YOUR CHOICE [1/2/3/4/5]: ";
        cin >> userOption;
        switch (userOption)
        {
            case 1:
                displayMenu();
                break;
            case 2:
                //displayOrder();
                break;
            case 3:
                //updateOrder();
                break;
            case 4:
                searchMenu();
                break;
            case 5:
                logout();
                break;
        }

        // return 0;
    }
    void Adminmenu(){
        int userOption = 0;
        char exitOption;

        cout << "***********************************************************************************************************************" << endl;
        cout << "*                                                                                                                     *" << endl;
        cout << "*                                                                                                                     *" << endl;
        cout << "*                           LiveOrder IT Online Store Admin Menu                                                      *" << endl;
        cout << "*                                                                                                                     *" << endl;
        cout << "*                                                                                                                     *" << endl;
        cout << "***********************************************************************************************************************" << endl << endl;
        cout << "\t [1] Obtain Purchase/Order Data\n\t [2] View Orders\n\t [3] Modify Orders\n\t [4] Search Orders\n\t [5] Generate Report \n\t [6] Logout" << endl << endl;
        cout << "\t ENTER YOUR CHOICE [1/2/3/4/5]: ";
        cin >> userOption;
        switch (userOption)
        {
            case 1:
                //refreshDetails();
                break;
            case 2:
                //displayOrder();
                break;
            case 3:
                //updateOrder();
                break;
            case 4:
                //searchOrder();
                break;
            case 5:
                //produceReport();
                break;
            case 6:
            ExitProgram:
                cout << "\n\tProgram terminating. Are you sure? (Y/N): ";
                cin >> exitOption;
                if (exitOption == 'y' || exitOption == 'Y')
                {
                    // return 0;
                }
                else if (exitOption == 'n' || exitOption == 'N')
                {
                    system("cls");
                    SOEmenu();
                }
                else
                {
                    cout << "Please enter the correct input only" << endl;
                    system("pause");
                    goto ExitProgram;
                }
                break;
            default:

                cout << "\n\tPlease choose between 1-5 only" << endl;
                system("pause");
                SOEmenu();
                break;
        }

        //return 0;
    }
};

int mainPage(){
    int userOption = 0;
    int menuOption = 0;
    char exitOption;

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
    switch (userOption)
    {
        case 1:
            Login();

            break;
        case 0:
        ExitProgram:
            cout << "\n\tProgram terminating. Are you sure? (Y/N): ";
            cin >> exitOption;
            if (exitOption == 'y' || exitOption == 'Y')
            {
                return 0;
            }
            else if (exitOption == 'n' || exitOption == 'N')
            {
                system("cls");
                mainPage();
            }
            else
            {
                cout << "Please enter the correct input only" << endl;
                system("pause");
                goto ExitProgram;
            }
            break;
        default:

            cout << "\n\tPlease choose between 1/0 only" << endl;
            system("pause");
            mainPage();
            break;
    }

    return 0;
}

void displayMenu(){

        // display menu and get user choice
        int choice = 0;
        cout << "\t [1] Display Products\n\t [2] Order Products \n\t [3] Refresh Order Data \n\t [4] Display Physical Orders \n\t [5] Logout \n\t [6] Exit"<< endl << endl;
        cout << "\t ENTER YOUR CHOICE [1/2/3/4/5/6]: ";
        cin >> choice;
        cout << endl;

        switch(choice) {
            case 1:
               // displayProducts(products);
                break;
            case 2:
               // orders = buyProduct(products, orders);
                break;
            case 3:
                //displayOrders(orders);
                break;
            case 4:
                break;
            case 5:
                mainPage();
            case 6:
                exit(0);
        }

}







void searchMenu(){
    int userOption = 0;
    char exitOption;
    cout << endl;
    cout << "***********************************************************************************************************************" << endl;
    cout << "*                                                                                                                     *" << endl;
    cout << "*                                                                                                                     *" << endl;
    cout << "*                                        Please Choose Which Parameter in Searching                                   *" << endl;
    cout << "*                                                                                                                     *" << endl;
    cout << "*                                                                                                                     *" << endl;
    cout << "***********************************************************************************************************************" << endl << endl;
    cout << "\t [1] Order ID/ProductID \n\t [2] Product Quantity \n\t [3] EXIT" << endl << endl;
    cout << "\t ENTER YOUR CHOICE [1/2/3]: ";

    cin >> userOption;
    switch (userOption)
    {
        case 1:
             ;

            break;
        case 2:

            break;
        case 3:
            
        ExitProgram:
            cout << "\n\tProgram terminating. Are you sure? (Y/N): ";
            cin >> exitOption;
            if (exitOption == 'y' || exitOption == 'Y')
            {
                exit(0);
            }
            else if (exitOption == 'n' || exitOption == 'N')
            {
                system("cls");
                mainPage();
            }
            else
            {
                cout << "Please enter the correct input only" << endl;
                system("pause");
                goto ExitProgram;
            }
            break;
        default:
            cout << "\n\tPlease choose between 1/0 only" << endl;
            system("pause");
            mainPage();
            break;
    }

}
