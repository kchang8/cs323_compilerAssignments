#include <iostream>
#include <string>
#include <stack>
using namespace std;

string postfix;
char choice;
int num, num1, num2, result;

stack<int> myStack; //makes a stack that stores integers

int main()
{
	do
	{
		cout << "Enter a postfix expression: ";
		getline(cin, postfix);

		for (int i = 0; i < postfix.size(); i++)
		{
			if (isalpha(postfix[i])) //checks if the characters are letters
			{
				cout << "  Enter the value of " << postfix[i] << ": ";
				cin >> num;
				postfix[i] = num; //make the user input number be the array index value
				cin.ignore();

				myStack.push(postfix[i]); //push the number into the stack
			}
			else //checks if the characters are any of the operators
			{
				if (postfix[i] == '*') //multiplication
				{
					num1 = myStack.top(); //stores the top value of the stack in num1
					myStack.pop(); //removes the value from the stack
					num2 = myStack.top(); //stores the new top value of the stack into num2
					myStack.pop(); //remove that value

					result = num1 * num2; //do the math
					myStack.push(result); //push the calculated value into the stack
				}
				else if (postfix[i] == '-') //subtraction
				{
					num1 = myStack.top();
					myStack.pop();
					num2 = myStack.top();
					myStack.pop();

					result = num1 - num2;
					myStack.push(result);
				}
				else if (postfix[i] == '+') //addition
				{
					num1 = myStack.top();
					myStack.pop();
					num2 = myStack.top();
					myStack.pop();

					result = num1 + num2;
					myStack.push(result);
				}
				else if (postfix[i] == '/') //division
				{
					num1 = myStack.top();
					myStack.pop();
					num2 = myStack.top();
					myStack.pop();

					result = num1 / num2;
					myStack.push(result);
				}
			}
		}

		cout << "    Final value = " << myStack.top() << endl; //displays the final answer in the stack
		myStack.pop(); //removes the number from the stack, making it empty
		cout << "  Continue(y/n)? ";
		cin >> choice;
		cin.ignore();

	} while (choice == 'y' || choice == 'Y');

	system("pause");
	return 0;
}