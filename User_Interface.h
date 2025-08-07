#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <sstream>
#include "Staff_Controller_Class.h"
#include "Species_Controller_Class.h"
#include "Sales_Controller_Class.h"
#include "Cutomer_Controller_Class.h"

using namespace std;

/*
===============================================================
Name of Artifact  : User Interface Class
Brief Description : This class is the user interface for the application. 
                    It handles all user interactions, including displaying menus, getting user input, 
                    and calling the appropriate functions from the controllers.
Coder Name        : Richard
Date              : 08/05/2025
===============================================================
*/
class User_Interface
{

private:
	int getUserInput(string menu, int maxOptions); // Function to get user input and validate it against the menu options
	Staff_Controller_Class    workers; // Declares an instance of the Staff_Controller_Class
	Species_Controller_Class  inventory; // Declares an instance of the Species_Controller_Class
	Sales_Controller_Class    transactions; // Declares an instance of the Sales_Controller_Class
	Customer_Controller_Class clients; // Declares an instance of the Customer_Controller_Class
	const string staffFile = "staff.txt"; // Constants for staff file name
	const string speciesFile = "species.txt"; // Constants for species file name
	const string salesFile = "sales.txt"; // Constants for sales file name
	const string customersFile = "customers.txt"; // Constants for customers file name

	// Menu Strings
    string managerMenu =
        "           Manager Menu           \n"
        "----------------------------------\n"
        "1) Look at inventory\n"
        "2) Add Sale\n"
        "3) Add Species\n"
        "4) Remove species(without a sale)\n"
        "5) Generate Report\n"
        "6) Add / remove staff\n"
        "7) Edit Staff\n"
        "8) Exit\n"
        "----------------------------------\n";

    string staffMenu =
        "             Staff Menu           \n"
        "----------------------------------\n"
        "1) Look at inventory\n"
        "2) Add Sale\n"
        "3) Add Species\n"
        "4) Remove species(without  sale)\n"
        "5) Exit\n"
        "----------------------------------\n";

    string addEditStaff =
        "----------------------------------\n"
        "1) Add Staff\n"
        "2) Remove Staff\n"
        "3) Cancel\n"
        "----------------------------------\n";

    string report =
        "----------------------------------\n"
        "1) Day\n"
        "2) Month\n"
        "3) Year\n"
        "4) Exit\n"
        "----------------------------------\n";

public:  

    // Constructor: reads from files or makes files if there are none already made
    User_Interface();

    // Saves the files, should be called anywhere we make changes
    void save();


    // Helper Functions
    void cls(); //Function to clear the screeen
    void line(); // Prints out a line
    void pause(); //Function to wait for user before conitnuing
    bool safeConvertToInt(string& targetString, int& targetInt); //Function will convert the string to integer
    bool safeConvertToDouble(string& targetString, double& targetInt); //Function will convert the string to integer
    int checkCredentials(string usernameAttempt, string passwordAttempt); //Checks Username and Password 


    // UI's:
    void staffUI();
    void managerUI();
    void setUser(string username);
    int currentUser = 0;


    // Menus
    const int managerOptions = 8;
    const int staffOptions = 5;
    const int reportOptions = 4;
    const int addEditStaffOptions = 3;

    

    // Species Control Functions:
    void displayInventory();  // completed
    void addSpecies();         // completed
    void removeSpecies();      // completed

    // Staff Control Functions:
    void addStaff();          // completed
    void removeStaff();       // completed
    void editStaff();        // completed
        
    // Customer Control Functions
    int addCustomer(); // completed

    // Sales Control Functions
    void addSale();        // compelte
    void removeSale();        // compelted
    void generateReport(); // compelted


    // First time logging in, one manager has to be made
    void makeManager();

};







/*We need 3 different User Interfaces depending on if the user is a customer/staff/admin
        when the application boots up, you can select what type of user you are
        
        -> customer: can see a list of the inventory of all the plant species 

        -> staff: will ask which option the user wants. 
                1) Look at inventory
                2) Add Sale
                3) Add Species
                4) Partially remove species?
                
        -> Admin: Will also ask which option the user wants.
                1) Look at inventory
                2) Add Sale
                3) Add Species
                4) remove species (without a sale)
                5) Generate Report
                6) add/remove staff
                7) edit Staff
    */
