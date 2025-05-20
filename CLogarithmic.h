/*! @file CLogarithmic.h
    @brief A class for Logarithmic functions 
    @author Emanuele Negrino and Carlo Toscano
*/

#ifndef LOGARITHMIC_H
#define LOGARITHMIC_H

#include <iostream>
#include <cmath>
#include <cstring>

#include "CFunction.h"

using namespace std;

/*! @class Logarithmic
    @brief A class for power functions 
    @details This class implements a power function of the form: k*x^e.
*/

class Logarithmic : public Function {

private:
    /// @name MEMBERS VARIABLEs
    /// @{
    double k_coeff;
    double b_coeff;
    /// @}

public:

    /// @name CONSTRUCTORs and DESTRUCTOR 
    /// @{
    Logarithmic();
    Logarithmic(double k, double b);
    Logarithmic(const Logarithmic& l);
    ~Logarithmic();
    /// @}

    /// @name OPERATORS 
    /// @{
    Logarithmic& operator=(const Logarithmic& l);
    bool operator==(const Logarithmic& l);
    /// @}

    /// @name GETTERs and SETTERs
    /// @{
    void SetLogarithmic(double k, double b);
    double GetValue(double in) const;
    /// @}

    /// @name DEBUG and SERIALIZATION 
    /// @{
    void ErrorMessage(const char *string); 
    void WarningMessage(const char *string);
    void Dump();
    /// @}

};


#endif
