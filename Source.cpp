#include <iostream>
#include <string.h>
#include "Graph.h"
using namespace std;


int main()
{
	Graph graph;

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

