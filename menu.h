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

class Menu {
private:
    vector<string> options;
    FunctionList functionList;
public:
    void displayMenu();
    int getUserChoice();
};

void insertFunction();
void deleteFunction();
void deleteAllFunctions();
void selectFunction();
int manageUserChoice(int choice);
void showFunctionsList();
void clearInputBuffer();
void clearScreen();

#endif // MENU_H
