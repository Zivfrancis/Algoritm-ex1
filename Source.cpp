#include <iostream>
#include <string.h>
#include "Graph.h"
using namespace std;


void main()
{
	Graph graph;

	graph.MakeEmptyGraph(6);

	graph.AddEdge(0, 1);
	graph.AddEdge(0, 2);
	graph.AddEdge(2, 1);
	graph.AddEdge(1, 3);
	graph.AddEdge(3, 2);
	graph.AddEdge(4, 3);
	graph.AddEdge(4, 5);
	graph.AddEdge(5, 4);
	
	graph.createSuperGraph();
}

