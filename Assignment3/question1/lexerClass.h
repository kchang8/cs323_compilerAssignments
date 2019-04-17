#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

//makes a struct that contains the lexeme and token to be printed
struct token_lex_pair
{
	string token;
	string lex;
};

class Lexer
{
	private:
		//stateArr contains the states of the FA 
		//column 0 contains the digit inputs, column 1 = decimal point
		//column 2 = letters, column 3 = separators
		//column 4 = operators, column 5 = others
		//accepting states are 1 being integers,
		//state 3 = float, state 5 = identifier, state 6 = separator
		//state 7 = operator
		//first row represents the initial state
		int stateArr[9][6] = { {1, 8, 5, 6, 7, 8}, 
							{1, 2, 8, 8, 8, 8},
							{3, 8, 8, 8, 8, 8}, 
							{3, 4, 4, 8, 8, 8},
							{4, 4, 4, 8, 8, 8}, 
							{5, 8, 5, 8, 8, 8},
							{8, 8, 8, 8, 8, 8}, 
							{8, 8, 8, 8, 8, 8},
							{8, 8, 8, 8, 8, 8} };
		int currentState = 0; //initializes the first state to be 0
		string lexeme; //stores the lexeme being analyzed
		vector<token_lex_pair> tlp; //make a vector that contains the struct data called tlp

	public:
		bool isSeparator(char c); //checks if chars are separators
		bool isOperator(char c); //checks if charas are operators
		bool isReservedWord(string r); //checks if lexeme is a reserved word
		void printVector(); //prints the vector
		void readFile(fstream &file); //function that reads in the file
		void changeState(char c); //changes the state using the stateArr

};
