#include"Graph.h"
#include "Program.h"

Graph::Graph()
{
	numberOfEdges = 0;
	numberOfVertices = 0;
}

Graph::~Graph()
{
	
}

void Graph::MakeEmptyGraph(int numOfVertices)
{
	numberOfVertices = numOfVertices;

	for (int u = 0; u < numberOfVertices; ++u)
	{
		Vertex ver;
		vertices.push_back(ver);
	}
}

bool Graph::IsAdjacent(int u, int v)const
{
	for (int neighbor : vertices[u].neighborsList)
	{
		if (neighbor == v)
		{
			return true;
		}
	}

	return false;
}

void Graph::AddEdge(int u, int v)
{
	if (u >= numberOfVertices || v >= numberOfVertices || v < 0 || u < 0 || v == u)
	{
		errorExit("Invalid input");
	}

	if (IsAdjacent(u, v) == false)
	{
		vertices[u].neighborsList.push_back(v);
		numberOfEdges++;
	}
}

void Graph::AddVertex(Vertex ver)
{
	vertices.push_back(ver);
	numberOfVertices++;
}

int Graph::getLastNeighborInVertax(int u)
{
	if (vertices[u].neighborsList.empty() == false)
	{
		return vertices[u].neighborsList.back();
	}

	return -1;
}

Graph Graph::Transpose()const
{
	Graph t;

	t.MakeEmptyGraph(numberOfVertices);

	for (int u = 0; u < numberOfVertices; ++u)
	{
		for (int v : vertices[u].neighborsList)
		{
			t.AddEdge(v, u);
		}
	}

	return t;
}

list<int> Graph::DFSEndList()
{
	list<int> endList;
	endList.clear();

	for (int u = 0; u < numberOfVertices; ++u)
	{
		vertices[u].SetColor(WHITE);
	}

	for (int u = 0; u < numberOfVertices; ++u)
	{
		if (vertices[u].GetColor() == WHITE)
		{
			VisitEndList(u, endList);
		}
	}

	return endList;
}

void Graph::VisitEndList(int u, list<int>& endList)
{
	vertices[u].SetColor(GREY);

	for (int v : vertices[u].neighborsList)
	{
		if (vertices[v].GetColor() == WHITE)
		{
			VisitEndList(v, endList);
		}
	}

	vertices[u].SetColor(BLACK);
	endList.push_back(u);
}

Graph Graph::createSuperGraph()
{
	list<int> endList = DFSEndList();
	auto tranponse = Transpose();
	endList.reverse();
	auto superGraph = tranponse.DFSSuperGraph(endList);

	superGraph.Print();
	return superGraph;
}

Graph Graph::DFSSuperGraph(list<int> mainList)
{
	Graph superGraph;
	int rakahIndex = 0;

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

void Graph::VisitSuperGraph(int u, int rakahIndex, Graph& superGraph)
{
	vertices[u].SetColor(GREY);

	for (int v : vertices[u].neighborsList)
	{
		if (vertices[v].GetColor() == WHITE)
		{
			vertices[v].SetRakahIndex(vertices[u].GetRakahIndex());

			VisitSuperGraph(v, rakahIndex,superGraph);
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

void Graph::Print()
{
	cout << numberOfVertices << " " << numberOfEdges;
}

