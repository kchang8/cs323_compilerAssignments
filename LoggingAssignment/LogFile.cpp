#include <iostream>
#include "LogHead.h"
using namespace std;

int main()
{
	LogClass file("test.txt");
	time_t cTime;
	time(&cTime);

	file.logOpen();
	cout << "Writing and Reading Log: " << endl;
	file.writeLog(cTime, 41, "logFunc()", "Error", "Invalid Statement");
	file.writeLog(cTime, 22, "logRead()", "Success", "None");
	file.readLog();
	file.flushLog();
	file.logClose();

	system("pause");
	return 0;
}