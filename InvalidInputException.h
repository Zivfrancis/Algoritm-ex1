#pragma once
#include <stdlib.h>
#include <string.h>
#include <string>
using namespace std;

// Class to represent an exception for invalid input
class  InvalidInputException
{

public:
	InvalidInputException(){}
	~InvalidInputException(){}

	inline const char* GetMessage()const { return "Invalid input"; }
};