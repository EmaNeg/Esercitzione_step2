/*! @file menu.h
    @brief Class for managing a menu
    @details This file contains functions to display a menu and handle user input.
    @author Emanuele Negrino and Carlo Toscano
*/ 

#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <string>
#include <vector>

#include "FunctionList.h"

using namespace std;

/// @class Menu
/// @brief Class for managing a menu
/// @details This class contains functions to display a menu and handle user input.
class Menu {
private:
    /// @name MEMBERS VARIABLEs
    /// @{
    vector<string> options;
    /// @}
public:

    /// @name CONSTRUCTORS
    /// @{
    Menu();
    ~Menu();
    /// @}

    /// @name MEMBER FUNCTIONS
    /// @{
    void display();
    int getUserChoice();
    /// @}
};

/// @name FUNCTIONS
/// @{
void insertFunction(FunctionList &functionList);
void showFunctionsList(FunctionList &functionList);
void deleteFunction(FunctionList &functionList);
bool deleteAllFunctions(FunctionList &functionList);
void selectFunction(FunctionList &functionList);
int manageUserChoice(int choice, FunctionList &functionList);
/// @}

#endif // MENU_H
