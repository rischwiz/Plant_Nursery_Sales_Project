#include "Staff_Controller_Class.h"


/*
===============================================================
Name of Artifact  : Staff_controller_class.cpp
Brief Description : Implements the functions initialized in
					the .h file.
Coder Name        : Emanuel
Date              : 08/07/2025
===============================================================
*/



staff* Staff_Controller_Class::getStaffPointer(int targetID) { 
	staff* returningStaff = nullptr;                        // Making an empty staff pointer set to null
															 
	for (auto& currStaff : staffList) {						// Going through the entire staff list
		if (currStaff.getStaffID() == targetID) {			// If the staff ID of the staff we are looking at matches the TARGETID
			returningStaff = &currStaff;					// Then set the pointer to this staff address 
			break;											// Breakinf out of the searching for loop since we already found it to save time
		}													
	}														
															
	return returningStaff;									// Returning the staff pointer, will still be nullptr if it did not find the staff
}

void Staff_Controller_Class::addStaff(string name, string address, string phone, string email, string username, string password, double salary, bool isManager) {
	uniqueID++;																					  // Increasing to keep unique
	staff newStaff(uniqueID, name, address, phone, email, username, password, salary, isManager); // Making new object
	staffList.push_back(newStaff); 																  // Adding to the vector of all staff
}


void Staff_Controller_Class::setStaffName(int targetID, string newName) {
	staff* targetStaff = getStaffPointer(targetID); // Locating the target staff using the getStaffPointer Function
	targetStaff->setName(newName);					// Using pointer to reach the objects methods
}

void Staff_Controller_Class::setStaffAddress(int targetID, string newAddress) {
	staff* targetStaff = getStaffPointer(targetID); // Locating the target staff using the getStaffPointer Function
	targetStaff->setAddress(newAddress);			// Using pointer to reach the objects methods
}

void Staff_Controller_Class::setStaffPhone(int targetID, string newPhone) {
	staff* targetStaff = getStaffPointer(targetID); // Locating the target staff using the getStaffPointer Function
	targetStaff->setPhone(newPhone);				// Using pointer to reach the objects methods
}

void Staff_Controller_Class::setStaffEmail(int targetID, string newEmail) {
	staff* targetStaff = getStaffPointer(targetID); // Locating the target staff using the getStaffPointer Function
	targetStaff->setEmail(newEmail);				// Using pointer to reach the objects methods
}

void Staff_Controller_Class::setStaffUsername(int targetID, string newUsername) {
	staff* targetStaff = getStaffPointer(targetID); // Locating the target staff using the getStaffPointer Function
	targetStaff->setUsername(newUsername);			// Using pointer to reach the objects methods
}

void Staff_Controller_Class::setStaffPassword(int targetID, string newPassword) {
	staff* targetStaff = getStaffPointer(targetID); // Locating the target staff using the getStaffPointer Function
	targetStaff->setPassword(newPassword);			// Using pointer to reach the objects methods
}

void Staff_Controller_Class::setStaffSalary(int targetID, double newSalary) {
	staff* targetStaff = getStaffPointer(targetID); // Locating the target staff using the getStaffPointer Function
	targetStaff->setSalary(newSalary);				// Using pointer to reach the objects methods
}

void Staff_Controller_Class::setStaffIsManager(int targetID, bool newIsManager) {
	staff* targetStaff = getStaffPointer(targetID); // Locating the target staff using the getStaffPointer Function
	targetStaff->setIsManager(newIsManager);		// Using pointer to reach the objects methods
}


void Staff_Controller_Class::removeStaff(int targetID) {
	int index = 0;                                          // Keeping track of what index we are in
	for (auto& currStaff : staffList) {						// Going through the entire staff list
		if (currStaff.getStaffID() == targetID) {			// IF this staffID == the targetID
			staffList.erase(staffList.begin() + index);		// Erase it by using .erase() which uses an iter. 
			return;											// Leaving the for loop
		}													// 
		index++;											// Increasing index after each loop
	}
}

bool Staff_Controller_Class::hasManager() {                 // 
	for (auto& person : staffList) {						// Going through all the staffList
		if (person.getIsManager())							// If this staff is a manager
			return true;									// Return true
	}														// 
															// 
	return false;											// If we never found it, return false
}

