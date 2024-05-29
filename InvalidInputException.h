#pragma once
#include <stdlib.h>
#include <string.h>
#include <string>
using namespace std;


class  InvalidInputException : exception
{
public:
	 InvalidInputException();
	~ InvalidInputException();

private:
	const char* message = "Invalid input";

public:
	InvalidInputException(){}
	~InvalidInputException(){}

	inline char const* what() const { return message; }

};



