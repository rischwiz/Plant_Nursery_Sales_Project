#pragma once

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

    // get functions
    int getCustomerID() const;
    string getName() const;
    string getAddress() const;

    // set functions
    void setAddress(string newAddress);
    void setName(string newName);
}; 





class Customer_Controller_Class {
 private:
     int uniqueID = 0;
     vector<customer> customerList;
     
 public:
     // Constructor
    Customer_Controller_Class() {}

    // Setting Functions
    int addCustomer(string newName, string newAddress);
    void removeCustomer(int targetID);
    void setCustomerAddress(int targetID, string newAddress);
    void setCustomerName(int targetID, string newName);


    // For loading from files
    void setUniqueID(int currID) { uniqueID = currID; }
    void setCustomerList(vector<customer> newCustomersList) { customerList = newCustomersList; }
    int getUniqueID() { return uniqueID; }

    // Get Functions
    vector<customer> getCustomerList() { return customerList; }
    customer getCustomer(int targetID) { customer copy = *getCustomerPointer(targetID); return copy; }
    customer* getCustomerPointer(int targetID);

};

