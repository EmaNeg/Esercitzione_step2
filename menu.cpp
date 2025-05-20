/*! @file menu.cpp
    @brief Functions implementation for class menu operations
    @details This file contains functions to display a menu and handle user input.
    @author Emanuele Negrino and Carlo Toscano
*/ 

#include "menu.h"

using namespace std;

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

void showFunctionsList() {
    cout << "List of functions:\n";

}

void insertFunction() {
    cout << "Insert a function:\n";
    // Implementation for inserting a function
}

void deleteFunction() {
    cout << "Delete a function:\n";
    // Implementation for deleting a function
}

void deleteAllFunctions() {
    cout << "Delete all functions:\n";
    // Implementation for deleting all functions
}

void selectFunction() {
    cout << "Select a function:\n";
    // Implementation for selecting a function
}

int manageUserChoice(int choice) {
    switch (choice) {
        case 0:
            cout << "Exiting the menu.\n";
            return 0;
        case 1:
            showFunctionsList();
            break;
        case 2:
            insertFunction();
            break;
        case 3:
            deleteFunction();
            break;
        case 4:
            deleteAllFunctions();
            break;
        case 5:
            selectFunction();
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
    }
}

void clearInputBuffer() {
    cin.clear(); // clear the error flag
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input
}

void clearScreen() {
    // Clear the console screen
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}
