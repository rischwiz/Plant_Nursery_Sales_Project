#include <iostream>
#include <string>
#include "User_Interface.h"


using namespace std;

// testing this here this is better idk 

int main()
{
    User_Interface mainUI; 
    while (true) {  
        mainUI.cls();
        //Ask to see what type of user is using the application
        mainUI.line();
        cout << "1. Customer" << endl;
        cout << "2. Staff" << endl;
        mainUI.line();
        cout << "> ";
        

        string tempString;
        int tempInt;
        getline(cin, tempString);
        
         //if user did not input value integer it will run through the loop again
        if (!mainUI.safeConvertToInt(tempString, tempInt)) {
            continue;
        }
        if (tempInt <= 0 || tempInt >= 4)
            continue;


        if (tempInt == 1) {
            mainUI.displayInventory();
            mainUI.pause();
            continue;
        }
        
        //We need to check credntials to see if the user has a valid username and password if they are a staff or adminntials to see if the user has a valid username and password if they are a staff or admin        
        mainUI.cls();
        string username, password;        

        cout << "Please Enter Credentials" << endl;
        cout << "Username: ";
        getline(cin, username);
        
        cout << "Password: ";
        getline(cin, password);

        int accountType = mainUI.checkCredentials(username, password); //0 = failed, 1=staff, 2=manager

        if (accountType == 0) {
            mainUI.cls();
            cout << "Invalid Username/Password. Please try again." << endl;
            mainUI.pause();
            continue;
        }

        else if (accountType == 1) {
            mainUI.setUser(username);
            mainUI.staffUI();
        }

        else if(accountType == 2){
            mainUI.setUser(username);
            mainUI.managerUI();
        }

    }
    return 0;
}