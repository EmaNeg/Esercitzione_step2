/*! @file menu.cpp
    @brief Functions implementation for class menu operations
    @details This file contains functions to display a menu and handle user input.
    @author Emanuele Negrino and Carlo Toscano
*/ 

#include "menu.h"

using namespace std;

Menu::Menu() {
    // Constructor implementation
}

Menu::~Menu() {
}

void Menu::displayMenu() {
    // Display the menu options
    options = {
        "Esci dal menù",
        "Visualizza lista delle funzioni",
        "Inserisci una funzione",
        "Elimina una funzione",
        "Elimina tutte le funzioni",
        "Seleziona una funzione"
    };

    cout << "Menu Options:\n";
    for (size_t i = 0; i < options.size(); ++i) {
        cout << i << ". " << options[i] << "\n";
    }
    cout << "Please select an option (0-" << options.size()-1 << "): ";
}

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
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard the rest of the line
            break;
        }
    }
    return choice;
}

void showFunctionsList(FunctionList &functionList) {
    cout << "List of functions:\n";
    functionList.showFunctionsList();
}

void insertPowerFunction(FunctionList &functionList) {
    double coeff, exponent;
    cout << "Enter base: ";
    cin >> coeff;
    cout << "Enter exponent: ";
    cin >> exponent;
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

void insertLogFunction(FunctionList &functionList) {
    double coeff, base;
    cout << "Enter coefficient: ";
    cin >> coeff;
    cout << "Enter base: ";
    cin >> base;
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

void insertPolynomialFunction(FunctionList &functionList) {
    int degree;
    cout << "Enter degree: ";
    cin >> degree;
    double *coefficients = new double[static_cast<size_t>(degree + 1)];
    if (coefficients == NULL) {
        cout << "Memory allocation failed.\n";
        return;
    }
    cout << "Enter coefficients (from constant to highest degree): ";
    for (int i = 0; i <= degree; ++i) {
        cin >> coefficients[i];
    }
    Function *polyFunction = new Polynomial(coefficients, degree);
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

void insertFunction(FunctionList &functionList) {
    cout << "Chose a function to insert:\n";
    cout << "1. Power Function\n";
    cout << "2. Logarithmic Function\n";
    cout << "3. Polynomial Function\n";
    cout << "Please select an option (1-3): ";
    int choice;
    cin >> choice;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard the rest of the line
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

void deleteFunction(FunctionList &functionList) {
    showFunctionsList(functionList);
    cout << "\nEnter the ID of the function to delete: ";
    int id;
    cin >> id;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard the rest of the line
    if(functionList.deleteFunction(id)){
        cout << "Function with ID " << id << " deleted successfully.\n";
    }else{
        cout << "Function with ID " << id << " not found.\n";
    }
}

void deleteAllFunctions(FunctionList &functionList) {
    cout << "Are you sure you want to delete all functions? (y/n): ";
    char confirm;
    cin >> confirm;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard the rest of the line
    if (confirm != 'y' && confirm != 'Y') {
        cout << "Deletion cancelled.\n";
        return;
    }
    if(functionList.deleteAllFunctions()){
        cout << "All functions deleted successfully.\n";
    }else{
        cout << "No functions to delete.\n";
    }
}

void selectFunction(FunctionList &functionList) {
    showFunctionsList(functionList);
    cout << "\nEnter the ID of the function to select: ";
    int id;
    cin >> id;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard the rest of the line
    cout << "Enter the value of x: ";
    double x;
    cin >> x;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard the rest of the line
    functionList.selectFunction(id, x);
}

int manageUserChoice(int choice, FunctionList &functionList) {
    switch (choice) {
        case 0:
            cout << "Exiting the menu.\n";
            deleteAllFunctions(functionList);
            return 0;
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
