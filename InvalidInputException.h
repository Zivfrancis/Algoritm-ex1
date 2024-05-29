#pragma once
#include <stdlib.h>
#include <string.h>
#include <string>
using namespace std;


class  InvalidInputException : exception
{

private:
	const char* message = "Invalid input";

public:
	InvalidInputException(){}
	~InvalidInputException(){}

	inline const char* GetMessage()const { return message; }

	//inline char const* what() const override { return "Invalid input"; }
};



