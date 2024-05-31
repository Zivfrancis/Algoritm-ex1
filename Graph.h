#pragma once
#include<iostream>
#include"Vertex.h"
#include"eVertexColor.h"
#include<vector>
using namespace std;

class Graph
{
private:
	// Vector to store all the vertices in the graph
	vector<Vertex> vertices;

	int numberOfVertices;
	int numberOfEdges;
	

public:
	Graph();
	~Graph();

	void MakeEmptyGraph(int numOfVertices);
	bool IsAdjacent(int u, int v)const;
	inline const list<int>& GetAdjList(int u) const{ return vertices[u].GetNeighborsList(); }
	void AddEdge(int u, int v);
	void RemoveEdge(int u, int v) { vertices[u].RemoveNeighbor(v); numberOfEdges--; }
	Graph Transpose()const;
	void AddVertex(Vertex ver);
	int getLastNeighborInVertax(int u);
	Graph createSuperGraph();

	void Print();
private:
	list<int> DFSEndList();
	void VisitEndList(int u, list<int>& endList);

	Graph DFSSuperGraph(list<int> mainList);
	void VisitSuperGraph(int u, int rakahIndex, Graph& superGraph);

};
