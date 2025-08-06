#include "Cutomer_Controller_Class.h"
#include <iostream> 

using namespace std; 

//Customer implementation

customer::customer(int newCustomerID, string newName, string newAddress){
    customerID = newCustomerID;
    name = newName;
    address = newAddress;
}

int customer::getCustomerID() const {
    return customerID;
}

string customer::getName() const {
    return name;
}

string customer::getAddress() const{
    return address;
}


void customer::setAddress(string newAddress){
    address = newAddress;
}

void customer::setName(string newName) {
    name = newName;
}

// customer control implementation

int Customer_Controller_Class::addCustomer(string newName, string newAddress) {
    uniqueID++;
    customer newCustomer(uniqueID, newName, newAddress);
    customerList.push_back(newCustomer);
    return uniqueID;
}


void Customer_Controller_Class::removeCustomer(int targetID) {
    for (auto it = customerList.begin(); it != customerList.end(); ++it) { // looping through all the csutomer through iter. pointer
        if (it->getCustomerID() == targetID) { // If customer id matches
            customerList.erase(it); // Removal of the customer
        }
    }
}

void Customer_Controller_Class::setCustomerAddress(int targetID, string newAddress) {
    customer* targetCustomer = getCustomerPointer(targetID);
    targetCustomer->setAddress(newAddress);
}

void Customer_Controller_Class::setCustomerName(int targetID, string newName) {
    customer* targetCustomer = getCustomerPointer(targetID);
    targetCustomer->setName(newName);
}

customer* Customer_Controller_Class::getCustomerPointer(int targetID) {
    for (auto& currCustomer : customerList) {
        if (currCustomer.getCustomerID() == targetID) {
            return &currCustomer;
        }
    }
    return nullptr; // Shouldnt't ever get here but just in case, handle the return type of the function
}
