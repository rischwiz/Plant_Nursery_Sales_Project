#pragma once
#include <string>
#include <vector>

using namespace std;


class staff {
private:
	int staffID;
	string name;
	string address;
	string phone;
	string email;
	string username;
	string password;
	double salary;
	bool isManager;


public:
	staff(int staffID_, string name_, string address_, string phone_, string email_, string username_, string password_, double salary_, bool isManager_) :
		staffID(staffID_), name(name_), address(address_), phone(phone_), email(email_), username(username_), password(password_), salary(salary_), isManager(isManager_)
	{
	}

	// Set Functions
	void setName(string newName)         { name = newName; }
	void setAddress(string newAddress)   { address = newAddress; }
	void setPhone(string newPhone)       { phone = newPhone; }
	void setEmail(string newEmail)       { email = newEmail; }
	void setUsername(string newUsername) { username = newUsername; }
	void setPassword(string newPassword) { password = newPassword; }
	void setSalary(double newSalary)     { salary = newSalary; }
	void setIsManager(bool newIsManager) { isManager = newIsManager; }


	// Get Functions
	int getStaffID()     { return staffID;}
	string getName()     { return name;}
	string getAddress()  { return address;}
	string getPhone()    { return phone;}
	string getEmail()    { return email;}
	string getUsername() { return username;}
	string getPassword() { return password;}
	double getSalary()   { return salary;}
	bool getIsManager()  { return isManager; }
};


class Staff_Controller_Class{
private:
	int uniqueID = 0;
	vector<staff> staffList;
public:
	// Constructor
	Staff_Controller_Class() {};

	// Set Functions
	void addStaff(string name, string address, string phone, string email, string username, string password, double salary, bool isManager);
	void removeStaff(int targetID);
	void setStaffName(int targetID, string newName);
	void setStaffAddress(int targetID, string newAddress);
	void setStaffPhone(int targetID, string newPhone);
	void setStaffEmail(int targetID, string newEmail);
	void setStaffUsername(int targetID, string newUsername);
	void setStaffPassword(int targetID, string newPassword);
	void setStaffSalary(int targetID, double newSalary);
	void setStaffIsManager(int targetID, bool newIsManager);

	// For loading from files
	void setUniqueID(int currID) { uniqueID = currID; }
	void setStaffList(vector<staff> newStaffList) { staffList = newStaffList; }
	int getUniqueID() { return uniqueID; }
	bool hasManager();


	
	// Helping Functions
	bool usernameUnique(string username) {
		for (auto& person : staffList) {
			if (username == person.getUsername())
				return false;
		}
		return true;
	}

	// Get Functions
	vector<staff> getStaffList() { return staffList; }
	staff getSingleStaff(int targetID) { staff copy = *getStaffPointer(targetID); return copy; }
	staff* getStaffPointer(int targetID);
};

