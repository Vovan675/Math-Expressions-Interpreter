#pragma once
#include <vector>
#include <string>

#include "TokenTypes.h"
#include "Token.h"


/*
	Tokenizer (Lexer)
	Gets a string and then split it into a corresponding tokens 
	i.e str="50+30"; output=[Token(NUMBER, 50), Token(PLUS, 0), TOKEN(NUMBER, 30)]
*/

class Tokenizer {

public:
	int currentPosition; //Position of the current character
	std::string currentString; //String to tokenize


	std::vector<Token> m_tokens; //There will be tokens for a given string


	Tokenizer() : currentPosition(0), currentString("") {}


	//Main method. Tokenizes and returns tokens for a given string
	std::vector<Token> tokenize(std::string str) {
		m_tokens.clear(); //Clear tokens array

		currentPosition = 0; //Set current position to zero
		currentString = str; //Set current string to given

		//While not the end of a string
		while (currentPosition < currentString.length()) {
			
			//if digit, then add digit token, otherwise add another tokens...
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
			nextChar(); //Increase current position
		
		}

		
		return m_tokens; //Return tokens (it also stored in class instance's variable)
	}


private:
	

	//Parse next characters and returns corresponding token
	Token tokenizeDigit() {
		std::string digitStr = "";

		//While current character is digit...
		while(true) {
			if (isDigit(peek(0))) {
				digitStr += peek(0); //Add current char(part of number) to string
				nextChar(); //Increase position
			}
			//If current char isn't digit
			else {
				break;
			}
		}
		currentPosition--;
		return Token(NUMBER, std::stoi(digitStr));
	}


	//Returns characher with position (currentPosition+1)
	char nextChar() {
		return currentString[currentPosition++];
	}


	//Returns characher with position (currentPosition+rel)
	char peek(int rel) {
		return currentString[currentPosition] + rel;
	}


	//Returns true if ch is a digit
	bool isDigit(char ch) {
		if (ch >= '0' && ch <= '9') {
			return true;
		}
		return false;
	}

	//Returns true if ch is a word (Not used function!!!)
	bool isWord(char ch) {
		if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')) {
			return true;
		}
		return false;
	}

};