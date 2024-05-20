#pragma once
#include <iostream>
using namespace std;

static void errorExit(string message)
{
	cout << message;
	exit(1);
}
