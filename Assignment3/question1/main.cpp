#include <iostream>
#include <fstream>
#include "lexerClass.h"
using namespace std;

int main()
{
	Lexer a;
	fstream file("test.txt", ios::in); //makes file of type fstream to take in the txt file
	a.readFile(file);
	a.printVector();

	system("pause");
	return 0;
}