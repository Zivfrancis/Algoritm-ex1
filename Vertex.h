#pragma once
#include <stdlib.h>
#include <list>
#include "eVertexColor.h"
using namespace std;

class Vertex
{
public:
	list<int> neighborsList;
	
private:
	

public:
	Vertex() { neighborsList = list<int>(); color = WHITE; indexOfRakah = -1; }

	inline eVertexColor GetColor()const { return color; }
	inline void SetColor(eVertexColor c) { color = c; }
	inline int GetRakahIndex() { return indexOfRakah; }
	inline void SetRakahIndex(int index) { indexOfRakah = index; }

private:
	eVertexColor color;
	int indexOfRakah;
};
