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

enum{POLY, LOG, POW};

using namespace std;

/*! @struct FunctionElements
    @brief Structure for storing function elements
    @details This structure contains the ID, type, and pointer to the function.
*/
typedef struct functionElements {
    /// @name MEMBERS VARIABLEs
    /// @{
    int ID;
    int type;
    Function *funzione;
    struct functionElements *nextFunctionElement;
    /// @}
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
    /// @name CONSTRUCTORS
    /// @{
    FunctionList();
    FunctionList(Function *function);
    ~FunctionList();
    /// @}

    /// @name MEMBER FUNCTIONS
    /// @{
    bool addFunction(Function *f);
    bool deleteFunction(int id);
    bool deleteAllFunctions();
    void selectFunction(int id, double x);
    void showFunctionsList();
    int searchID();
    void sortID();
    /// @}
};

#endif // FUNCTIONLIST_H
