#include "Staff_Controller_Class.h"

staff* Staff_Controller_Class::getStaffPointer(int targetID) { 
	staff* returningStaff = nullptr;

	for (auto& currStaff : staffList) {
		if (currStaff.getStaffID() == targetID) {
			returningStaff = &currStaff;
			break;
		}
	}

	return returningStaff;
}

void Staff_Controller_Class::addStaff(string name, string address, string phone, string email, string username, string password, double salary, bool isManager) {
	uniqueID++;
	staff newStaff(uniqueID, name, address, phone, email, username, password, salary, isManager);
	staffList.push_back(newStaff); 
}


void Staff_Controller_Class::setStaffName(int targetID, string newName) {
	staff* targetStaff = getStaffPointer(targetID);
	targetStaff->setName(newName);
}

void Staff_Controller_Class::setStaffAddress(int targetID, string newAddress) {
	staff* targetStaff = getStaffPointer(targetID);
	targetStaff->setAddress(newAddress);
}

void Staff_Controller_Class::setStaffPhone(int targetID, string newPhone) {
	staff* targetStaff = getStaffPointer(targetID);
	targetStaff->setPhone(newPhone);
}

void Staff_Controller_Class::setStaffEmail(int targetID, string newEmail) {
	staff* targetStaff = getStaffPointer(targetID);
	targetStaff->setEmail(newEmail);
}

void Staff_Controller_Class::setStaffUsername(int targetID, string newUsername) {
	staff* targetStaff = getStaffPointer(targetID);
	targetStaff->setUsername(newUsername);
}

void Staff_Controller_Class::setStaffPassword(int targetID, string newPassword) {
	staff* targetStaff = getStaffPointer(targetID);
	targetStaff->setPassword(newPassword);
}

void Staff_Controller_Class::setStaffSalary(int targetID, double newSalary) {
	staff* targetStaff = getStaffPointer(targetID);
	targetStaff->setSalary(newSalary);
}

void Staff_Controller_Class::setStaffIsManager(int targetID, bool newIsManager) {
	staff* targetStaff = getStaffPointer(targetID);
	targetStaff->setIsManager(newIsManager);
}


void Staff_Controller_Class::removeStaff(int targetID) {
	int index = 0;
	for (auto& currStaff : staffList) {
		if (currStaff.getStaffID() == targetID) {
			staffList.erase(staffList.begin() + index);
			return;
		}
		index++;
	}
}

bool Staff_Controller_Class::hasManager() {
	for (auto& person : staffList) {
		if (person.getIsManager())
			return true;
	}

	return false;
}

