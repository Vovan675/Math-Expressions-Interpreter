#pragma once
#include <vector>
#include <string>

#include "TokenTypes.h"
#include "Token.h"



class Tokenizer {

public:
	int currentPosition;
	std::string currentString;


	std::vector<Token> m_tokens;


	Tokenizer() : currentPosition(0), currentString("") {}

	std::vector<Token> tokenize(std::string str) {
		m_tokens.clear();

		currentPosition = 0;
		currentString = str;

		while (currentPosition < currentString.length()) {
			
			if (isDigit(peek(0))) {
				m_tokens.push_back(tokenizeDigit());
			}
			else if (peek(0) == '+') {
				m_tokens.push_back(Token(PLUS, 0));
			}
			else if (peek(0) == '-') {
				m_tokens.push_back(Token(MINUS, 0));
			}
			else if (peek(0) == '*') {
				m_tokens.push_back(Token(MULTIPLICATION, 0));
			}
			else if (peek(0) == '/') {
				m_tokens.push_back(Token(DIVISION, 0));
			}
			else if (peek(0) == '(') {
				m_tokens.push_back(Token(LPAREN, 0));
			}
			else if (peek(0) == ')') {
				m_tokens.push_back(Token(RPAREN, 0));
			}
			nextChar();
		
		}


		return m_tokens;
	}


private:
	


	Token tokenizeDigit() {
		std::string digitStr = "";

		while(true) {
			if (isDigit(peek(0))) {
				digitStr += peek(0);
				nextChar();
			}
			else {
				break;
			}
		}
		currentPosition--;
		return Token(NUMBER, std::stoi(digitStr));
	}



	char nextChar() {
		return currentString[currentPosition++];
	}


	char peek(int rel) {
		return currentString[currentPosition] + rel;
	}


	bool isDigit(char ch) {
		if (ch >= '0' && ch <= '9') {
			return true;
		}
		return false;
	}
	bool isWord(char ch) {
		if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')) {
			return true;
		}
		return false;
	}

};