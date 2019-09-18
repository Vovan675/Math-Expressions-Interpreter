#pragma once
#include <vector>
#include <string>

#include "TokenTypes.h"
#include "Token.h"



/*
	Expression it's the abstract class for all expressions
	Every child must create his own constructor and eval function
*/

class Expression {
public:

	virtual double eval() { return -999999; };



};