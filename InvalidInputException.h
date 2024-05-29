#pragma once
#include <stdlib.h>
#include <string.h>
#include <string>
using namespace std;


class  InvalidInputException
{

public:
	InvalidInputException(){}
	~InvalidInputException(){}

	inline const char* GetMessage()const { return "Invalid input"; }
};



