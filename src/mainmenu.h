//
// Created by User on 13/7/2022.
//
#include <iostream>
#include <conio.h>

using namespace std;


class mainmenu{
private:
public:
    int SOEmenu(){
        int userOption = 0;
        char exitOption;

        cout << "***********************************************************************************************************************" << endl;
        cout << "*                                                                                                                     *" << endl;
        cout << "*                                                                                                                     *" << endl;
        cout << "*                           LiveOrder IT Online Store Sales Order Executive Menu                                      *" << endl;
        cout << "*                                                                                                                     *" << endl;
        cout << "*                                                                                                                     *" << endl;
        cout << "***********************************************************************************************************************" << endl << endl;
        cout << "\t [1] Obtain Purchase Orders\n\t [2] View Orders\n\t [3] Modify Orders\n\t [4] Search Orders\n\t [5] Logout" << endl << endl;
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

       return 0;
    }
    int Adminmenu(){
        int userOption = 0;
        char exitOption;

        cout << "***********************************************************************************************************************" << endl;
        cout << "*                                                                                                                     *" << endl;
        cout << "*                                                                                                                     *" << endl;
        cout << "*                           LiveOrder IT Online Store Admin Menu                                                      *" << endl;
        cout << "*                                                                                                                     *" << endl;
        cout << "*                                                                                                                     *" << endl;
        cout << "***********************************************************************************************************************" << endl << endl;
        cout << "\t [1] Obtain Purchase Orders\n\t [2] View Orders\n\t [3] Modify Orders\n\t [4] Search Orders\n\t [5] Generate Report \n\t [6] Logout" << endl << endl;
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
                    return 0;
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

        return 0;
    }
};




