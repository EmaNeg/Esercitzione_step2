/*! @file FunctionList.cpp
    @brief Implementation of the FunctionList class
    @details This file contains the implementation of the FunctionList class, which manages a list of functions.
    @author Emanuele Negrino and Carlo Toscano
*/

#include "FunctionList.h"

using namespace std;


FunctionList::FunctionList() {
    // Constructor implementation
}

FunctionList::FunctionList(Function *function) {
    // Constructor implementation
    FunctionElementsPtr pNew = new FunctionElements;
    pNew->ID = 0; // Initialize ID to 0
    pNew->funzione = function; // Assign the function pointer
    pNew->nextFunctionElement = NULL; // Initialize next pointer to NULL

    firstElement = pNew; // Set the first element to the new function
}

FunctionList::~FunctionList() {
    // Destructor implementation
    deleteAllFunctions(); // Clean up all functions when the list is destroyed
}

int searchID(FunctionElementsPtr firstElement) {
    FunctionElementsPtr currentPtr = firstElement;
    int maxID = 0;
    while(currentPtr != NULL){
        if(currentPtr->ID > maxID){
            maxID = currentPtr->ID;
        }
        currentPtr = currentPtr->nextFunctionElement;
    }
    return maxID;
}

bool FunctionList::addFunction(FunctionElementsPtr *firstElement, Function *f) {
    FunctionElementsPtr pNew = new FunctionElements;
    FunctionElementsPtr prevPtr;
    FunctionElementsPtr currentPtr;
    if(pNew != NULL){
        pNew->ID=searchID(*firstElement);
        pNew->funzione = f;

        pNew->nextFunctionElement = NULL;
        prevPtr = NULL;
        currentPtr = *firstElement;
        while(currentPtr!=NULL){
            prevPtr = currentPtr;
            currentPtr = currentPtr->nextFunctionElement;
        }
        if(prevPtr == NULL){
            pNew->nextFunctionElement = *firstElement;
            *firstElement = pNew;
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

void FunctionList::deleteFunction() {
    // Implementation for deleting a function
    cout << "Delete a function:\n";
}

void FunctionList::deleteAllFunctions() {
    // Implementation for deleting all functions
    cout << "Delete all functions:\n";
    FunctionElementsPtr currentPtr = firstElement;
    FunctionElementsPtr nextPtr;

    while (currentPtr != NULL) {
        nextPtr = currentPtr->nextFunctionElement;
        delete currentPtr->funzione; // Assuming funzione is dynamically allocated
        delete currentPtr;
        currentPtr = nextPtr;
    }
    firstElement = NULL; // Reset the list to empty
}

void FunctionList::selectFunction() {
    // Implementation for selecting a function
    cout << "Select a function:\n";
}

void FunctionList::showFunctionsList() {
    // Implementation for showing the list of functions
    cout << "List of functions:\n";
    FunctionElementsPtr currentPtr = firstElement;
    while (currentPtr != NULL) {
        cout << "Function ID: " << currentPtr->ID << endl;
        currentPtr = currentPtr->nextFunctionElement;
    }
}