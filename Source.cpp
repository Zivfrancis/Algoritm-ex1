#include <iostream>
#include <string.h>
#include "Graph.h"
#include"InvalidInputException.h"
using namespace std;


int main()
{
	Graph graph;
	int n, m;

	// Read number of vertices (n) and number of edges (m)
	cin >> n;
	cin >> m;

	// Initialize an empty graph with n vertices
	graph.MakeEmptyGraph(n);
	
	try
	{
		// Read edges and add them to the graph
		for (int i = 0; i < m; ++i)
		{
			int u, v;

			cin >> u >> v;

			u -= 1;
			v -= 1;

			graph.AddEdge(u, v);
		}

		// Create and print the supergraph
		graph.createSuperGraph();
	}

	catch (const InvalidInputException& ex)
	{
		cout << ex.GetMessage();
		return 1;
	}
	catch (const exception& ex)
	{
		cout << ex.what();
		return 1;
	}	

	return 0;
}

