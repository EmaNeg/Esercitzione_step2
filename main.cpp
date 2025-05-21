/*! @file main.cpp
    @brief Main function for the program
    @author Emanuele Negrino and Carlo Toscano
*/ 

#include "Interface.h"
#include "CPower.h"
#include "CLogarithmic.h"
#include "CPolynomial.h"

using namespace std;

int main() {
    
    Menu menu;
    FunctionList functionList;

    int choice = 0;

    do {

        menu.display();
        
        // Get user choice
        choice = menu.getUserChoice();
        
    } while (manageUserChoice(choice, functionList)); 
    
    return 0;
}
