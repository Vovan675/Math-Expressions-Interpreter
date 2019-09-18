#pragma once
#include <vector>
#include <string>

#include "TokenTypes.h"
#include "Token.h"

#include "Expression.h"
#include "NumberExpression.h"
#include "UnaryExpression.h"
#include "BinaryExpression.h"




class Parser {
public:
	int currentPosition;
	std::vector<Token> m_tokens;

	Parser() {};

	Expression* parse(std::vector<Token> tokens) {
		currentPosition = 0;
		m_tokens = tokens;
		return expression();
	}

	
	Expression* expression() {
		return addition();
	}

	Expression* addition() {
		Expression* expr = multiplication();
		while (true) {
			if (match(peek(0), PLUS)) {
				expr = new BinaryExpression('+', expr, multiplication());
			}
			else if (match(peek(0), MINUS)) {
				expr = new BinaryExpression('-', expr, multiplication());
			}
			else {
				break;
			}
		}

		return expr;
	}


	Expression* multiplication() {
		Expression* expr = negating();
		while (true) {
			if (match(peek(0), MULTIPLICATION)) {
				expr = new BinaryExpression('*', expr, negating());
			}
			else if (match(peek(0), DIVISION)) {
				expr = new BinaryExpression('/', expr, negating());
			}
			else {
				break;
			}


		}
		return expr;
	}

	
	Expression* negating() {
		Expression* expr;
		if (match(peek(0), PLUS)) {
			expr = new UnaryExpression('+', number());
		}
		else if (match(peek(0), MINUS)) {
			expr = new UnaryExpression('-', number());
		}
		else {
			expr = number();
		}

		return expr;
	}
	

	Expression* number() {
		Token token = peek(0);
		if (match(token, NUMBER)) {
			return new NumberExpression(token.m_value);
		}
		else if (match(token, LPAREN)) {
			Expression* exprInParen = addition();
			currentPosition++;
			return exprInParen;
		}

	}


	bool match(Token token, int type) {
		if (token.m_type == type) {
			currentPosition++;
			return true;
		}
		return false;
	}

	Token peek(int rel) {
		if (currentPosition + rel >= m_tokens.size()) {
			return Token(EOF, 0);
		}
		return m_tokens.at(currentPosition + rel);
	}

	



private:


};