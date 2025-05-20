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
    // Clear the screen
    clearScreen();
    
    while (true) {
        Menu menu;
        menu.displayMenu();
        
        // Get user choice
        int choice = menu.getUserChoice();
        
        // Handle user choice
        if (manageUserChoice(choice) == 0) {
            break; // Exit the loop if the user chooses to exit
        }
        
        // Clear the input buffer before the next iteration
        clearInputBuffer();
    }
    
    return 0;
}