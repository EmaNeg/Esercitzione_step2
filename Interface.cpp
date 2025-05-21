/*! @file menu.cpp
    @brief Functions implementation for class menu operations
    @details This file contains functions to display a menu and handle user input.
    @author Emanuele Negrino and Carlo Toscano
*/ 

#include "Interface.h"

using namespace std;

/// @brief Default Constructor of Menu class
/// @details This constructor initializes the menu options.
Menu::Menu() {
}
/// @brief Destructor of Menu class
/// @details This destructor clears the options vector.
Menu::~Menu() {
    options.clear(); // Clear the options vector
}

/// @brief Function to display the menu options
/// @details This function displays the menu options to the user and prompts for input.
void Menu::display() {
    // Display the menu options
    options = {
        "Esci dal menù",
        "Visualizza lista delle funzioni",
        "Inserisci una funzione",
        "Elimina una funzione",
        "Elimina tutte le funzioni",
        "Seleziona una funzione"
    };

    cout << "\nMenu Options:\n";
    for (size_t i = 0; i < options.size(); ++i) {
        cout << i << ". " << options[i] << "\n";
    }
    cout << "Please select an option (0-" << options.size()-1 << "): ";
}

/// @brief Function to get user choice
/// @details This function prompts the user for input and validates it.
/// @return The user's choice as an integer
int Menu::getUserChoice() {
    int min = 0;
    int max = (int)(options.size()-1);
    int choice;
    while (true) {
        cin >> choice;
        if (cin.fail() || choice < min || choice > max) {
            cin.clear(); // clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input
            cout << "Invalid input. Please enter a number between " << min << " and " << max << ": ";
        } else {
            
            break;
        }
    }
    return choice;
}

/// @brief Function to check if the input is numeric
/// @details This function checks if the input is numeric and clears the error flag if not.
/// @return true if the input is numeric, false otherwise
bool checkIfNumeric() {
    if(cin.fail()) {
        cin.clear(); // clear the error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input
        return false;
    }
    return true;
}

/// @brief Function to show the list of functions
/// @details This function displays the list of functions to the user.
/// @param functionList The list of functions to be displayed
void showFunctionsList(FunctionList &functionList) {
    cout << "List of functions:\n";
    functionList.showFunctionsList();
}

/// @brief Function to insert a power function
/// @details This function prompts the user for input to create a power function and adds it to the list.
/// @param functionList The list of functions to which the power function will be added
void insertPowerFunction(FunctionList &functionList) {
    double coeff, exponent;
    cout << "Enter coefficient: ";
    cin >> coeff;
    if(checkIfNumeric() == false){
        cout << "Invalid input. Please enter numeric values.\n";
        return;
    }
    cout << "Enter exponent: ";
    cin >> exponent;
    if(checkIfNumeric() == false){
        cout << "Invalid input. Please enter numeric values.\n";
        return;
    }
    Function *powerFunction = new Power(coeff, exponent);
    cout << "Power function: ";
    powerFunction->Dump();
    cout << "\nAre you sure you want to add this function? (y/n): ";
    char confirm;
    cin >> confirm;
    if (confirm != 'y' && confirm != 'Y') {
        cout << "Function not added.\n";
        delete powerFunction; // Free the allocated memory for the function
        return;
    }else if(confirm == 'y' || confirm == 'Y'){
        cout << "Function added.\n";
    }
    functionList.addFunction(powerFunction);
}

/// @brief Function to insert a logarithmic function
/// @details This function prompts the user for input to create a logarithmic function and adds it to the list.
/// @param functionList The list of functions to which the logarithmic function will be added
void insertLogFunction(FunctionList &functionList) {
    double coeff, base;
    cout << "Enter coefficient: ";
    cin >> coeff;
    if(checkIfNumeric() == false){
        cout << "Invalid input. Please enter numeric values.\n";
        return;
    }
    cout << "Enter base: ";
    cin >> base;
    if(checkIfNumeric() == false || base <= 0 || base == 1){
        cout << "Invalid input. Please enter positive numeric values, not equal to 1.\n";
        return;
    }
    Function *logFunction = new Logarithmic(coeff, base);
    cout << "Logarithmic function: ";
    logFunction->Dump();
    cout << "\nAre you sure you want to add this function? (y/n): ";
    char confirm;
    cin >> confirm;
    if (confirm != 'y' && confirm != 'Y') {
        cout << "Function not added.\n";
        delete logFunction; // Free the allocated memory for the function
        return;
    }else if(confirm == 'y' || confirm == 'Y'){
        cout << "Function added.\n";
    }
    functionList.addFunction(logFunction);
}

/// @brief Function to insert a polynomial function
/// @details This function prompts the user for input to create a polynomial function and adds it to the list.
/// @param functionList The list of functions to which the polynomial function will be added
void insertPolynomialFunction(FunctionList &functionList) {
    int degree;
    cout << "Enter degree: ";
    cin >> degree;
    if(checkIfNumeric() == false || degree < 0){
        cout << "Invalid input. Please enter a non-negative integer.\n";
        return;
    }
    double *coefficients = new double[static_cast<size_t>(degree + 1)];
    if (coefficients == NULL) {
        cout << "Memory allocation failed.\n";
        return;
    }
    cout << "Enter coefficients (from constant to highest degree):\n";
    for (int i = 0; i <= degree; ++i) {
        cin >> coefficients[i];
        if(checkIfNumeric() == false){
            cout << "Invalid input. Please enter numeric values.\n";
            delete[] coefficients; // Free the allocated memory for coefficients
            return;
        }
    }
    Function *polyFunction = new Polynomial(coefficients, degree+1); //degree+1 because polynomial wants size of coeff array
    cout << "Polynomial function: ";
    polyFunction->Dump();
    cout << "\nAre you sure you want to add this function? (y/n): ";
    char confirm;
    cin >> confirm;
    if (confirm != 'y' && confirm != 'Y') {
        cout << "Function not added.\n";
        delete polyFunction; // Free the allocated memory for the function
        delete[] coefficients; // Free the allocated memory for coefficients
        return;
    }else if(confirm == 'y' || confirm == 'Y'){
        cout << "Function added.\n";
    }
    functionList.addFunction(polyFunction);
    delete[] coefficients; // Free the allocated memory for coefficients
}

/// @brief Function to insert a function into the list
/// @details This function prompts the user to choose a function type and calls the appropriate insertion function.
/// @param functionList The list of functions to which the new function will be added
void insertFunction(FunctionList &functionList) {
    cout << "\nChose a function to insert:\n";
    cout << "1. Power Function\n";
    cout << "2. Logarithmic Function\n";
    cout << "3. Polynomial Function\n";
    cout << "Please select an option (1-3): ";
    int choice;
    cin >> choice;
    if(checkIfNumeric() == false){
        cout << "Invalid input. Please enter a number between 1 and 3.\n";
        return;
    }
    switch (choice) {
        case 1: {
            // Insert Power Function
            insertPowerFunction(functionList);
            break;
        }
        case 2: {
            // Insert Logarithmic Function
            insertLogFunction(functionList);
            break;
        }
        case 3: {
            // Insert Polynomial Function
            insertPolynomialFunction(functionList);
            break;
        }
        default:
            cout << "Invalid choice. Please try again.\n";
    }
    // Implementation for inserting a function
}

/// @brief Function to delete a function from the list
/// @details This function prompts the user for the ID of the function to be deleted and removes it from the list.
/// @param functionList The list of functions from which the function will be deleted
void deleteFunction(FunctionList &functionList) {
    showFunctionsList(functionList);
    cout << "\nEnter the ID of the function to delete: ";
    int id;
    cin >> id;
    if(checkIfNumeric() == false){
        cout << "Invalid input. Please enter a valid ID.\n";
        return;
    }
    if(functionList.deleteFunction(id)){
        cout << "Function with ID " << id << " deleted successfully.\n";
    }else{
        cout << "Function with ID " << id << " not found.\n";
    }
}

/// @brief Function to delete all functions from the list
/// @details This function prompts the user for confirmation and deletes all functions from the list.
/// @param functionList The list of functions from which all functions will be deleted
/// @return true if all functions were deleted, false otherwise
bool deleteAllFunctions(FunctionList &functionList) {
    cout << "Are you sure you want to delete all functions? (y/n): ";
    char confirm;
    cin >> confirm;
    if (confirm != 'y' && confirm != 'Y') {
        cout << "Deletion cancelled.\n";
        return 0;
    }
    if(functionList.deleteAllFunctions()){
        cout << "All functions deleted successfully.\n";
        return 1;
    }else{
        cout << "No functions to delete.\n";
        return 1;
    }
}

/// @brief Function to select a function by ID and evaluate it at a given x
/// @details This function prompts the user for the ID of the function and the value of x, then evaluates the function.
/// @param functionList The list of functions from which the function will be selected
void selectFunction(FunctionList &functionList) {
    showFunctionsList(functionList);
    cout << "\nEnter the ID of the function to select: ";
    int id;
    cin >> id;
    if(checkIfNumeric() == false){
        cout << "Invalid input. Please enter a valid ID.\n";
        return;
    }
    cout << "Enter the value of x: ";
    double x;
    cin >> x;
    if(checkIfNumeric() == false){
        cout << "Invalid input. Please enter a numeric value for x.\n";
        return;
    }
    functionList.selectFunction(id, x);
}

/// @brief Function to exit the menu
/// @details This function prompts the user for confirmation and exits the menu.
/// @param functionList The list of functions to be managed
/// @return true if the user wants to exit, false otherwise
bool exitMenu(FunctionList &functionList) {
    cout << "Are you sure you want to exit? (y/n): ";
    char confirm;
    cin >> confirm;
    if (confirm != 'y' && confirm != 'Y') {
        cout << "Exiting cancelled.\n";
        return false;
    }
    functionList.deleteAllFunctions();
    cout << "Exiting the menu.\n";
    return true;
}

/// @brief Function to manage user choice
/// @details This function takes the user's choice and calls the appropriate function.
/// @param choice The user's choice as an integer
/// @param functionList The list of functions to be managed
int manageUserChoice(int choice, FunctionList &functionList) {
    switch (choice) {
        case 0:
            if(exitMenu(functionList)){
                return 0;
            }
            break;
        case 1:
            showFunctionsList(functionList);
            break;
        case 2:
            insertFunction(functionList);
            break;
        case 3:
            deleteFunction(functionList);
            break;
        case 4:
            deleteAllFunctions(functionList);
            break;
        case 5:
            selectFunction(functionList);
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
    }
    return 1;
}
