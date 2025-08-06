#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class species
{
private:
	int speciesID;
	string name;
	string season;
	string environment;
	string description;
	int careLevel;
	int quantity;
	double price;

public:
	//Constructor
	species(int speciesID_, string name_, string season_, string environment_, string description_, int careLevel_, int quantity_, double price_)
	{
		speciesID = speciesID_;
		name = name_;
		season = season_;
		environment = environment_;
		description = description_;
		careLevel = careLevel_;
		quantity = quantity_;
		price = price_;
	}

	// Set Functions
	// void setSpeciesID(int newSpeciesID)
	// {
	// 	speciesID = newSpeciesID;
	// }
	void setName(string newName)
	{
		name = newName;
	}
	void setSeason(string newSeason)
	{
		season = newSeason;
	}
	void setEnvironment(string newEnvironment)
	{
		environment = newEnvironment;
	}
	void setDescription(string newDescription)
	{
		description = newDescription;
	}
	void setCareLevel(int newCareLevel)
	{
		careLevel = newCareLevel;
	}
	void setQuantity(int newQuantity)
	{
		quantity = newQuantity;
	}
	void setPrice(double newPrice)
	{
		price = newPrice;
	}

	//Get Functions
	int getSpeciesID()
	{
		return speciesID;
	}
	string getName()
	{
		return name;
	}
	string getSeason()
	{
		return season;
	}
	string getEnvironment()
	{
		return environment;
	}
	string getDescription()
	{
		return description;
	}
	int getCareLevel()
	{
		return careLevel;
	}
	int getQuantity()
	{
		return quantity;
	}
	double getPrice()
	{
		return price;
	}
};

class Species_Controller_Class{
private:
	int uniqueID = 0;
	vector<species> speciesList;
	

public:
	void addSpecies(string name, string season, string environment, string description, int careLevel, int quantity, double price);
	void removeSpecies(int targetID);

	void editSpeciesName(int targetID, string newName);
	void editSpeciesSeason(int targetID, string newSeason);
	void editSpeciesEnvironment(int targetID, string newEnvironment);
	void editSpeciesDescription(int targetID, string newDescription);
	void editSpeciesCareLevel(int targetID, int newCareLevel);
	void editSpeciesQuantity(int targetID, int newQuantity);
	void editSpeciesPrice(int targetID, double newPrice);

	// For loading from files
	void setUniqueID(int currID) { uniqueID = currID; }
	void setSpeciesList(vector<species> newSpeciesList) { speciesList = newSpeciesList; }
	int getUniqueID() { return uniqueID; }

	vector<species> getSpeciesList() { return speciesList; }
	species getSpecies(int targetID) { species copy = *getSpeciesPointer(targetID); return copy; }
	species* getSpeciesPointer(int targetID);

};

