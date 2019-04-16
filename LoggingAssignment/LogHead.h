#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
using namespace std;

class LogClass
{
	public:
		//constructor
		LogClass(string newFile)
		{
			filename = newFile;
		}

		//opens log file
		int logOpen()
		{
			infile.open(filename);
			ofile.open(filename);
			if (!infile.is_open() || !ofile.is_open())
			{
				cout << "Error: logOpen() unsuccessful" << endl;
				return -1;
			}
			else
			{
				cout << "logOpen() successful" << endl;
				return 0;
			}
		}

		//close log file
		int logClose()
		{
			if (infile.is_open() || ofile.is_open())
			{
				infile.close();
				ofile.close();
				cout << "logClose() successful" << endl;
				return 0;
			}
			else
			{
				cout << "Error: logClose() unsuccessful" << endl;
				return -1;
			}
		}

		//reads log file, returns contents of log
		void readLog()
		{
			if (infile.is_open())
			{
				string contentLine;
				while (getline(infile, contentLine, '|'))
				{
					cout << contentLine << " ";
					getline(infile, contentLine, '|');
					cout << contentLine << " ";

					getline(infile, contentLine, '|');
					cout << contentLine << " ";

					getline(infile, contentLine, '|');
					cout << contentLine << " ";

					getline(infile, contentLine);
					cout << contentLine << endl;
				}
			}
		}

		//writes to log file
		void writeLog(time_t currentTime, int lineNum, string funcName, string type, string description)
		{
			string tempT = ctime(&currentTime);
			tempT.erase(tempT.size() - 1, 1);
			ofile << tempT << "|" << lineNum << "|" << funcName << "|" << type << "|" << description << endl;
		}

		//flush last write
		void flushLog()
		{
			ofile << flush;
		}

	private:
		ofstream ofile;
		ifstream infile;
		string filename;
};
