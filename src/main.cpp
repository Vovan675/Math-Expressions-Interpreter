#include <iostream>
#include <string>
#include <vector>

#include <boost/algorithm/string.hpp>


#include "TokenTypes.h"
#include "Token.h"

#include "Expression.h"


#include "Tokenizer.h"
#include "Parser.h"



using namespace std;


int main() {

	while (true) {
		Tokenizer tokenizer;
		string str;
		getline(cin, str);
		vector<Token> tokens = tokenizer.tokenize(str);


		for (int i = 0; i < tokens.size(); i++) {
			//cout << tokens.at(i).m_type << " " << tokens.at(i).m_value << endl;
		}


		Parser parser;
		Expression* expressions = parser.parse(tokens);

		cout << expressions->eval() << endl;

		system("pause");
	}
	return 0;
}