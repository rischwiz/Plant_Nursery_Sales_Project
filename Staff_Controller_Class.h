#pragma once
#include <string>
#include <vector>

using namespace std;


/*
===============================================================
Name of Artifact  : Staff Class
Brief Description : Holds all the date for the staff. The cons-
					tructor makes the object using the uniqueID
					sent it. All other methods are set/get
					functions
Coder Name        : Emanuel
Date              : 08/07/2025
===============================================================
*/


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



/*
===============================================================
Name of Artifact  : Staff Controller Class
Brief Description : Holds all the staff in a vector and a unique
					ID that is kept track of. The set and get
					functions allow changes for any staff. The
					addstaff takes care of increasing the unique
					ID to keep this number unique.
Coder Name        : Emanuel
Date              : 08/07/2025
===============================================================
*/




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
	bool hasManager();                                                          // Returns true if there is at least one manager in staff


	
	// Helping Functions
	bool usernameUnique(string username) {                                     // Returns true if this username has not been used before
		for (auto& person : staffList) {
			if (username == person.getUsername())
				return false;
		}
		return true;
	}

	// Get Functions
	vector<staff> getStaffList() { return staffList; }                                             // Returns a copy of the full staff list
	staff getSingleStaff(int targetID) { staff copy = *getStaffPointer(targetID); return copy; }   // Returns a copy of a single staff object
	staff* getStaffPointer(int targetID);														   // Returns the staff address(&) by ID
};

