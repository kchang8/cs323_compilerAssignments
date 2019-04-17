#include <iostream>
#include <string>
#include <stack>
using namespace std;

string postfix;
int result, num1, num2;
char choice;

stack<int> myStack; //makes a stack that stores ints called myStack

int main()
{
	do
	{
		cout << "Enter a postfix expression: ";
		getline(cin, postfix);

		for (int i = 0; i < postfix.size(); i++)
		{
			if (postfix[i] == ' ') //loops through the postfix string to check if the chars are spaces
			{
				continue; //continue when it encounters space chars
			}
			else if (isdigit(postfix[i])) //checks if the char is a digit
			{
				int num = 0; //sets the initial num as 0
				//while index i is less than the postfix string length and if the char is a digit
				while (i < postfix.length() && isdigit(postfix[i]))
				{
					//num will be the digit the for loop reads in 
					//current num will multiple by 10 if the next char is another digit
					num = (num * 10) + (postfix[i] - '0');
					i++; //goes to the next index
				}

				i--; //goes back to the previous index
				myStack.push(num); //pushes the number stored in num into the stack
			}
			else //checks if the characters are any of the operators
			{
				if (postfix[i] == '*') //multiplication
				{
					num1 = myStack.top(); //stores the top value of the stack in num1
					myStack.pop(); //removes the value from the stack
					num2 = myStack.top(); //stores the new top value of the stack into num2
					myStack.pop(); //remove that value

					result = num2 * num1; //do the math
					myStack.push(result); //push the calculated value into the stack
				}
				else if (postfix[i] == '-') //subtraction
				{
					num1 = myStack.top();
					myStack.pop();
					num2 = myStack.top();
					myStack.pop();

					result = num2 - num1;
					myStack.push(result);
				}
				else if (postfix[i] == '+') //addition
				{
					num1 = myStack.top();
					myStack.pop();
					num2 = myStack.top();
					myStack.pop();

					result = num2 + num1;
					myStack.push(result);
				}
				else if (postfix[i] == '/') //division
				{
					num1 = myStack.top();
					myStack.pop();
					num2 = myStack.top();
					myStack.pop();

					result = num2 / num1;
					myStack.push(result);
				}
				else if (postfix[i] == '$') //if the loop encounters a '$' in the string
				{
					cout << "	Answer = $" << myStack.top() << endl;
				}
			}
		}

		myStack.pop();
		cout << "CONTINUE(y/n)? ";
		cin >> choice;
		cin.ignore();

	} while (choice == 'y' || choice == 'Y');

	system("pause");
	return 0;
}
