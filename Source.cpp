#include <iostream>
#include <string.h>
#include "Graph.h"
using namespace std;


int main()
{
	Graph graph;

	//graph.AddEdge(0, 1);
	//graph.AddEdge(0, 2);
	//graph.AddEdge(2, 1);
	//graph.AddEdge(1, 3);
	//graph.AddEdge(3, 2);
	//graph.AddEdge(4, 3);
	//graph.AddEdge(4, 5);
	//graph.AddEdge(5, 4);

	int n, m;

	cin >> n;
	cin >> m;

	graph.MakeEmptyGraph(n);

	for (int i = 0; i < m; ++i)
	{
		int u, v;

		cin >> u >> v;

		u -= 1;
		v -= 1;

		graph.AddEdge(u, v);
	}
	
	graph.createSuperGraph();

	return 0;
}

