/*! @file FunctionList.cpp
    @brief Implementation of the FunctionList class
    @details This file contains the implementation of the FunctionList class, which manages a list of functions.
    @author Emanuele Negrino and Carlo Toscano
*/

#include "FunctionList.h"

using namespace std;

/// @brief Default Constructor of FunctionList class
/// @details This constructor initializes the first element of the function list to NULL.
FunctionList::FunctionList() {
    // Constructor implementation
    firstElement = NULL; // Initialize the first element to NULL
}

/// @brief Constructor of FunctionList class
/// @details This constructor initializes the first element of the function list with a given function.
/// @param function Pointer to the function to be added to the list.
/// @details If the function is NULL, the first element is set to NULL.
FunctionList::FunctionList(Function *function) {
    if(function != NULL) {
        firstElement = new FunctionElements;
        firstElement->ID = 0; // Initialize ID to 0
        firstElement->type = function->getType(); // Set the type of the function
        firstElement->funzione = function; // Set the function pointer
        firstElement->nextFunctionElement = NULL; // Initialize next element to NULL
    } else {
        firstElement = NULL; // If function is NULL, set first element to NULL
    }
}

/// @brief Destructor of FunctionList class
/// @details This destructor deletes all functions in the list and cleans up the memory.
/// @details It also deletes the first element pointer.
FunctionList::~FunctionList() {
    // Destructor implementation
    deleteAllFunctions(); // Clean up all functions when the list is destroyed
    delete firstElement; // Delete the first element pointer
}

/// @brief Function to search for the next available ID in the function list.
/// @return The next available ID for a new function.
/// @details This function iterates through the list of functions and finds the maximum ID.
int FunctionList::searchID() {
    FunctionElementsPtr currentPtr = firstElement;
    int maxID = -1;
    while (currentPtr != NULL) {
        if (currentPtr->ID > maxID) {
            maxID = currentPtr->ID; // Find the maximum ID
        }
        currentPtr = currentPtr->nextFunctionElement; // Move to the next element
    }
    return maxID + 1; // Return the next available ID
}

/// @brief Function to add a function to the list.
/// @param f Pointer to the function to be added.
/// @return true if the function was added successfully, false otherwise.
/// @details This function creates a new FunctionElements structure, sets its ID, type, and function pointer,
bool FunctionList::addFunction(Function *f) {
    FunctionElementsPtr pNew = new FunctionElements;
    FunctionElementsPtr prevPtr;
    FunctionElementsPtr currentPtr;
    if(pNew != NULL && f != NULL){
        pNew->ID=searchID();
        pNew->type = f->getType();
        pNew->funzione = f;

        pNew->nextFunctionElement = NULL;
        prevPtr = NULL;
        currentPtr = firstElement;
        while(currentPtr!=NULL){
            prevPtr = currentPtr;
            currentPtr = currentPtr->nextFunctionElement;
        }
        if(prevPtr == NULL){
            pNew->nextFunctionElement = firstElement;
            firstElement = pNew;
        }
        else{
            prevPtr->nextFunctionElement = pNew;
            pNew->nextFunctionElement = currentPtr;
        }
        return 1;
    }
    else{
        return 0;
    }
}

/// @brief Function to riorganize the list of functions renumbering the IDs.
/// @details This function iterates through the list and assigns new IDs to each function in order.
void FunctionList::sortID() {
    FunctionElementsPtr currentPtr = firstElement;
    int newID = 0;
    while (currentPtr != NULL) {
        currentPtr->ID = newID; // Assign new ID
        newID++;
        currentPtr = currentPtr->nextFunctionElement; // Move to the next element
    }
}

/// @brief Function to delete a function from the list.
/// @param id The ID of the function to be deleted.
/// @return true if the function was deleted successfully, false otherwise.
/// @details This function searches for the function with the given ID and deletes it from the list.
bool FunctionList::deleteFunction(int id) {
    FunctionElementsPtr currentPtr = firstElement;
    FunctionElementsPtr prevPtr = NULL;

    while (currentPtr != NULL && currentPtr->ID != id) {
        prevPtr = currentPtr;
        currentPtr = currentPtr->nextFunctionElement;
    }

    if (currentPtr == NULL) {
        return 0;
    } else {
        if (prevPtr == NULL) {
            firstElement = currentPtr->nextFunctionElement;
        } else {
            prevPtr->nextFunctionElement = currentPtr->nextFunctionElement;
        }
        delete currentPtr->funzione; // Assuming funzione is dynamically allocated
        delete currentPtr;
        sortID(); // Reorganize the list after deletion
        return 1;
    }
}

/// @brief Function to delete all functions from the list.
/// @return true if all functions were deleted successfully, false otherwise.
/// @details This function iterates through the list and deletes each function and its corresponding element.
bool FunctionList::deleteAllFunctions() {
    FunctionElementsPtr currentPtr = firstElement;
    FunctionElementsPtr nextPtr;

    while (currentPtr != NULL) {
        nextPtr = currentPtr->nextFunctionElement;
        delete currentPtr->funzione; // Assuming funzione is dynamically allocated
        delete currentPtr;
        currentPtr = nextPtr;
    }
    firstElement = NULL; // Set the first element to NULL after deletion
    return 1;
}

/// @brief Function to select a function by ID and evaluate it at a given x.
/// @param id The ID of the function to be selected.
/// @param x The value at which to evaluate the function.
/// @details This function searches for the function with the given ID and evaluates it at the specified x.
void FunctionList::selectFunction(int id, double x) {
    FunctionElementsPtr currentPtr = firstElement;
    while (currentPtr != NULL) {
        if (currentPtr->ID == id) {
            cout << "Function with ID " << id << " evaluated at x = " << x << ": ";
            cout << currentPtr->funzione->GetValue(x) << endl; // Assuming Evaluate is a method of Function
            return;
        }
        currentPtr = currentPtr->nextFunctionElement;
    }
    cout << "Function with ID " << id << " not found.\n";
}

/// @brief Function to show the list of functions.
/// @details This function iterates through the list of functions and prints their details.
void FunctionList::showFunctionsList() {
    // Implementation for showing the list of functions
    if (firstElement == NULL) {
        cout << "No functions available.\n";
        return;
    }
    FunctionElementsPtr currentPtr = firstElement;
    cout << "ID:\t" << "Type:\t\t" << "Function:\n";
    cout << "-------------------------------------\n";
    while (currentPtr != NULL) {
        cout << currentPtr->ID << "\t";
        switch (currentPtr->type) {
            case POLY:
                cout << "Polynomial\t";
                break;
            case LOG:
                cout << "Logarithmic\t";
                break;
            case POW:
                cout << "Power\t\t";
                break;
            default:
                cout << "Unknown\t\t";
                break;
        }
        currentPtr->funzione->Dump();
        cout << endl;
        currentPtr = currentPtr->nextFunctionElement;
    }
}
