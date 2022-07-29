// Including various C++ packages and libraries
#include <iostream>
#include <conio.h>
#include <limits>
#include <stdlib.h>

// Including external header files
#include "userLogin.h"

using namespace std;

// Function to start the program
int start(){

    int userOption; // Variable to store user selection input

    // Display menu as text and options as text
    cout << "\n***********************************************************************************************************************" << endl;
    cout << "***********************************************************************************************************************" << endl;
    cout << "***********************************************************************************************************************" << endl;
    cout << "*                                     Do you want to start the application?                                           *" << endl;
    cout << "***********************************************************************************************************************" << endl;
    cout << "***********************************************************************************************************************" << endl;
    cout << "***********************************************************************************************************************" << endl << endl;
    cout << "\t [1] Start\n\t [0] EXIT" << endl << endl;
    cout << "\t ENTER YOUR CHOICE [1/0]: ";
    cin >> userOption;

    // To Validate user input that is supposed to be for int input
    // Ex: Input only accepts numbers, string values wll reset the input to another to avoid error
    if (cin.fail()) { //
        cin.clear();
        cin.ignore();
        userOption = 6969;
    }

    cout << endl;

    // To handle user choice and display the next option
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
                start();
            }
            else
            {
                cout << "ERROR: Please enter either 'Y' or 'N' only" << endl;
                start();
            }

            break;
        default:
            system("cls");
            cout << "\n\tPlease choose between 1/0 only!" << endl;
            start();
            break;
    }
}
int main()
{
    start();     // Function to start the application
    return 0;
}