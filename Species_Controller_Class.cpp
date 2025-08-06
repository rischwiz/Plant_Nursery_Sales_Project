#include <iostream>
#include <string>
#include <vector>
#include "Species_Controller_Class.h"

using namespace std;

species* Species_Controller_Class::getSpeciesPointer(int targetID) 
{
    species* returningSpecies = nullptr;
    for (auto& currSpecies : speciesList)
        if (currSpecies.getSpeciesID() == targetID) {
            returningSpecies = &currSpecies;
            break;
        }
    return returningSpecies;
}

void Species_Controller_Class::addSpecies(string name, string season, string environment, string description, int careLevel, int quantity, double price)
{
    uniqueID++;
    species newSpecies(uniqueID, name, season, environment, description, careLevel, quantity, price);
    speciesList.push_back(newSpecies);
}

void Species_Controller_Class::removeSpecies(int targetID)
{
    speciesList.erase(speciesList.begin() + (getSpeciesPointer(targetID) - &speciesList[0]));
}

void Species_Controller_Class::editSpeciesName(int targetID, string newName)
{
    species* targetSpecies = getSpeciesPointer(targetID);
    targetSpecies->setName(newName);
}

void Species_Controller_Class::editSpeciesSeason(int targetID, string newSeason)
{
    species* targetSpecies = getSpeciesPointer(targetID);
    targetSpecies->setSeason(newSeason);
}

void Species_Controller_Class::editSpeciesEnvironment(int targetID, string newEnvironment)
{
    species* targetSpecies = getSpeciesPointer(targetID);
    targetSpecies->setEnvironment(newEnvironment);
}

void Species_Controller_Class::editSpeciesDescription(int targetID, string newDescription)
{
    species* targetSpecies = getSpeciesPointer(targetID);
    targetSpecies->setDescription(newDescription);
}

void Species_Controller_Class::editSpeciesCareLevel(int targetID, int newCareLevel)
{
    species* targetSpecies = getSpeciesPointer(targetID);
    targetSpecies->setCareLevel(newCareLevel);
}

void Species_Controller_Class::editSpeciesQuantity(int targetID, int newQuantity)
{
    species* targetSpecies = getSpeciesPointer(targetID);
    targetSpecies->setQuantity(newQuantity);
}

void Species_Controller_Class::editSpeciesPrice(int targetID, double newPrice)
{
    species* targetSpecies = getSpeciesPointer(targetID);
    targetSpecies->setPrice(newPrice);
}
