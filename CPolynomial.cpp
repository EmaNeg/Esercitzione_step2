/*! @file CPolynomial.cpp
	@brief Implementation of Polynomial class 
	@author Emanuele Negrino and Carlo Toscano
*/ 

#include "CPolynomial.h"

/// @brief Default Constructor of Polynomial class
Polynomial::Polynomial() {
	cout << "Polynomial constructor" << endl;
	degree=-1;
	coeff = NULL;
}

/// @brief Constructor of Polynomial class
/// @details This constructor creates a polynomial with the coefficients given in the array.
///	@param coefficients array with the coefficients (format: c0+c1*x+ ...)
///	@param size size of the array
Polynomial::Polynomial(const double* coefficients, int size) {

	cout << "Polynomial constructor" << endl;
	degree = -1;
	coeff = NULL;

	SetPolynomial(coefficients,size);
}

/// @brief Destructor of Polynomial class
/// @details This destructor deletes the coefficients of the polynomial.
Polynomial::~Polynomial() {

    cout << "Polynomial destructor" << endl;
	if (coeff != NULL) {
		delete coeff;
		coeff = NULL;
	}
}

/// @brief Copy Constructor of Polynomial class
Polynomial::Polynomial(const Polynomial& p) {
	
	cout << "Polynomial copy constructor" << endl;
	int i;
	
	if (p.coeff == NULL) {
		ErrorMessage("Copy constructor: the object to be copied has no coefficients");
		exit(-1);
	}
	degree = p.degree;
	coeff = new double[static_cast<size_t>(degree + 1)];
	if (coeff == NULL) {
		ErrorMessage("Copy constructor: cannot allocate memory");
		exit(-1);
	}
	
    for (i=0;i<=degree;i++)
		coeff[i]= p.coeff[i];
}


/// @brief Overload Operator =
/// @details This operator copies the coefficients of the polynomial p into the current object.
///	@param p the polynomial to be copied
Polynomial& Polynomial::operator=(const Polynomial& p) {
    
	int i; 
	
	if (this != &p) {
		if (coeff != NULL)
			delete coeff;
        degree = p.degree;
        coeff = new double[static_cast<size_t>(degree + 1)];
		if (coeff == NULL) {
			ErrorMessage("Operator =: cannot allocate memory");
			exit(-1);
		}
        for (i=0;i<=degree;i++)
			coeff[i]= p.coeff[i];
    }
    return *this;
}

/// @brief Overload Operator ==
/// @details This operator checks if two polynomials are equal.
///	@param p the polynomial to be compared with
bool Polynomial::operator==(const Polynomial& p) {
	
	int i;
	
	if (degree != p.degree)
		return false;
	
	for (i=0; i<=degree; i++) {
		if (coeff[i] != p.coeff[i])
			return false;
	}
	
	return true;
	
}

/// @brief Sets the coefficients of the polynomial 
///	@param coefficients array with the coefficients (format: c0+c1*x+ ...)
///	@param size size of the array
void Polynomial::SetPolynomial(const double* coefficients, int size) {
	
	int i= 0;
	
	if (size < 1) {
		ErrorMessage("SetPolynomial: the degree of the Polynomial cannot be negative");
		exit(-1);
	}
	
	if (coeff != NULL)
		Reset();
	
	degree = size - 1;
    coeff = new double[static_cast<size_t>(size)];
	if (coeff == NULL) {
		ErrorMessage("SetPolynomial: cannot allocate memory");
		exit(-1);
	}
	
	for (i=0;i<=degree;i++)
		coeff[i]= coefficients[i];
	
}

/// @brief Returns the value of the function, given an input 
///	@param in the input, "x" in the function
///	@return the value of the function
double Polynomial::GetValue(double in) const {
        
		int i;
		double x = in;
		double result = 0.0;
        
		result = coeff[0];
		for (i=1; i<=degree; i++) {
			result += coeff[i]*x;
			x *= in;			/* x^i */
		}
        
		return result;
}

/// @brief Resets the polynomial 
/// @details This function deletes the coefficients of the polynomial and sets the degree to -1.
void Polynomial::Reset() {
	
	degree = -1; 
	if (coeff != NULL) {
		delete coeff;
		coeff = NULL;
	}
}


/// @brief Writes an error message 
/// @param string message to be printed
void Polynomial::ErrorMessage(const char *string) {
	
	cout << endl << "ERROR -- Polynomial --";
	cout << string << endl;

}

/// @brief Writes a warning message 
/// @param string message to be printed
void Polynomial::WarningMessage(const char *string) {
	
	cout << endl << "WARNING -- Polynomial --";
	cout << string << endl;

}

/// @brief Gives the status of the object 
void Polynomial::Dump() {

	int i;
	
	if (degree == -1) {
		cout << "Uninitialized polynomial" << endl;
		return;
	}
	
	if (coeff == NULL) {
		cout << "Degree: " << degree << endl;
		cout << "No coefficients available" << endl;
		return;
	}
	
	cout << "Polynomial function: ";
    for (i = 0; i <= degree; ++i) {
		if (coeff[i] != 0.) {
			cout << (coeff[i] > 0 && i > 0 ? " +" : " ") << coeff[i];
                if (i > 0) {
                    cout << "x";
                    if (i > 1) 
                        cout << "^" << i;
                }
        }
    }
	cout << endl << endl;

}
