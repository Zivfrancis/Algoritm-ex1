#pragma once
#include"Vertex.h"
#include"eVertexColor.h"
#include<vector>
using namespace std;

class Graph
{
private:
	vector<Vertex> vertices;
	int numberOfVertices;

public:
	Graph();
	~Graph();

	void MakeEmptyGraph(int numOfVertices);
	bool IsAdjacent(int u, int v)const;
	inline list<int> GetAdjList(int u) const{ return vertices[u].neighborsList; }
	void AddEdge(int u, int v);
	void RemoveEdge(int u, int v) { vertices[u].neighborsList.remove(v); }
	Graph Transpose()const;
	void AddVertex(Vertex ver);
	int getLastNeighborInVertax(int u);

	list<int> DFSEndList();
	void VisitEndList(int u, list<int>& endList);
	Graph createSuperGraph();
	Graph DFSSuperGraph(list<int> mainList);
	void VisitSuperGraph(int u,int rakahIndex, Graph& superGraph);


	void Print();
private:

};
