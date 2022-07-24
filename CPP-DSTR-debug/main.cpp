#include <iostream>
#include <conio.h>
#include <limits>
#include <stdlib.h>
#include "userLogin.h"
using namespace std;

void loginMenu();

int start(){

    int userOption;
    string exitOption;

    cout << "***********************************************************************************************************************" << endl;
    cout << "***********************************************************************************************************************" << endl;
    cout << "***********************************************************************************************************************" << endl;
    cout << "*                                     Do you want to start the application?                                           *" << endl;
    cout << "***********************************************************************************************************************" << endl;
    cout << "***********************************************************************************************************************" << endl;
    cout << "***********************************************************************************************************************" << endl << endl;
    cout << "\t [1] Start\n\t [0] EXIT" << endl << endl;
    cout << "\t ENTER YOUR CHOICE [1/0]: ";
    cin >> userOption;

    if (cin.fail()) { // To Validate user input that is supposed to be for int value type input
        cin.clear();
        cin.ignore();
        userOption = 6969;
    }
//    cin.clear();
//    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    cout << endl;
    switch (userOption)
    {
        case 1:
            mm.loginMenu();
            break;
        case 0:
            char exitOption;
            cout << "\n\tProgram terminating. Are you sure? (Y/N): ";
            cin >> exitOption;
            if (exitOption == 'y' || exitOption == 'Y')
            {
                return 0;
            }
            else if (exitOption == 'n' || exitOption == 'N')
            {
//                system("cls");
                start();
            }
            else
            {
                cout << "ERROR: Please enter either 'Y' or 'N' only" << endl;
                start();
            }

            break;
        default:
//            system("cls");
            cout << "\n\tPlease choose between 1/0 only!" << endl;
            start();
            break;
    }
}
int main()
{
    start();
    return 0;
}