/*! @file CPower.cpp
    @brief Implementation of Power class 
    @author Emanuele Negrino and Carlo Toscano
*/

#include "CPower.h"

enum{POLY, LOG, POW};

/// @brief Default Constructor of Power class
Power::Power() {
    k_coeff = 0.0;
    e_coeff = 0.0;
}

/// @brief Constructor of Power class
/// @details This constructor creates a power function with the coefficients given.
///	@param k coefficient of the power function
///	@param e exponent of the power function
Power::Power(double k, double e) {
    SetPower(k, e);
}

/// @brief Copy Constructor of Power class
Power::Power(const Power& p) {
    k_coeff = p.k_coeff;
    e_coeff = p.e_coeff;
}

/// @brief Destructor of Power class
Power::~Power() {
}

/// @brief Assignment operator of Power class
/// @details This operator copies the coefficients of the power function p into the current object.
///	@param p the power function to be copied
Power& Power::operator=(const Power& p) {
    if (this != &p) {
        k_coeff = p.k_coeff;
        e_coeff = p.e_coeff;
    }
    return *this;
}

/// @brief Equality operator of Power class
/// @details This operator checks if two power functions are equal.
///	@param p the power function to be compared with
bool Power::operator==(const Power& p) {
    return (k_coeff == p.k_coeff && e_coeff == p.e_coeff);
}

/// @brief Check if the exponent is between -1 and 1, transforming the function in a sqrt
/// @param e the exponent
/// @return False if exponent is between -1 and 1, otherways true
bool controlExponent(double e) {
    if(e < 1 && e > -1){
        return true;
    }
    return false;
}

/// @brief Sets the coefficients of the power function
///	@param k coefficient of the power function
///	@param e exponent of the power function
void Power::SetPower(double k, double e) {
    k_coeff = k;
    e_coeff = e;
    if(controlExponent(e)) {
        WarningMessage("Your function become a square root, so x < 0 doesn't exists");
    }
}

/// @brief Returns the value of the function, given an input
///	@param in the input, "x" in the function
///	@return the value of the function
double Power::GetValue(double in) const {
    if(controlExponent(e_coeff) && in < 0) {
        cout << "The function has an exponenent between -1 and 1, so x<0 are not allowed" << endl << flush;
        exit(-1);
    }
    else {
        return k_coeff * pow(in, e_coeff);
    }
}

/// @brief Returns the type of the function
/// @return the type of the function
int Power::getType() const {
    return POW;
}

/// @brief Error message function
/// @param string message to be printed
void Power::ErrorMessage(const char *string) {
    cout << endl << "ERROR -- Power --";
    cout << string << endl;
}

/// @brief Warning message function
/// @param string message to be printed
void Power::WarningMessage(const char *string) {
    cout << endl << "WARNING -- Power --";
    cout << string << endl;
}

/// @brief Gives the status of the object
void Power::Dump() {
    cout << k_coeff << "*x^" << e_coeff;
}
