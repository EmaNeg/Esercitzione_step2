/*! @file main
    @brief Main function for the program
    @author Emanuele Negrino and Carlo Toscano
*/ 

#include "menu.h"
#include "CPower.h"
#include "CLogarithmic.h"
#include "CPolynomial.h"

using namespace std;

int main() {
    
    Menu menu;
    FunctionList functionList;

    while (true) {

        menu.displayMenu();
        
        // Get user choice
        int choice = menu.getUserChoice();
        
        // Handle user choice
        if (manageUserChoice(choice, functionList) == 0) {
            break; // Exit the loop if the user chooses to exit
        }
        
    }
    
    return 0;
}
