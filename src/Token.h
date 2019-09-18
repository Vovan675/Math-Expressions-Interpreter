#pragma once

class Token {
public:
	unsigned int m_type;
	int m_value;

	Token(int type, int value) : m_type(type), m_value(value) {};

private:


};