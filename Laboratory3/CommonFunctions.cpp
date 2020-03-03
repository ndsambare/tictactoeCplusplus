#include "Header.h"
#include "Errors.h"
#include <iostream>
#include <string>


int usageFunction(char* programName, string programInfo) {
	cout << programName << endl;
	cout << programInfo;
	return failedUsageMessage;
}
