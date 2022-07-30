// Directives usages
#ifndef LIVEORDERIT_MANAGEMENT_SYSTEM_DONUT_H
#define LIVEORDERIT_MANAGEMENT_SYSTEM_DONUT_H

// Including various C++ packages and libraries
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include "mainMenu.h"

//#include "mainmenu.h"
using namespace std;

// Retrieve mainmenu class from external header file
mainmenu mm;

// Struct for users data
struct USERS{
    string uID, uRole, uName, uGender, uEmail, uContactNumber, uAddress, uPassword;
    int uAge ;
    USERS *nextUSer;
} ;

// Set the size for mUsers array
USERS mUsers[6];

// Function for login process
int Login () {
    string userID, userPassword;
    int loginAttempt = 0;

    // User's data
    mUsers[0].uID = "SOE0001";
    mUsers[0].uRole = "Sales Order Executive";
    mUsers[0].uName = "Muhammad Faris";
    mUsers[0].uGender = "Male";
    mUsers[0].uEmail = "faris01@gmail.com";
    mUsers[0].uContactNumber = "012-6763829";
    mUsers[0].uAddress = "Kuala Lumpur, Malaysia";
    mUsers[0].uPassword = "faris222";
    mUsers[0].uAge = 20;

    mUsers[1].uID = "SOE0002";
    mUsers[1].uRole = "Sales Order Executive";
    mUsers[1].uName = "Ali Bin Abu";
    mUsers[1].uGender = "Male";
    mUsers[1].uEmail = "aliabu11@gmail.com";
    mUsers[1].uContactNumber = "012-6265429";
    mUsers[1].uAddress = "Sabah, Malaysia";
    mUsers[1].uPassword = "abuali22";
    mUsers[1].uAge = 25;

    mUsers[2].uID = "SOE0003";
    mUsers[2].uRole = "Sales Order Executive";
    mUsers[2].uName = "Aisyah Binti Bagus";
    mUsers[2].uGender = "Female";
    mUsers[2].uEmail = "ctaisyah@gmail.com";
    mUsers[2].uContactNumber = "012-0398273";
    mUsers[2].uAddress = "Perak, Malaysia";
    mUsers[2].uPassword = "aisyahbag90";
    mUsers[2].uAge = 23;

    mUsers[3].uID = "AD0001";
    mUsers[3].uRole = "Admin";
    mUsers[3].uName = "Jennie Kishanthan";
    mUsers[3].uGender = "Female";
    mUsers[3].uEmail = "kishnnie2@gmail.com";
    mUsers[3].uContactNumber = "012-0392873";
    mUsers[3].uAddress = "Kuala Lumpur, Malaysia";
    mUsers[3].uPassword = "jenniesolo";
    mUsers[3].uAge = 22;

    mUsers[4].uID = "AD0002";
    mUsers[4].uRole = "Admin";
    mUsers[4].uName = "Nuts Forger";
    mUsers[4].uGender = "Male";
    mUsers[4].uEmail = "nuttieforger2@gmail.com";
    mUsers[4].uContactNumber = "012-8372832";
    mUsers[4].uAddress = "Kelantan, Malaysia";
    mUsers[4].uPassword = "nutsfarger";
    mUsers[4].uAge = 30;

    mUsers[5].uID = "AD0003";
    mUsers[5].uRole = "Admin";
    mUsers[5].uName = "Muhammad Bemes Zafri";
    mUsers[5].uGender = "Male";
    mUsers[5].uEmail = "bemesZ4f@gmail.com";
    mUsers[5].uContactNumber = "012-0289432";
    mUsers[5].uAddress = "Kuala Lumpur, Malaysia";
    mUsers[5].uPassword = "bemeszaf";
    mUsers[5].uAge = 21;

    // User ID and Password verification process
    while (loginAttempt < 6) {
        cout << "\t  Please Login by Entering User ID and Password!\n";
        cout << "\t User ID: ";
        cin >> userID;
        cout << "\t  Password : ";
        cin >> userPassword;
        for (int i = 0; i <= 6; i++) {
            if (userID == mUsers[i].uID && userPassword == mUsers[i].uPassword &&
                mUsers[i].uRole == "Sales Order Executive") {
                cout << "\n\t\t\t\t          Log In Successful!\n";
                cout << "\n\t\t\t\tWELCOME Sales Order Executive" << " " << mUsers[i].uName << "\n\t" << endl;
                mm.mainPageDisplay("Sales Order Executive");
                return 0;

            } else if (userID == mUsers[i].uID && userPassword == mUsers[i].uPassword && mUsers[i].uRole == "Admin") {
                cout << "\n\t\t\t\t     Log In Successful!\n";
                cout << "\n\t\t\t\t    WELCOME Admin" << " " << mUsers[i].uName << "\n\t" << endl;
                mm.mainPageDisplay("Admin");
                return 0;
            }
        }
        cout << "\n\t Invalid login attempt, Incorrect Password or ID. Please try again.\n" << endl;
        loginAttempt++;
        if (loginAttempt == 6) {
            cout << "\nToo many login attempts! The program will now terminate.";
            exit(0);
        }
    }

    return 0;
    };

// Function for handling logout process
void logout(string userType){
    string exitOption = "";
    cout<< "\n______________________________________________________________" << endl;
    cout << "\n\t Are you sure you want to logout? ";
    cout << "\n\t [Y] Yes [N] No \n\t" << endl;
    cout << "\t ENTER YOUR CHOICE [Y/N]: ";
    cin >> exitOption;
    if (exitOption == "y" || exitOption == "Y") {
        mm.loginMenu();
    } else if (exitOption == "n" || exitOption == "N") {
        mm.mainPageDisplay(userType);
    } else {
        cout << endl << "ERROR: Please enter either 'Y' or 'N' only" << endl;
        logout(userType);
    }
}

#endif //LIVEORDERIT_MANAGEMENT_SYSTEM_DONUT_H
