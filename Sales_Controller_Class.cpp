#include "Sales_Controller_Class.h"

Sales* Sales_Controller_Class::getSalePointer(int targetID) {
	Sales* returningSale = nullptr;
	for (auto& transaction : salesList) {
		if (transaction.getSalesID() == targetID) {
			returningSale = &transaction;
			break;
		}
	}
	return returningSale;
}

void Sales_Controller_Class::addSale(int customerID, int staffID, string paymentType, date salesDate, double totalAmount, int speciesIDSold) {
	uniqueID++;
	Sales newSale(uniqueID, customerID, staffID, paymentType, salesDate, totalAmount, speciesIDSold);
	salesList.push_back(newSale);
}


void Sales_Controller_Class::removeSale(int targetID) {
	int currentIndex = 0;
	for (auto& current : salesList) {
		if (targetID == current.getSalesID()){
			salesList.erase(salesList.begin() + currentIndex);
			break;
		}
		currentIndex++;
	}
	
}

void Sales_Controller_Class::editCustomerID(int targetID, int newCustomerID) {
	Sales* targetSale = getSalePointer(targetID);
	targetSale->setCustomerID(newCustomerID);
}

void Sales_Controller_Class::editStaffID(int targetID, int newStaffID) {
	Sales* targetSale = getSalePointer(targetID);
	targetSale->setStaffID(newStaffID);
}

void Sales_Controller_Class::editPaymentType(int targetID, string newPaymentType) {
	Sales* targetSale = getSalePointer(targetID);
	targetSale->setPaymetType(newPaymentType);
}

void Sales_Controller_Class::editSalesDate(int targetID, date newDate) {
	Sales* targetSale = getSalePointer(targetID);
	targetSale->setSalesDate(newDate);
}

void Sales_Controller_Class::editTotalAmount(int targetID, double newTotalAmount) {
	Sales* targetSale = getSalePointer(targetID);
	targetSale->setTotalAmount(newTotalAmount);
}

void Sales_Controller_Class::editSpeciesIDSold(int targetID, int newSpeciesIDSold) {
	Sales* targetSale = getSalePointer(targetID);
	targetSale->setSpeciesIDSold(newSpeciesIDSold);
}




vector<Sales> Sales_Controller_Class::getReport(date start, date end){
	vector<Sales> report;
	for (auto& transaction : salesList) {
		if (transaction.getSalesDate() >= start && transaction.getSalesDate() <= end) {
			report.push_back(transaction);
		}
	}
	return report;	
}

