/*! @file CLogarithmic.cpp
    @brief Implementation of Logarithmic class 
    @author Emanuele Negrino and Carlo Toscano
*/

#include <math.h>
#include "CLogarithmic.h"

enum{POLY, LOG, POW};

/// @brief Default Constructor of Power class
Logarithmic::Logarithmic() {
    k_coeff = 0;
    b_coeff = -1;
}

/// @brief Constructor of Logarithmic class
/// @details This constructor creates a logarithmic function with the coefficients given.
///	@param k coefficient of the logarithmic function
///	@param b base of the logarithmic function
Logarithmic::Logarithmic(double k, double b) {
    SetLogarithmic(k, b);
}

/// @brief Copy Constructor of Logarithmic class
/// @param l the logarithmic function to be copied
Logarithmic::Logarithmic(const Logarithmic& l) {
    k_coeff = l.k_coeff;
    b_coeff = l.b_coeff;
}

/// @brief Destructor of Logarithmic class
Logarithmic::~Logarithmic() {
}

/// @brief Assignment operator of Logarithmic class
/// @details This operator copies the coefficients of the Logarithmic function l into the current object.
///	@param l the Logarithmic function to be copied
Logarithmic& Logarithmic::operator=(const Logarithmic& l) {
    if(this != &l){
        k_coeff = l.k_coeff;
        b_coeff = l.b_coeff;
    }
    return *this;
}

/// @brief Equality operator of Logarithmic class
/// @details This operator checks if two Logarithmic functions are equal.
///	@param l the Logarithmic function to be compared with
bool Logarithmic::operator==(const Logarithmic& l) {
    return (k_coeff == l.k_coeff && b_coeff == l.b_coeff);
}

/// @brief Sets the coefficients of the Logarithmic function
///	@param k coefficient of the Logarithmic function
///	@param b exponent of the Logarithmic function
void Logarithmic::SetLogarithmic(double k, double b) {

    if(b<=0 && b != -1){
        ErrorMessage("The base must be >0 and not equal to 1");
        exit(-1);
    }
    k_coeff = k;
    b_coeff = b;
}

/// @brief Returns the value of the function, given an input
///	@param in the input, "x" in the function
///	@return the value of the function
double Logarithmic::GetValue(double in) const {
    if(in <= 0){
        cout << "The logarithm is not defined for x <= 0" << endl;
        exit(-1);
    }
    return k_coeff * (log(in) / log(b_coeff));
}

/// @brief Returns the type of the function
/// @return the type of the function
int Logarithmic::getType() const {
    return LOG;
}

/// @brief Error message function
/// @param string message to be printed
void Logarithmic::ErrorMessage(const char *string) {
    cout << endl << "ERROR -- Logarithmic --";
    cout << string << endl;
}

/// @brief Warning message function
/// @param string message to be printed
void Logarithmic::WarningMessage(const char *string) {
    cout << endl << "WARNING -- Logarithmic --";
    cout << string << endl;
}

/// @brief Gives the status of the object
void Logarithmic::Dump() {
    if(b_coeff == -1){
        cout << "Uninitialized logarithmic" << endl;
    }
    else
    {
        cout << k_coeff << "*log_" << b_coeff << " (x)";
    }
}
