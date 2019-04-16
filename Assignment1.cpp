#include <iostream>
#include <string>
using namespace std;

int main()
{
	int stateArr[3][4] = {{ 1, 2, 1, 2 }, { 1, 1, 1, 2 }, { 2, 2, 2, 2 }};
	char choice;
	string id;

	do
	{
		int state = 0;
		cout << "\tEnter a string: ";
		getline(cin, id);

		for (int i = 0; i < id.size(); i++)
		{
			//checks if the char in string is a letter
			if (isalpha(id[i]))
			{
				state = stateArr[state][0];
			}
			//checks if the char is a digit
			else if (isdigit(id[i]))
			{
				state = stateArr[state][1];
			}
			//checks if it's an underscore
			else if (id[0] == '_')
			{
				state = stateArr[state][2];
			}
			else //if it's any other character
			{
				state = stateArr[state][3];
			}
		}

		if (state == 1) //1 is acceptable state
		{
			cout << "\t" << id << " is an identifier" << endl;
			cout << "CONTINUE(y/n)? ";
			cin >> choice;
			cin.ignore();
		}

		else if (state == 2) //2 is unacceptable state
		{
			cout << "\t" << id << " is not an identifier" << endl;
			cout << "CONTINUE(y/n)? ";
			cin >> choice;
			cin.ignore();
		}

	} while (choice == 'y' || choice == 'Y');

	system("pause");
	return 0;
}