/*
===============================================================
Name of Artifact  : User Interface Class.cpp
Brief Description : This class handles the implementation of the 
                    methods defined in the User_Interface.h file
Coder Name        : Richard, Emannuel, Arya
Date              : 08/07/2025
===============================================================
*/



#include "User_Interface.h"

//This function can be used for input validation by the user so we dont have to check the variables every single time. 
//Just to make sure the user inputted a valid number
int User_Interface::getUserInput(string menu, int maxOptions) { 
    string tempString;
    int tempInt = -1;

    while (tempInt == -1) {
        cls();
        cout << menu << endl;
        cout << "Enter a choice above: ";
        getline(cin, tempString);
        if (!safeConvertToInt(tempString, tempInt)) {
            tempInt = -1;
            continue;
        }

        if (tempInt < 1 || tempInt > maxOptions) {
            tempInt = -1;
            continue;
        }


    }
    return tempInt;
}


//Function that handles the UI for the staff
void User_Interface::staffUI() {
    while (true) {
        cls();
        int userChoice = getUserInput(staffMenu, staffOptions);
        if (userChoice == staffOptions)
            return;

        cls();
        switch (userChoice) {
        case 1:
            displayInventory();
            break;
        case 2:
            addSale();
            break;
        case 3:
            addSpecies();
            break;
        case 4:
            removeSpecies();
            break;
        }
        save();
        pause();
    }
}

//Function that handles the UI for the manager
void User_Interface::managerUI() {
    while (true) {
        cls();
        int userChoice = getUserInput(managerMenu, managerOptions);
        int tempInt;
        if (userChoice == managerOptions)
            return;

        cls();
        switch (userChoice) {
        case 1:
            displayInventory();
            break;
        case 2:
            addSale();
            break;
        case 3:
            addSpecies();
            break;
        case 4:
            removeSpecies();
            break;
        case 5:
            generateReport();
            break;
        case 6:
            tempInt = getUserInput(addEditStaff, addEditStaffOptions);
            if (tempInt == addEditStaffOptions)
                continue;
            if (tempInt == 1)
                addStaff();
            else
                removeStaff();
            break;
        case 7:
            editStaff();
            break;
        }
        save();
        pause();
    }
}



void User_Interface::displayInventory(){ //displays inventorty of all the speicies 
    cls();
    //Check to see if there are any plants for sale
    if (inventory.getSpeciesList().size() == 0) {
        cout << "There are currently no plants for sale." << endl;
        return;
    }

    for (auto& plant : inventory.getSpeciesList()) {
        line();
        cout << "Name: " << plant.getName() << endl;
        cout << "Season: " << plant.getSeason() << endl;
        cout << "Environment: " << plant.getEnvironment() << endl;
        cout << "Description: " << plant.getDescription() << endl;
        cout << "Care Level : " << plant.getCareLevel() << endl;
        cout << "Quantity: " << plant.getQuantity() << endl;
        cout << "Price: " << plant.getPrice() << endl;
        line();
    }
}


//Function used to add species if the user selects this option
void User_Interface::addSpecies(){
    cls();
    string name, enviornment, season, description;
    int careLevel; //1-5 
    int quantity;
    double price;

    string tempString;

    cout<< "Enter Plant Species Name: ";
    getline(cin, name);

    cout << "Enter the season for the plant species: ";
    getline(cin, season);

    cout << "Enter the environment the plant species grows in: ";
    getline(cin, enviornment);

    cout << "Enter the description for the plant species: ";
    getline(cin, description);


    careLevel = -1;
    while (careLevel == -1) {//Input Validation
        cout << "Enter the Care Level (1-5) for the species: ";
        getline(cin, tempString);
        if (!safeConvertToInt(tempString, careLevel)) {
            careLevel = -1;
            continue;
        }
        if (careLevel < 1 || careLevel > 5){
            cout << "Invalid Care Level. Please make sure it is between 1 and 5.\n";
            careLevel = -1;
        }
    }

    quantity = -1;
    while(quantity == -1){//Input Validation
        cout<< "Enter the quantity: ";
        getline(cin, tempString);
        if(!safeConvertToInt(tempString, quantity))
        {
            quantity = -1;
            continue;
        }
        if(quantity <= 0)
        {
            cout << "Invalid Quantity. Please Make sure it is greater than 0.\n";
            quantity = -1;
        }
    }

    price = -1.00;
    while(price == -1.00)//Input Validation
    {
        cout<< "Enter the Price for the Plant: ";
        getline(cin, tempString);
        if(!safeConvertToDouble(tempString, price))
        {
            price = -1.00;
            continue;
        }
        if(price <= 0.00)
        {
            cout << "Invalid Price. Please make sure it is greater than $0.00. \n";
            price = -1.00;
        }
    }
    
    inventory.addSpecies(name, season, enviornment, description, careLevel, quantity, price);
}

//Function used to remove a plant species 
void User_Interface::removeSpecies() {

    if (inventory.getSpeciesList().empty()) { 
        cout << "There are currently no species in inventory." << endl;
        return;
    }

    string tempString;
    int tempInt = -1;
    while (tempInt == -1) {//Input Validation
        cls();
        line();
        for (auto& plant : inventory.getSpeciesList()) {
            cout << "Name : " << plant.getName() << endl;
            cout << "ID   : " << plant.getSpeciesID() << endl;
            line();
        }

        cout << "Enter the ID of the species you want to remove. " << endl;
        cout << "Enter 'c' to cancel." << endl;
        cout << "> ";

        getline(cin, tempString);
        if (tempString == "c" || tempString == "C")
            return;

        // Making sure the input can convert to an integer
        if (!safeConvertToInt(tempString, tempInt)) {
            tempInt = -1;
            continue;
        }

        // Making sure the species is in the vector
        if (inventory.getSpeciesPointer(tempInt) == nullptr) {
            tempInt = -1;
            continue;
        }
    }

    // Removing the species
    inventory.removeSpecies(tempInt);
    cls();
    cout << "This species has been removed." << endl;
}

//Function used to add a staff member
void User_Interface::addStaff() {
    // workers.usernameUnique() = false when username is already used, true when username is avaiable
    cls();
    string name, address, phone, email, username, password, tempString;
    double salary;
    bool isManager;
    bool validUsername = false;

    cout << "Enter name: ";
    getline(cin, name);

    cout << "Enter address: ";
    getline(cin, address);

    cout << "Enter phone: ";
    getline(cin, phone);

	cout << "Enter email: ";
	getline(cin, email);

    while (!validUsername) {//Input Validation
        cout << "Enter username: ";
        getline(cin, username);

        validUsername = workers.usernameUnique(username);
        if (!validUsername) {
            cout << "This username is taken." << endl;
        }
    }

	cout << "Enter password: ";
	getline(cin, password);

    salary = -1;
    while (salary == -1) {//Input Validation
        cout << "Enter salary: ";
        getline(cin, tempString);
        if (!safeConvertToDouble(tempString, salary) || salary <= 0) {
            salary = -1;
        }
    }

    tempString = "";
    while (tempString == "") {//Input Validation
        cout << "Is this staff a manager? Enter 'y' or 'n': ";
        getline(cin, tempString);
        if (tempString == "y" || tempString == "Y")
            tempString = "y";
        else if (tempString == "n" || tempString == "Y")
            tempString = "n";
        else
            tempString = "";
    }

    isManager = (tempString == "y");

    cls();
    workers.addStaff(name, address, phone, email, username, password, salary, isManager);
    cout << "New Staff has been added." << endl;

}


//Function used to remove a staff member
void User_Interface::removeStaff() {
    if (workers.getStaffList().empty()) {
        cout << "There are currently no staff." << endl;
        return;
    }


    string tempString;
    int tempInt = -1;
    while (tempInt == -1) {//Input Validation
        cls();
        line();
        for (auto& person : workers.getStaffList()) {
            cout << "Name : " << person.getName() << endl;
            cout << "User : " << person.getUsername() << endl;
            cout << "ID   : " << person.getStaffID() << endl;
            line();
        }

        cout << "Enter the ID of the staff you want to remove. " << endl;
        cout << "Enter 'c' to cancel." << endl;
        cout << "> ";

        getline(cin, tempString);
        if (tempString == "c" || tempString == "C")
            return;

        // Making sure the input can convert to an integer
        if (!safeConvertToInt(tempString, tempInt)) {
            tempInt = -1;
            continue;
        }

        // Making sure the species is in the vector
        if (workers.getStaffPointer(tempInt) == nullptr) {
            tempInt = -1;
            continue;
        }
    }

    // Removing the species
    workers.removeStaff(tempInt);
    cls();
    cout << "This staff has been removed." << endl; 
}

//Function used to edit the data of a staff member
void User_Interface::editStaff() {
    cls();

    if (workers.getStaffList().empty()) {
        cout << "There are currently no staff." << endl;
        return;
    }

    string tempString;
    int tempInt = -1;
    while (tempInt == -1) {
        cls();
        line();
        for (auto& person : workers.getStaffList()) {
            cout << "Name : " << person.getName() << endl;
            cout << "User : " << person.getUsername() << endl;
            cout << "ID   : " << person.getStaffID() << endl;
            line();
        }

        cout << "Enter the ID of the staff you want to edit. " << endl;
        cout << "Enter 'c' to cancel." << endl;
        cout << "> ";

        getline(cin, tempString);
        if (tempString == "c" || tempString == "C")
            return;

        // Making sure the input can convert to an integer
        if (!safeConvertToInt(tempString, tempInt)) {
            tempInt = -1;
            continue;
        }

        // Making sure the species is in the vector
        if (workers.getStaffPointer(tempInt) == nullptr) {
            tempInt = -1;
            continue;
        }
    }

    cls();
    staff targetStaff = workers.getSingleStaff(tempInt);

    int userChoice = -1;
    while (userChoice == -1) {//Input Validation
        cls();
        line();
        // Showing the staff that was selected
        cout << "Staff ID: " << targetStaff.getStaffID() << endl;
        cout << "Name    : " << targetStaff.getName() << endl;
        cout << "Address : " << targetStaff.getAddress() << endl;
        cout << "Phone   : " << targetStaff.getPhone() << endl;
        cout << "Email   : " << targetStaff.getEmail() << endl;
        cout << "Username: " << targetStaff.getUsername() << endl;
        cout << "Password: " << targetStaff.getPassword() << endl;
        cout << "Manager : " << (targetStaff.getIsManager() ? "True" : "False") << endl;
        line();
        cout << "1) Name\n2) Address\n3) Phone\n4) Email\n5) Username\n6) Password\n7) Salary\n8) Exit" << endl;
        line();

        // Getting input and validating its a number between 1-8
        cout << "Enter an option above: ";
        getline(cin, tempString);
        if (!safeConvertToInt(tempString, userChoice) || userChoice < 1 || userChoice > 8) {
            userChoice = -1;
        }
        if (userChoice == 8)
            return;
    }

    bool validUsername = false; //variable to check if the username matches an already existing one
    double salary = -1; 
    switch (userChoice) {
    case 1:
        cout << "Enter a name: "; 
        getline(cin, tempString); 
        workers.setStaffName(tempInt, tempString);
        break;
    case 2:
        cout << "Enter an address: ";
        getline(cin, tempString);
        workers.setStaffAddress(tempInt, tempString);
        break;
    case 3:
        cout << "Enter a phone: ";
        getline(cin, tempString);
        workers.setStaffPhone(tempInt, tempString);
        break;
    case 4:
        cout << "Enter an email: ";
        getline(cin, tempString);
        workers.setStaffEmail(tempInt, tempString);
        break;
    case 5:
        while (!validUsername) {
            cout << "Enter an username: ";
            getline(cin, tempString);
            validUsername = workers.usernameUnique(tempString);
        }
        workers.setStaffUsername(tempInt, tempString);
        break;
    case 6:
        cout << "Enter a password: ";
        getline(cin, tempString);
        workers.setStaffAddress(tempInt, tempString);
        break;
    case 7:
        cout << "Enter a Salary: ";
        salary = -1;
        while (salary == -1) {
            getline(cin, tempString);
            if (!safeConvertToDouble(tempString, salary)) {
                salary = -1;
                continue;
            }
            if (salary <= 0) {
                salary = -1;
                continue;
            }
        }
        workers.setStaffSalary(tempInt, salary);
        break;
    }

    cout << "Staff has been updated." << endl;
}


//Function used to add a sale
//
void User_Interface::addSale() {

    if (inventory.getSpeciesList().size() == 0) {
        cout << "There are currently species in inventory" << endl;
        return;
    }

    // customerID,  staffID,  paymentType,  salesDate,  totalAmount,  speciesIDSold
    cls();

    line();
    for (auto& plant : inventory.getSpeciesList()) {
            cout << "Name : " << plant.getName() << endl;
            cout << "ID   : " << plant.getSpeciesID() << endl;
            cout << "Quantity: " << plant.getQuantity() << endl;
            line();
    }
    
    int staffID = currentUser;
    string paymentType;
    date salesDate;
    double totalAmount;
    
    
    string tempString;

    int speciesID = -1;
    while(speciesID == -1)//Input Validation
    {
        cout << "Enter the Species ID or type 'c' to cancel: ";
        getline(cin, tempString);
        if (tempString == "c" || tempString == "C")
            return;

        if(!safeConvertToInt(tempString, speciesID) || speciesID <= 0){ // Catches when a species ID is not a number OR (||) when its a negative number
            speciesID = -1;
            cout << "Please Enter a valid species ID. " << endl;
            continue;
        }
        if (inventory.getSpeciesPointer(speciesID) == nullptr) { // Catches when the number inputted was not a valid speciesID
            speciesID = -1;
            cout << "Please Enter a valid species ID. " << endl;
        }
        
    }


    species targetSpieces = inventory.getSpecies(speciesID);  // Saving a copy of the species that user has chosen

    
    int quantity = -1; 
    while(quantity == -1)//Input Validation
    {
        cout << "Enter the quantity sold: "; 
        getline(cin, tempString);
        if (!safeConvertToInt(tempString, quantity) || quantity <= 0) {
            quantity = -1;
            continue;
        }
        if (quantity > targetSpieces.getQuantity()) {
            quantity = -1;
            cout << "This quantity is more than the actual inventory." << endl;
        }

    }


    cout << "\n\nChoose Returning Customer" << endl;
    int customerID = -1;
    while(customerID == -1)//Input Validation
    {
        line();
        if (clients.getCustomerList().size() == 0) {
            cout << "There are currently no customers. \nPlease add one below." << endl;
        }
        else {
            cout << "Choose one of the customers:" << endl;
            for (auto& person : clients.getCustomerList()) {
                cout << "Name: " << person.getName() << endl;
                cout << "ID  : " << person.getCustomerID() << endl;
            }
        }
        line();
        cout << "Enter the Customer ID or type 'a' to add new customer: ";
        getline(cin, tempString);


        if (tempString == "a" || tempString == "A") { // If user wants to add a customer, then go to add customer section
            customerID = addCustomer();
            continue;
        }


        if(!safeConvertToInt(tempString, customerID)) // Catches when the input is not numbers, should NOT continue this code to not crash in conversions
        {
            customerID = -1;
            continue;
        }

        if(customerID <= 0)                          // Catches when the input is a negative
        {
            cout << "Please Enter a valid Customer ID. ";
            customerID = -1;
        }

        if (clients.getCustomerPointer(customerID) == nullptr) { // Catches when the customer ID is not valid
            cout << "Please Enter a vlaid Customer ID." << endl;
            customerID = -1;
        }
    }
  
    
    cout << endl;
    int tempInt = -1;
    while(tempInt == -1)//Input Validation
    {
        cout << "Cash Transaction [1], Debit [2], or Credit [3]? ";
        getline(cin, tempString);
        if(!safeConvertToInt(tempString, tempInt))
        {
            tempInt = -1;
            continue;
        }
        if(tempInt != 1 && tempInt != 2 && tempInt != 3)
        {
            cout << "Please enter either 1, 2, or 3. ";
            tempInt = -1;
        }
    }

    if(tempInt == 1)
        paymentType = "Cash Transaction";
    else if(tempInt == 2)
        paymentType = "Debit Card";
    else
        paymentType = "Credit Card";
    

        int day = -1;
        while(day == -1)//Input Validation
    {
            cout << "Enter the day: ";
            getline(cin, tempString);
        if(!safeConvertToInt(tempString, day))
        {
            day = -1;
            continue;
        }
        if(day <= 0)
        {
            cout << "Please enter a valid day: ";
            day = -1;
        }
    }

        int month = -1;
        while(month == -1)
    {
            cout << "Enter the month: ";
            getline(cin, tempString);
        if(!safeConvertToInt(tempString, month))
        {
            month = -1;
            continue;
        }
        if(month <= 0)
        {
            cout << "Please enter a valid month: ";
            month = -1;
        }
    }


        int year = -1;
        while(year == -1)//Input Validation
    {
            cout << "Enter the year: ";
            getline(cin, tempString);
        if(!safeConvertToInt(tempString, year))
        {
            year = -1;
            continue;
        }
        if(year <= 0)
        {
            cout << "Please enter a valid year: ";
            year = -1;
        }
    }

    //Set the sales date to todays date
    salesDate.setTo(month,day,year);

    //Calculates the total amount of the sale based on the quantity that was bought 
    totalAmount = targetSpieces.getPrice() * quantity;

    
    transactions.addSale(customerID, staffID, paymentType, salesDate, totalAmount, speciesID);


    if (quantity == targetSpieces.getQuantity()) {
        inventory.removeSpecies(speciesID);
    }
    else {
        inventory.editSpeciesQuantity(speciesID, targetSpieces.getQuantity() - quantity);
    }
}



//Function used to remove a sale
void User_Interface::removeSale() {

    if (transactions.getSalesList().empty()) {
        cout << "There are currently no transactions." << endl;
        return;
    }

    string tempString;
    int tempInt = -1;
    while (tempInt == -1) {//Input Validation
        cls();
        line();
        for (auto& transaction : transactions.getSalesList()) {
            cout << "Sale ID     : " << transaction.getSalesID() << endl;
            cout << "Total Amount: " << transaction.getTotalAmount() << endl;
            cout << "Date        : " << transaction.getSalesDate().toString() << endl;
            line();
        }

        cout << "Enter the ID of the sale you want to remove. " << endl;
        cout << "Enter 'c' to cancel." << endl;
        cout << "> ";

        getline(cin, tempString);
        if (tempString == "c" || tempString == "C")
            return;

        // Making sure the input can convert to an integer
        if (!safeConvertToInt(tempString, tempInt)) {
            tempInt = -1;
            continue;
        }

        // Making sure the species is in the vector
        if (transactions.getSalePointer(tempInt) == nullptr) {
            tempInt = -1;
            continue;
        }
    }

    // Removing the species
    transactions.removeSale(tempInt);
    cls();
    cout << "This Transaction has been removed." << endl;
}


//Function used by manager to generate a sales report 
//
void User_Interface::generateReport() {

    if (transactions.getSalesList().empty()) {
        cout << "There are currently no transactions." << endl;
        return;
    }

    cls();
    int userChoice = getUserInput(report, reportOptions);

    if (userChoice == reportOptions)
        return;

    date start, end;
    switch (userChoice) {
    case 1:  // User wants the report for the day
        break; // start and end are init. at today so they are ready to go
    case 2: // User wants the report for the month
        start.setDay(1);
        end.setDay(31);
        break;
    case 3: // User wants the report for the year
        start.setMonth(1);
        start.setDay(1);
        end.setMonth(12);
        end.setDay(31);
    }



    cls();
    line();
    double runningTotal = 0; //Loop that generates the report
    for (auto& transaction : transactions.getReport(start, end)) {
        cout << "{" << setw(3) << setfill('0') << transaction.getSalesID() << "} " << setfill(' ');
        cout << "Customer: " << clients.getCustomer(transaction.getCustomerID()).getName()                   << endl;
        cout << string(6, ' ') << "Staff   : " << transaction.getStaffID()                                   << endl;
        cout << string(6, ' ') << "Date    : " << transaction.getSalesDate().toString()                      << endl;
        cout << string(6, ' ') << "Species : " << transaction.getSpeciesIDSold()                             << endl;
        cout << string(6, ' ') << "Payment : " << transaction.getPaymentType()                               << endl;
        cout << string(6, ' ') << "Total   : " << fixed << setprecision(2) << transaction.getTotalAmount()   << endl << endl;
        
        //calculating the total revenue
        runningTotal += transaction.getTotalAmount();
    }
    line();
    cout << endl << endl;
    line();
    cout << (userChoice == 1 ? "Day " : (userChoice == 2 ? "Month " : "Year ")) << "Report: ";
    cout << "[" << start.toString() << "-" << end.toString() << "]" << endl;
    cout << "Total Amount $" << fixed << setprecision(2) << runningTotal << endl;
    line();

}


//Function that checks the username and passowrd entered in
int User_Interface::checkCredentials(string usernameAttempt, string passwordAttempt) {

    for (auto& person : workers.getStaffList()) {         // Looking through all the workers
        if (person.getUsername() == usernameAttempt) {    // If the username matches
            if (person.getPassword() == passwordAttempt)  // --> If the password matches
                return (person.getIsManager() ? 2 : 1);   // -----> return 1 if the user is a manager, return 2 if the user is a staff
            else                                          // --> If the password DOES NOT match
                return 0;                                 // -----> return 0 saying that the password is incorrect
        }
    }

    return 0;                                             // If the username was not found, return 0 that the user doesn't even exists
}


//Function used to add a customer
int User_Interface::addCustomer() {
    string newName, newAddress;

    line();
    cout << "New Customer Name: ";
    getline(cin, newName);
    cout << "New Customer Address: ";
    getline(cin, newAddress);

    return clients.addCustomer(newName, newAddress);
}



//Funciton that clears the terminal to make it more readable 
void User_Interface::cls() {
    cout << string(30, '\n') << endl;
}

//Function that pauses throughout the program to allow for smoother user experience
void User_Interface::pause() {
    cout << "Press enter to conintue." << endl; 
    string tempString; 
    getline(cin, tempString);
}

//Function that converts the inputed string to integer
bool User_Interface::safeConvertToInt(string &targetString, int &targetInt) {
    try { //try catch block will catch any value that cannot be converted to integer 
        targetInt = stoi(targetString);
    }
    catch (...) {
        return false;
    }
    return true;
}


//Function that converts the inputed string to a double
bool User_Interface::safeConvertToDouble(string& targetString, double& targetInt) {
    try { //try catch block will catch any value that cannot be converted to integer 
        targetInt = stod(targetString);
    }
    catch (...) {
        return false;
    }
    return true;
}



//function that outputs a line 
void User_Interface::line() { 
    cout << "----------------------------------" << endl; 
}


//Function that setrs the username of a staff member
void User_Interface::setUser(string username) {
    for (auto& person : workers.getStaffList()) {
        if (person.getUsername() == username)
            currentUser = person.getStaffID();
    }
}

//funciton that creates a manager, if no data for a manager detected it automatically defaults 
// to creating one 
void User_Interface::makeManager() {
    string name, address, phone, email, username, password, tempString;
    double salary;
    cls();
    line();
    cout << "Making The First Manager" << endl;
    line();

    cout << "Name: ";
    getline(cin, name);

    cout << "Address: ";
    getline(cin, address);

    cout << "Phone: ";
    getline(cin, phone);

    cout << "Email: ";
    getline(cin, email);

    username = "";
    while (username == "") {
        cout << "Username: ";
        getline(cin, username);
        if (!workers.usernameUnique(username)) {
            username = "";
        }
    }

    cout << "Password: ";
    getline(cin,  password);

    salary = -1;
    while (salary == -1) {
        cout << "Salary : ";
        getline(cin, tempString);
        if (!safeConvertToDouble(tempString, salary) || salary <= 0) {
            salary = -1;
        }
    }

    // Make manager with "true" for the is manager
    workers.addStaff(name, address, phone, email, username, password, salary, true);
    cls();
    cout << "Manager has been created." << endl;
    pause();

    save(); // writes this new manager to the files
}


//Function that reads data from the files
User_Interface::User_Interface() {
    // Making all the files if they do not exist already
    ifstream testingStaff(staffFile);
    ifstream testingSpecies(speciesFile);
    ifstream testingSales(salesFile);
    ifstream testingCustomers(customersFile);

    if (!testingStaff) {
        ofstream makingStaff(staffFile);
        makingStaff.close();
    }
    else { testingStaff.close(); }

    if (!testingSpecies) {
        ofstream makingSpecies(speciesFile);
        makingSpecies.close();
    }
    else { testingSpecies.close();}

    if (!testingSales) {
        ofstream makingSales(salesFile);
        makingSales.close();
    }
    else { testingSales.close(); }

    if (!testingCustomers) {
        ofstream makingCustomers(customersFile);
        makingCustomers.close();
    }
    else { testingCustomers.close(); }


    // Reading from the files, if they are empty then they will just be skipped here
    ifstream readingStaff(staffFile);
    ifstream readingSpecies(speciesFile);
    ifstream readingSales(salesFile);
    ifstream readingCustomers(customersFile);
    string tempString;

    getline(readingStaff, tempString);
    if (!tempString.empty()) {
        workers.setUniqueID(stoi(tempString));                  // Setting the current uniqueID so that we know where we left off last time
        

        int staffID;                                            // -,
        double salary;                                          //  | Making variables for parsing
        bool isManager;                                         //  |
        string name, address, phone, email, username, password; // -'
        vector<staff> newStaffList;                             // Making a new list that we will set the staffList with at the end of this section

        // <staffID>|<name>|<address>|<phone>|<email>|<username>|<password>|<salary>|<isManager>
        while (getline(readingStaff, tempString)) {                                                // Reading every line in the file
            if (tempString.empty())                                                                // Ignoring empty lines just in case
                continue;
            stringstream ss(tempString);                                                           // Making a string stream to hold the string we read
                                                                                                   
            getline(ss, tempString, '|'); staffID = stoi(tempString);                              // Sending into tempstring, then converting (getline only uses string)
            getline(ss, name, '|');                                                                
            getline(ss, address, '|');                                                             
            getline(ss, phone, '|');                                                               
            getline(ss, email, '|');                                                               
            getline(ss, username, '|');                                                            
            getline(ss, password, '|');                                                            
            getline(ss, tempString, '|'); salary = stod(tempString);                               // Sending into tempstring, then converting (getline only uses string)
            getline(ss, tempString);      isManager = (tempString == "1" ? true : false);          // Sending into tempstring, then converting (getline only uses string)

            staff newStaff(staffID, name, address, phone, email, username, password, salary, isManager); // Making new staff object
            newStaffList.push_back(newStaff);                                                            // Pushing this new staff into the vector above 
        }

        workers.setStaffList(newStaffList);  // Saving the staff list into the control class
        readingStaff.close();
    }
    else { readingStaff.close(); } // If first read was empty, then we assume file is new







    getline(readingSpecies, tempString);
    if (!tempString.empty()) {
        inventory.setUniqueID(stoi(tempString));                 


        int speciesID, careLevel, quantity;
        double price;                                           
        string name, season, environment, description;
        vector<species> newSpeciesList;                             

        // <speciesID>|<name>|<season>|<environment>|<description>|<careLevel>|<quantity>|<price>
        while (getline(readingSpecies, tempString)) {
            if (tempString.empty())                                                               
                continue;
            stringstream ss(tempString);                                                          

            getline(ss, tempString, '|'); speciesID = stoi(tempString);
            getline(ss, name, '|');
            getline(ss, season, '|');
            getline(ss, environment, '|');
            getline(ss, description, '|');
            getline(ss, tempString, '|'); careLevel = stoi(tempString);
            getline(ss, tempString, '|'); quantity = stoi(tempString);
            getline(ss, tempString, '|'); price = stod(tempString);                               

            species newSpecies(speciesID, name, season, environment, description, careLevel, quantity, price);
            newSpeciesList.push_back(newSpecies);
        }

        inventory.setSpeciesList(newSpeciesList);
        readingSpecies.close();
    }
    else { readingSpecies.close(); } 







    getline(readingSales, tempString);
    if (!tempString.empty()) {
        transactions.setUniqueID(stoi(tempString));


        date salesDate;
        string paymentType;
        double totalAmount;
        int salesID, customerID, staffID, speciesIDSold;
        vector<Sales> newSalesList;

        // <salesID>|<customerID>|<staffID>|<paymentType>|<salesDate>|<totalAmount>|<speciesIDSold>
        while (getline(readingSales, tempString)) {
            if (tempString.empty())
                continue;
            stringstream ss(tempString);

            getline(ss, tempString, '|'); salesID = stoi(tempString);
            getline(ss, tempString, '|'); customerID = stoi(tempString);
            getline(ss, tempString, '|'); staffID = stoi(tempString);
            getline(ss, paymentType, '|');
            getline(ss, tempString, '|'); salesDate.setFromString(tempString);
            getline(ss, tempString, '|'); totalAmount = stod(tempString);
            getline(ss, tempString, '|'); speciesIDSold = stoi(tempString);

            Sales newSale(salesID, customerID, staffID, paymentType, salesDate, totalAmount, speciesIDSold);
            newSalesList.push_back(newSale);
        }

        transactions.setSalesList(newSalesList);
        readingSales.close();
    }
    else { readingSales.close(); } 







    getline(readingCustomers, tempString);
    if (!tempString.empty()) {
        clients.setUniqueID(stoi(tempString));


        int customerID;
        string name, address;
        vector<customer> newCustomerList;

        // <customerID>|<name>|<address>
        while (getline(readingCustomers, tempString)) {
            if (tempString.empty())
                continue;
            stringstream ss(tempString);


            getline(ss, tempString, '|'); customerID = stoi(tempString);
            getline(ss, name, '|');
            getline(ss, address, '|');

            customer newCustomer(customerID, name, address);
            newCustomerList.push_back(newCustomer);
        }

        clients.setCustomerList(newCustomerList);
        readingCustomers.close();
    }
    else { readingCustomers.close(); } 



    // IF STAFF LIST DOES NOT HAVE A MANAGER, WE NEED AT LEAST ONE TO MAKE ANY NEW STAFF 
    if (!workers.hasManager()) {
        makeManager();
    }
}

//Function that saves data into files 
void User_Interface::save(){
    // We assume that files were created since we already went through the constructor

    ofstream writtingStaff(staffFile);
    ofstream writtingSpecies(speciesFile);
    ofstream writtingSales(salesFile);
    ofstream writtingCustomers(customersFile);
    
    // FORMATS OF FILES WHEN WRITTING AND READING: ============================================
    // <staffID>|<name>|<address>|<phone>|<email>|<username>|<password>|<salary>|<isManager>    // staff file
    // <speciesID>|<name>|<season>|<environment>|<description>|<careLevel>|<quantity>|<price>   // species file
    // <salesID>|<customerID>|<staffID>|<paymentType>|<salesDate>|<totalAmount>|<speciesIDSold> // sales file
    // <customerID>|<name>|<address>                                                            // customers file
    // ========================================================================================

    writtingStaff << workers.getUniqueID() << endl;
    for (auto& person : workers.getStaffList()) {
        writtingStaff << person.getStaffID() << "|";
        writtingStaff << person.getName() << "|";
        writtingStaff << person.getAddress() << "|";
        writtingStaff << person.getPhone() << "|";
        writtingStaff << person.getEmail() << "|";
        writtingStaff << person.getUsername() << "|";
        writtingStaff << person.getPassword() << "|";
        writtingStaff << person.getSalary() << "|";
        writtingStaff << person.getIsManager() << endl;
    }

    writtingSpecies << inventory.getUniqueID() << endl;
    for (auto& plant : inventory.getSpeciesList()) {
        writtingSpecies << plant.getSpeciesID() << "|";
        writtingSpecies << plant.getName() << "|";
        writtingSpecies << plant.getSeason() << "|";
        writtingSpecies << plant.getEnvironment() << "|";
        writtingSpecies << plant.getDescription() << "|";
        writtingSpecies << plant.getCareLevel() << "|";
        writtingSpecies << plant.getQuantity() << "|";
        writtingSpecies << plant.getPrice() << endl;
    }

    writtingSales << transactions.getUniqueID() << endl;
    for (auto& transaction : transactions.getSalesList()) {
        writtingSales << transaction.getSalesID() << "|";
        writtingSales << transaction.getCustomerID() << "|";
        writtingSales << transaction.getStaffID() << "|";
        writtingSales << transaction.getPaymentType() << "|";
        writtingSales << transaction.getSalesDate().toString() << "|";
        writtingSales << transaction.getTotalAmount() << "|";
        writtingSales << transaction.getSpeciesIDSold() << endl;
    }

    writtingCustomers << clients.getUniqueID() << endl;
    for (auto& person : clients.getCustomerList()) {
        writtingCustomers << person.getCustomerID() << "|";
        writtingCustomers << person.getName() << "|";
        writtingCustomers << person.getAddress() << endl;
    }




    writtingStaff.close();
    writtingSpecies.close();
    writtingSales.close();
    writtingCustomers.close();
}



