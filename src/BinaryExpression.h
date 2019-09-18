#pragma once

#pragma once
#include <vector>
#include <string>

#include "Expression.h"


/*
	Binary Expression
	Takes two other expressions and operation in constructor, and then does corresponding operation to them
*/

class BinaryExpression : public Expression {
public:
	char m_operation; // '+', '-', '*', '/'
	Expression* m_first;
	Expression* m_second;


	BinaryExpression(char operation, Expression* first, Expression* second) : m_operation(operation), m_first(first), m_second(second) {}


	//Calculate expression
	double eval() {
		switch (m_operation)
		{
		case '+':
			return m_first->eval() + m_second->eval();
		case '-':
			return m_first->eval() - m_second->eval();
		case '*':
			return m_first->eval() * m_second->eval();
		case '/':
			return m_first->eval() / m_second->eval();

		default:
			return m_first->eval() + m_second->eval();
		}
	}

};