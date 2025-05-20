/*! @file FunctionList.h
    @brief Class for managing a list of functions
    @details This file contains the FunctionList class, which manages a list of functions.
    @author Emanuele Negrino and Carlo Toscano
*/ 

#ifndef FUNCTIONLIST_H
#define FUNCTIONLIST_H

#include <vector>

#include "CPower.h"
#include "CLogarithmic.h"
#include "CPolynomial.h"
#include "CFunction.h"


using namespace std;

typedef struct functionElements {
    int ID;
    Function *funzione;
    struct functionElements *nextFunctionElement;
} FunctionElements;
typedef FunctionElements* FunctionElementsPtr;

/*! @class FunctionList
    @brief Class for managing a list of functions
    @details This class manages a list of functions, allowing for adding, deleting, and selecting functions.
*/
class FunctionList {
private:
    /// @name MEMBERS VARIABLEs
    /// @{
    FunctionElementsPtr firstElement = NULL;
    /// @}
public:
    FunctionList();
    FunctionList(Function *function);
    ~FunctionList();

    bool addFunction(FunctionElementsPtr *p, Function *f);
    void deleteFunction();
    void deleteAllFunctions();
    void selectFunction();
    void showFunctionsList();
};

#endif // FUNCTIONLIST_H
