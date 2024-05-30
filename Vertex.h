#pragma once
#include <stdlib.h>
#include <list>
#include "eVertexColor.h"

using namespace std;

class Vertex
{
private:
	// List of neighboring vertices
	list<int> neighborsList;
	
	eVertexColor color;
	int indexOfRakah;

public:
	// Constructor to initialize a vertex with default values
	Vertex() { neighborsList = list<int>(); color = WHITE; indexOfRakah = -1; }

	inline eVertexColor GetColor()const { return color; }
	inline void SetColor(eVertexColor c) { color = c; }
	inline int GetRakahIndex() { return indexOfRakah; }
	inline void SetRakahIndex(int index) { indexOfRakah = index; }
	inline const list<int>& GetNeighborsList()const { return neighborsList; }
	inline bool HasNeighbors() { return neighborsList.empty() == false; }
	inline void AddNeighbor(int neighbor) { neighborsList.push_back(neighbor); }
	inline void RemoveNeighbor(int neighbor) { neighborsList.remove(neighbor); }

};
