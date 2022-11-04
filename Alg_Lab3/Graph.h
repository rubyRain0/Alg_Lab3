#pragma once
#include <iostream>
#include <list>
#include <queue>
#include <vector>

class Graph
{
	int numVertexes;
	std::list<int>* adjLists;
	bool* visited;
	int* comp;
public:
	Graph(int vertexes);
	void addEdge(int from, int to);
	void DFS(int vertex, int connectivity);
	void BFS(int vertex, int connectivity);
	bool* getVisited();
	int* getComp();
};