#include"Graph.h"
#include "Program.h"
#include "InvalidInputException.h"
#include <string>


/// <summary>
/// Default constructor for the Graph class
/// </summary>
Graph::Graph()
{
	numberOfEdges = 0;
	numberOfVertices = 0;
}

/// <summary>
/// Default constructor for the Graph class
/// </summary>
Graph::~Graph()
{
	
}

/// <summary>
/// Initializes an empty graph with a specified number of vertices
/// </summary>
/// <param name="numOfVertices">The number of vertices to create</param>
void Graph::MakeEmptyGraph(int numOfVertices)
{
	numberOfVertices = numOfVertices;

	// Create vertices and add them to the vertices list
	for (int u = 0; u < numberOfVertices; ++u)
	{
		Vertex ver;
		vertices.push_back(ver);
	}
}

/// <summary>
/// Checks if there is an edge between vertices u and v
/// </summary>
/// <param name="u">The source vertex</param>
/// <param name="v">The destination vertex</param>
/// <returns>True if there is an edge, otherwise false</returns>
bool Graph::IsAdjacent(int u, int v)const
{
	const list<int>& uNeighborsList = vertices[u].GetNeighborsList();

	// Check if v is a neighbor of u
	for (int neighbor : uNeighborsList)
	{
		if (neighbor == v)
		{
			return true;
		}
	}

	return false;
}

/// <summary>
/// Adds an edge between vertices u and v
/// </summary>
/// <param name="u">The source vertex</param>
/// <param name="v">The destination vertex</param>
void Graph::AddEdge(int u, int v)
{
	if (u >= numberOfVertices || v >= numberOfVertices || v < 0 || u < 0 || v == u)
	{
		throw InvalidInputException();
	}

	if (!IsAdjacent(u, v))
	{
		vertices[u].AddNeighbor(v);
		numberOfEdges++;
	}
}

/// <summary>
/// Adds a vertex to the graph
/// </summary>
/// <param name="ver">The vertex to add</param>
void Graph::AddVertex(Vertex ver)
{
	vertices.push_back(ver);
	numberOfVertices++;
}

/// <summary>
/// Gets the last neighbor of a given vertex
/// </summary>
/// <param name="u">The vertex index</param>
/// <returns>The last neighbor's index, or -1 if there are no neighbors</returns>
int Graph::getLastNeighborInVertax(int u)
{
	if (vertices[u].HasNeighbors() == true)
	{
		return vertices[u].GetNeighborsList().back();
	}

	return -1;
}

/// <summary>
/// Creates the transpose of the graph
/// </summary>
/// <returns>The transposed graph</returns>
Graph Graph::Transpose()const
{
	Graph t;

	t.MakeEmptyGraph(numberOfVertices);

	// Reverse all edges
	for (int u = 0; u < numberOfVertices; ++u)
	{
		const list<int> uNeighborsList = vertices[u].GetNeighborsList();

		for (int v : uNeighborsList)
		{
			t.AddEdge(v, u);
		}
	}

	return t;
}

/// <summary>
/// Performs DFS and returns the end list
/// </summary>
/// <returns>A list of vertices in the order they finished processing</returns>
list<int> Graph::DFSEndList()
{
	list<int> endList;
	endList.clear();

	// Initialize all vertices to WHITE
	for (int u = 0; u < numberOfVertices; ++u)
	{
		vertices[u].SetColor(WHITE);
	}

	// Visit all vertices
	for (int u = 0; u < numberOfVertices; ++u)
	{
		if (vertices[u].GetColor() == WHITE)
		{
			VisitEndList(u, endList);
		}
	}

	return endList;
}

/// <summary>
/// Helper function for 'DFSEndList' to visit a vertex and its neighbors
/// </summary>
/// <param name="u">The vertex index</param>
/// <param name="endList">The list of finished vertices</param>
void Graph::VisitEndList(int u, list<int>& endList)
{
	vertices[u].SetColor(GREY);

	const list<int>& uNeighborsList = vertices[u].GetNeighborsList();

	for (int v : uNeighborsList)
	{
		if (vertices[v].GetColor() == WHITE)
		{
			VisitEndList(v, endList);
		}
	}

	vertices[u].SetColor(BLACK);
	endList.push_back(u);
}

/// <summary>
/// Creates a supergraph based on the current graph
/// </summary>
/// <returns>The supergraph</returns>
Graph Graph::createSuperGraph()
{
	list<int> endList = DFSEndList();
	auto tranponse = Transpose();
	endList.reverse();
	auto superGraph = tranponse.DFSSuperGraph(endList);

	superGraph.Print();
	return superGraph;
}

/// <summary>
/// Performs DFS on the graph to create a supergraph
/// </summary>
/// <param name="mainList">The list of vertices in the main graph</param>
/// <returns>The supergraph</returns>
Graph Graph::DFSSuperGraph(list<int> mainList)
{
	Graph superGraph;
	int rakahIndex = 0;

	// Initialize all vertices to WHITE
	for (int u = 0; u < numberOfVertices; ++u)
	{
		vertices[u].SetColor(WHITE);
	}

	for (int u : mainList)
	{
		if (vertices[u].GetColor() == WHITE)
		{
			Vertex superVer;
			superGraph.AddVertex(superVer);
			vertices[u].SetRakahIndex(rakahIndex);

			VisitSuperGraph(u, rakahIndex, superGraph);
			rakahIndex++;
		}
	}
	return superGraph;
}

/// <summary>
/// Helper function for 'DFSSuperGraph' to visit a vertex and its neighbors
/// </summary>
/// <param name="u">The vertex index</param>
/// <param name="rakahIndex">The current component index</param>
/// <param name="superGraph">The supergraph being constructed</param>
void Graph::VisitSuperGraph(int u, int rakahIndex, Graph& superGraph)
{
	vertices[u].SetColor(GREY);

	const list<int>& uNeighborsList = vertices[u].GetNeighborsList();

	for (int v : uNeighborsList)
	{
		if (vertices[v].GetColor() == WHITE)
		{
			vertices[v].SetRakahIndex(vertices[u].GetRakahIndex());

			VisitSuperGraph(v, rakahIndex, superGraph);
		}
		else if (vertices[v].GetColor() == BLACK)
		{
			int vRakah = vertices[v].GetRakahIndex();
			int vRakahLastNeighbor = superGraph.getLastNeighborInVertax(vRakah);
			int uRakah = vertices[u].GetRakahIndex();
			if (vRakahLastNeighbor != uRakah && vRakah != uRakah)
			{
				superGraph.AddEdge(vRakah, uRakah);
			}
		}
	}

	vertices[u].SetColor(BLACK);
}

/// <summary>
/// Prints the graph's number of vertices and edges
/// </summary>
void Graph::Print()
{
	cout << numberOfVertices << " " << numberOfEdges;
}

