#include "lexerClass.h"
using namespace std;

//checks if the read in chars are separators
bool Lexer::isSeparator(char c)
{
	switch (c)
	{
	case '[':
	case ']':
	case '(':
	case ')':
	case '{':
	case '}':
	case ',':
	case ';':
	case '!':
	case '\'':
		return true;
	default:
		return false;
	}
}

//checks if the read in chars are operators
bool Lexer::isOperator(char c)
{
	switch (c)
	{
	case '=':
	case '*':
	case '-':
	case '+':
	case '/':
	case '%':
	case '<':
	case '>':
		return true;
	default:
		return false;
	}
}

//checks if the lexeme is a reserved word
bool Lexer::isReservedWord(string r)
{
	if (r == "int" || r == "char" || r == "float" || r == "bool")
	{
		return true;
	}
	else
	{
		return false;
	}
}

//reads through the file
void Lexer::readFile(fstream &file)
{
	if (!file.is_open()) //if file can't open
	{
		cout << "Cannot open file\n";
	}
	else //if it can be opened
	{
		char c1;
		while (file.get(c1)) //reads the txt file one char at a time
		{
			//gets rid of white spaces
			if (isspace(c1) && lexeme.size() == 0)
			{
				continue;
			}

			changeState(c1); //changes the state based off of input c1 and FA(stateArr)
			lexeme.push_back(c1); //pushes the c1 into lexeme
			c1 = file.peek(); //peeks at the next char
			
			//if the next char is an operator or separator or space,
			//indicates that the lexeme is complete
			//if the state is 6 or 7, lexeme is an operator or separator
			if (isOperator(c1) || isSeparator(c1) || currentState == 6 || currentState == 7 || isspace(c1))
			{
				token_lex_pair temp; //makes an instance of the struct with a lexeme and token
				if (currentState == 1) //if state is 1, it's an integer
				{
					temp.lex = lexeme;
					temp.token = "INTEGER NUMBER";
				}
				else if (currentState == 3) //state 3 == float
				{
					temp.lex = lexeme;
					temp.token = "FLOAT";
				}
				else if (currentState == 4) //state 4 == not a real number
				{
					temp.lex = lexeme;
					temp.token = "NOT REAL NUMBER";
				}
				else if (currentState == 5) //if state is 5, check if lexeme is an identifier or reserved word
				{
					temp.lex = lexeme;
					if (isReservedWord(lexeme)) //inserts lexeme into reserved word function to check
					{
						temp.token = "RESERVED WORD";
					}
					else //if isReservedWord is false
					{
						temp.token = "IDENTIFIER";
					}
				}
				else if (currentState == 6 || currentState == 7) //state 6 or 7 == operator or separator
				{
					temp.lex = lexeme;
					temp.token = "SPECIAL CHARACTER";
				}
				else if (currentState == 8) //if lexeme has other symbols that make it invalid
				{
					temp.lex = lexeme;
					temp.token = "INVALID TOKEN";
				}
				tlp.push_back(temp); //pushes the lexeme and token into the vector tlp
				currentState = 0; //resets the state to 0
				lexeme.clear(); //clears the lexeme
			}
		}
	}
}

//prints the vector with the lexeme and token
void Lexer::printVector()
{
	for (int i = 0; i < tlp.size(); i++)
	{
		cout << tlp[i].lex << "\t" << tlp[i].token << endl;
	}
}

//function that uses the stateArr to change the state of the read in chars in text file
void Lexer::changeState(char c)
{
	if (isdigit(c)) //if it is a digit
	{
		currentState = stateArr[currentState][0];
	}
	else if (c == '.') //if is is a period/decimal point
	{
		currentState = stateArr[currentState][1];
	}
	else if (isalpha(c)) //if it is a letter
	{
		currentState = stateArr[currentState][2];
	}
	else if (isSeparator(c)) //if it is a separator
	{
		currentState = stateArr[currentState][3];
	}
	else if (isOperator(c)) //if it's an operator
	{
		currentState = stateArr[currentState][4];
	}
	else //if it is anything else
	{
		currentState = stateArr[currentState][5];
	}
}