#include <iostream>
#include <conio.h>
#include <limits>
#include <stdlib.h>
#include "userLogin.h"
using namespace std;

int mainPage();


int main()
{
    //variables
    int userOption = 0;
    char exitOption;

    cout << "***********************************************************************************************************************" << endl;
    cout << "***********************************************************************************************************************" << endl;
    cout << "***********************************************************************************************************************" << endl;
    cout << "**************************************Do you want to start the application?********************************************" << endl;
    cout << "***********************************************************************************************************************" << endl;
    cout << "***********************************************************************************************************************" << endl;
    cout << "***********************************************************************************************************************" << endl << endl;
    cout << "\t [1] Start\n\t [0] EXIT" << endl << endl;
    cout << "\t ENTER YOUR CHOICE [1/0]: ";
    cin >> userOption;
    switch (userOption)
    {
        case 1:
            mainPage();
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
                main();
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
            main();
            break;
    }

    return 0;
}

