#pragma once
#include <string>
#include <vector>
#include <chrono>

using namespace std;

// Date class to grab the current date and time
struct date {
private:
	int day = 0;
	int month = 0;
	int year = 0;

public:
	// Constructors
	date() { setToToday(); }

	// Set Functions
	void setTo(int month_, int day_, int year_) { month = month_; day = day_; year = year_; }
	void setToToday() {
		time_t t = time(nullptr);
		tm now = {};
		localtime_s(&now, &t);

		day = now.tm_mday;
		month = now.tm_mon + 1;    // tm_mon is 0-based
		year = now.tm_year + 1900; // tm_year is years since 1900
	}
	void setFromString(string dateInString) { // <month>/<day>/<year>
		month = stoi(dateInString.substr(0, dateInString.find('/')));
		dateInString = dateInString.substr(dateInString.find('/') + 1);
		day = stoi(dateInString.substr(0, dateInString.find('/') + 1));
		dateInString = dateInString.substr(dateInString.find('/') + 1);
		year = stoi(dateInString);
	}

	void setDay(int newDay) { day = newDay; }
	void setMonth(int newMonth) { month = newMonth; }
	void setYear(int newYear) { year = newYear; }


	// Get Functions
	int getDay() { return day; }
	int getMonth() { return month; }
	int getYear() { return year; }
	string toString() {
		return to_string(month) + "/" + to_string(day) + "/" + to_string(year);
	}

	// Comparison Functions to use when generating a report
	bool operator<(date& other) {
		if (year != other.year) return year < other.year;
		if (month != other.month) return month < other.month;
		return day < other.day;
	}

	bool operator>(date& other) {
		return other < *this;
	}

	bool operator<=(date& other) {
		return !(other < *this);
	}

	bool operator>=(date& other) {
		return !(*this < other);
	}
};

/*
========================================================================================
Name of Artifact: Sales Class
Brief Description: The Sales class is used to represent a sale transaction in the system. 
Coder Name: Richard Schweizer
Date: 08/05/2025
=========================================================================================
*/
class Sales {
private:
    int salesID;
    int customerID;
    int staffID;
    string paymentType;
    date salesDate;
    double totalAmount;
    int speciesIDSold;

public:
	Sales(int salesID_, int customerID_, int staffID_, string paymentType_, date salesDate_, double totalAmount_, int speciesIDSold_) :
		salesID(salesID_), customerID(customerID_), staffID(staffID_), paymentType(paymentType_), salesDate(salesDate_), totalAmount(totalAmount_), speciesIDSold(speciesIDSold_) {
	}

	//setters
	void setPaymetType(string newPaymentType)	{ paymentType = newPaymentType; }
	void setTotalAmount(double newTotalAmount)	{ totalAmount = newTotalAmount; }
	void setSpeciesIDSold(int newSpeciesIDSold) { speciesIDSold = newSpeciesIDSold; }
	void setSalesDate(date newSalesDate)		{ salesDate = newSalesDate; }
	void setCustomerID(int newCustomerID) { customerID = newCustomerID; }
	void setStaffID(int newStaffID) { staffID = newStaffID; }

	//getters
	int getSalesID()		{ return salesID; }
	int getCustomerID()		{ return customerID; }
	int getStaffID()		{ return staffID; }
	string getPaymentType() { return paymentType; }
	date getSalesDate()		{ return salesDate; }
	double getTotalAmount() { return totalAmount; }
	int getSpeciesIDSold()	{ return speciesIDSold; }	
};

/*
=========================================================================================
Name of Artifact: Sales Controller Class
Brief Description: The Sales_Controller_Class is responsible for managing sales transactions in the system.
Coder Name: Richard Schweizer
Date: 08/05/2025
==========================================================================================
*/
class Sales_Controller_Class {
private:
	int uniqueID = 0;
	vector<Sales> salesList;
	

public:
	

	void addSale(int customerID, int staffID, string paymentType, date salesDate, double totalAmount, int speciesIDSold);
	void removeSale(int targetID);

	// Set Functions
	void editCustomerID(int targetID, int newCustomerID);
	void editStaffID(int targetID, int newStaffID);
	void editPaymentType(int targetID, string newPaymentType);
	void editSalesDate(int targetID, date newSalesDate);
	void editTotalAmount(int targetID, double newTotalAmount);
	void editSpeciesIDSold(int targetID, int newSpeciesIDSold);


	// For loading from files
	void setUniqueID(int currID) { uniqueID = currID; }
	void setSalesList(vector<Sales> newSalesList) { salesList = newSalesList; }
	int getUniqueID() { return uniqueID; }

	// Get Functions
	vector<Sales> getSalesList() { return salesList; }
	vector<Sales> getReport(date start, date end);
	Sales* getSalePointer(int targetID);
};