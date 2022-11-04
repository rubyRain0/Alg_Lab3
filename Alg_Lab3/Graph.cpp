#include "Graph.h"

Graph::Graph(int vertexes)
{
	numVertexes = vertexes;
	adjLists = new std::list<int>[numVertexes];
	visited = new bool[numVertexes];
	comp = new int[numVertexes];
	for (size_t i = 0; i < vertexes; i++)
	{
		visited[i] = false;
	}
}
void Graph::addEdge(int from, int to)
{
	adjLists[from-1].push_front(to-1);
}
void Graph::DFS(int vertex, int connectivity)
{
	visited[vertex] = true;
	comp[vertex] = connectivity;
	std::list<int> adjList = adjLists[vertex];

	std::cout << vertex+1 << " ";

	std::list<int>::iterator i;
	for (i = adjList.begin(); i != adjList.end(); ++i)
	{
		if (!visited[*i])
			DFS(*i, connectivity);
	}
}
void Graph::BFS(int vertex, int connectivity)
{	
	std::queue<int> adjQueue;
	adjQueue.push(vertex);
	visited[vertex] = true;
	std::list<int> adjList = adjLists[vertex];

	std::list<int>::iterator i;
	while (!adjQueue.empty())
	{
		std::list<int> adjList = adjLists[adjQueue.front()];
		comp[adjQueue.front()] = connectivity;
		std::cout << adjQueue.front() + 1 << " ";
		adjQueue.pop();
		for (i = adjList.begin(); i != adjList.end(); ++i)
		{
			if (!visited[*i])
			{
				adjQueue.push(*i);
				visited[*i] = true;
			}
		}
	}
}
bool* Graph::getVisited()
{
	return visited;
}

int* Graph::getComp()
{
	return comp;
}
