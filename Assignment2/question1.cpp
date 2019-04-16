#include <iostream>
#include <string>
using namespace std;

//the array represents the possible inputs that can be accepted according to the language
//first column represents input 'a'
//second column represents input 'b'
//third column represents any other input
//2 and 3 are the accepting states; 1 and 4 are unacceptable states
int arr[5][3] = { {1, 2, 4}, {1, 3, 4}, {4, 2, 4}, {4, 4, 4}, {4, 4, 4} };
string word;
char choice;

int main()
{
	cout << "Given : L=aa*b | bb*" << endl;

	do
	{
		int state = 0; //starts the initial state to be 0
		cout << "  Enter a word to check: ";
		getline(cin, word);

		for (int i = 0; i < word.size(); i++)
		{
			if (word[i] == 'a') //checks if the characters are 'a'
			{
				state = arr[state][0];
			}
			else if (word[i] == 'b') //checks if the characters are 'b'
			{
				state = arr[state][1];
			}
			else //checks if characters are anything other than 'a' or 'b'
			{
				state = arr[state][2];
			}
		}

		if (state == 1 || state == 4) //1 and 4 are unacceptable states
		{
			cout << "    REJECTED: Word is not part of the language" << endl;
			cout << "    Continue(y/n)? ";
			cin >> choice;
			cin.ignore();
		}
		else if (state == 2 || state == 3) //2 and 3 are acceptable states
		{
			cout << "    ACCEPTED: Word is part of the language" << endl;
			cout << "    Continue(y/n)? ";
			cin >> choice;
			cin.ignore();
		}

	} while (choice == 'y' || choice == 'Y');

	system("pause");
	return 0;
}
