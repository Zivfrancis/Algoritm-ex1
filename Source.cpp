#include <iostream>
#include <string.h>
#include "Graph.h"
#include"InvalidInputException.h"
using namespace std;


int main()
{
	Graph graph;

	int n, m;

	cin >> n;
	cin >> m;

	graph.MakeEmptyGraph(n);
	try
	{
		for (int i = 0; i < m; ++i)
		{
			int u, v;

			cin >> u >> v;

			u -= 1;
			v -= 1;

			graph.AddEdge(u, v);
		}

		
		graph.createSuperGraph();
	}
	catch (InvalidInputException ex)
	{
		cout << ex.GetMessage();
		return 1;
	}
	catch (exception ex)
	{
		cout << ex.what();
		return 1;
	}


	
	

	return 0;
}

