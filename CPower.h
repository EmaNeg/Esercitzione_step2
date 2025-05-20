/*! @file CPower.h
    @brief A class for Power functions 
    @author Emanuele Negrino and Carlo Toscano
*/ 

#ifndef POWER_H
#define POWER_H

#include <iostream>
#include <cmath>
#include <cstring>

#include "CFunction.h"

using namespace std;

/*! @class Power
    @brief A class for power functions 
    @details This class implements a power function of the form: k*x^e.
*/
class Power : public Function {

private:
    /// @name MEMBERS VARIABLEs
    /// @{
    double k_coeff;
    double e_coeff;
    /// @}

public:

    /// @name CONSTRUCTORs and DESTRUCTOR 
    /// @{
    Power();
    Power(double k, double e);
    Power(const Power& p);
    ~Power();
    /// @}

    /// @name OPERATORS 
    /// @{
    Power& operator=(const Power& p);
    bool operator==(const Power& p);
    /// @}

    /// @name GETTERs and SETTERs
    /// @{
    void SetPower(double k, double e);
    double GetValue(double in) const;
    int getType() const;
    /// @}

    /// @name DEBUG and SERIALIZATION 
    /// @{
    void ErrorMessage(const char *string); 
    void WarningMessage(const char *string);
    void Dump();
    /// @}

};

#endif
