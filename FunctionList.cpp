/*! @file FunctionList.cpp
    @brief Implementation of the FunctionList class
    @details This file contains the implementation of the FunctionList class, which manages a list of functions.
    @author Emanuele Negrino and Carlo Toscano
*/

#include "FunctionList.h"

using namespace std;

FunctionList::FunctionList() {
    // Constructor implementation
    firstElement = NULL; // Initialize the first element to NULL
}

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

FunctionList::~FunctionList() {
    // Destructor implementation
    deleteAllFunctions(); // Clean up all functions when the list is destroyed
    delete firstElement; // Delete the first element pointer
}

int searchID(FunctionElementsPtr firstElement) {
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

bool FunctionList::addFunction(Function *f) {
    FunctionElementsPtr pNew = new FunctionElements;
    FunctionElementsPtr prevPtr;
    FunctionElementsPtr currentPtr;
    if(pNew != NULL && f != NULL){
        pNew->ID=searchID(firstElement);
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
        return 1;
    }
}

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
        currentPtr = currentPtr->nextFunctionElement;
    }
}
