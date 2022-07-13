#include <iostream>
#include <conio.h>
#include <limits>
using namespace std;


void Login();
//void userData ();



struct USERS{
    string uID, uRole, uName, uGender, uEmail, uContactNumber, uAddress, uPassword;
    int uAge ;
    USERS *nextUSer;
} ;

USERS mUsers[4];


int main()
{
    //variables
    int userOption = 0;
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
//mUsers[0] = "testt";

//void USERS::userData (){
    //string uID, uRole, uName, uGender, uEmail, uContactNumber, uAddress, uPassword;
  //  int uAge ;
   // USERS *nextUSer;

   // USERS mainUser[5];

//}


void Login (){

    system("CLS");

    mUsers[0].uID = "SOE0001";
    mUsers[0].uRole = "Sales Order Executive";
    mUsers[0].uName = "Muhammad Faris";
    mUsers[0].uGender = "Male";
    mUsers[0].uEmail = "faris01@gmail.com";
    mUsers[0].uContactNumber = "012-6763829";
    mUsers[0].uAddress = "Kuala Lumpur, Malaysia";
    mUsers[0].uPassword = "test";
    mUsers[0].uAge = 20;

    mUsers[1].uID = "AD0002";
    mUsers[1].uPassword = "TeSt";
    mUsers[1].uRole = "Admin";
    //string uID, uRole, uName, uGender, uEmail, uContactNumber, uAddress, uPassword;
   // int uAge ;
    //USERS *nextUSer;

   // USERS mainUser[5];

  //  mainUser[0].uID = "SOE0001";
   // mainUser[0].uRole = "Sales Order Executive";
   // mainUser[0].uName = "Muhammad Faris";
   // mainUser[0].uGender = "Male";
   // mainUser[0].uEmail = "faris01@gmail.com";
   // mainUser[0].uPassword = "test";
   // mainUser[0].uName = "kaki";

 //   mainUser[1].uID = "SOE0002";
 //   mainUser[1].uPassword = "TeSt";

    //mainuser.uID [5] = {"SOE0001", "SOE0002", "SOE0003"};
    //mainuser.uPassword =  {"tes", "test"};
   // mainuser.uName = {"danish", "faris"};
    string userID, userPassword;



    cout << "\t User ID: ";
    //cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin >> userID;
    //getline(cin, userID);
    //getline(cin, userID);
   // userID = "";
    cout << "\tPassword : ";
    cin >> userPassword;
    //userPassword = "";

    //char ps = _getch();
  // while (ps != 13)
    //{
    //    userPassword.push_back(ps);
      //  cout << '*';
       // ps = _getch();
   // }
   // cin >> userID;
   // cout << "\tUser Password: ";
    //cin >> userPassword;

    for (int i=0; i<=4; i++) {
        if (userID == mUsers[i].uID && userPassword == mUsers[i].uPassword && mUsers[i].uRole == "Sales Order Executive") {
            cout << "***Log In Successful***\n\n";
            cout << "\n\t    WELCOME Sales Order Executive" << "\t" << mUsers[i].uName << "\n\t" << endl;
            getch();
            // goto endofadminlogin;
        } else if (userID == mUsers[i].uID && userPassword == mUsers[i].uPassword && mUsers[i].uRole == "Admin") {
            cout << "***Log In Successful***\n\n";
            cout << "\n\t    WELCOME Admin" << "\t" << mUsers[i].uName << "\n\t" << endl;
        }

    }
}

