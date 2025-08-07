#pragma once


/*
===============================================================
Name of Artifact  : Customer Class
Brief Description : Customer Object that holds customers data 
Coder Name        : Juhi 
Date              : 08/07/2025
===============================================================
*/

#include <string>
#include <vector>
using namespace std;
class customer {
private:
    int customerID; 
    string name;
    string address;

public:
    // Constructor
    customer(int newCustomerID, string newName, string newAddress);

    // Get functions
    int getCustomerID() const;
    string getName() const;
    string getAddress() const;

    // Set functions
    void setAddress(string newAddress);
    void setName(string newName);
}; 




/*
===============================================================
Name of Artifact  : Customer Controller Class
Brief Description : Holds all customers and assings unique ID's
                    to each one. Also manages customers through
                    sets and gets. Handles any algorithms that
                    are needed for the customer's data.
Coder Name        : Juhi
Date              : 08/07/2025
===============================================================
*/




class Customer_Controller_Class {
 private:
     int uniqueID = 0;
     vector<customer> customerList;
     
 public:
     // Constructor
    Customer_Controller_Class() {}

    // Setting Functions
    int addCustomer(string newName, string newAddress);                 // Makes customer object using new uniqueID
    void removeCustomer(int targetID);                                   
    void setCustomerAddress(int targetID, string newAddress);            
    void setCustomerName(int targetID, string newName);                  


    // For loading from files
    void setUniqueID(int currID) { uniqueID = currID; }
    void setCustomerList(vector<customer> newCustomersList) { customerList = newCustomersList; }
    int getUniqueID() { return uniqueID; }

    // Get Functions
    vector<customer> getCustomerList() { return customerList; }                                           // Returns a copy of the customersList
    customer getCustomer(int targetID) { customer copy = *getCustomerPointer(targetID); return copy; }    // Returns a target customer using their ID
    customer* getCustomerPointer(int targetID);                                                           // Returns a customer's address(&) by ID
};

