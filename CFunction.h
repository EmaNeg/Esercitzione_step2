/*! @file CFunction.h
	@brief A virtual base class for functions of a single variable
	@author Negrino Emanuele and Toscano Carlo
*/ 

#ifndef FUNCTION_H
#define FUNCTION_H

#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

/*! @class Function
	@brief A virtual base class for functions of a single variable
	@details This class is the base class for all the functions of a single variable. 
	It contains the interface for the derived classes.
*/
class Function {
	
public:
    
	/// @name CONSTRUCTORS/DESTRUCTOR
	/// @{
    Function(){cout << "Function constructor" << endl;};
    virtual ~Function(){cout << "Function destructor" << endl;};
	/// @}

	/// @name GETTERS
	/// @{
	virtual double GetValue(double in) const =0;
	/// @}

	/// @name DEBUG 
	/// @{
	virtual void Dump()=0;
	/// @}
    
};

#endif
