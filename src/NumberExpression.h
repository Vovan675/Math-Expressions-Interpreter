#pragma once
#include <vector>
#include <string>

#include "Expression.h"


class NumberExpression : public Expression {
public:
	int m_value;

	NumberExpression(int value) : m_value(value) {}


	double eval() {
		return m_value;
	}

};