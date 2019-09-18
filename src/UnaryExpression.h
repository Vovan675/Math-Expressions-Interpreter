#pragma once
#include <vector>
#include <string>

#include "Expression.h"


class UnaryExpression : public Expression {
public:
	char m_operation;
	Expression* m_expr;


	UnaryExpression(char operation, Expression* expr) : m_operation(operation), m_expr(expr) {}


	double eval() {
		switch (m_operation)
		{
		case '+':
			return m_expr->eval();
		case '-':
			return -m_expr->eval();

		default:
			return m_expr->eval();
		}
	}

};