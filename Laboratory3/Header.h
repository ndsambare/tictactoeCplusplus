#pragma once
#include <string>
using namespace std;

enum indices { programName, inputName, correctNumArgs = 2, commandLine };

int usageFunction(char *, string);
