/*! @file CPolynomial.h
	@brief A class for Polynomial functions 
	@author Emanuele Negrino and Carlo Toscano
*/ 

#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <iostream>
#include <cmath>
#include <cstring>

#include "CFunction.h"

using namespace std;

/*! @class Polynomial
	@brief A class for polynomial functions 
	@details This class implements a polynomial function of the form: c0 + c1*x + c2*x^2 + ... + cn*x^n.
*/
class Polynomial : public Function {

private:
	/// @name MEMBERS VARIABLEs
    /// @{
    double* coeff;
    int degree;
	/// @}

public:
    
	/// @name CONSTRUCTORs and DESTRUCTOR 
	/// @{
    Polynomial();
	Polynomial(const double* coefficients, int size);
    Polynomial(const Polynomial& p);
    ~Polynomial();
	/// @}

	/// @name OPERATORS 
	/// @{
    Polynomial& operator=(const Polynomial& p);
	bool operator==(const Polynomial& p);
	/// @}

	/// @name GETTERs and SETTERs
	/// @{}
	void SetPolynomial(const double* coefficients, int size);
    double GetValue(double in) const;
	/// @}
	
	void Reset();

	/// @name DEBUG and SERIALIZATION 
	/// @{
	void ErrorMessage(const char *string); 
	void WarningMessage(const char *string);
	void Dump();
	/// @}

};

#endif
