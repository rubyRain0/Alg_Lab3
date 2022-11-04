#include "Graph.h"

int main()
{	// инициализация графа (нумерация вершин начинается не с 0 а с 1)
	int connectivity = 0;
	int n, amountOfRoads, a, b;
	std::cout << "Enter amount of vertexes: \n";
	std::cin >> n;
	std::cout << "Enter amount of roads: \n";
	std::cin >> amountOfRoads;
	Graph roads(n);
	std::cout << "Enter edges: \n";
	for (size_t i = 0; i < amountOfRoads; i++)
	{ 
		std::cin >> a >> b;
		roads.addEdge(a, b);
	}
	// поиск в глубину DFS с подсчетом компонент связности (connectivity) 
	std::cout << "Vertexes order: ";
	/*for (size_t i = 0; i < n; i++)
	{
		if (!roads.getVisited()[i])
		{
			roads.DFS(i, connectivity);
			connectivity++;
		}
	}*/

	// поиск в ширину BFS с подсчетом компонент связности (connectivity)
	for (size_t i = 0; i < n; i++)
	{
		if (!roads.getVisited()[i])
		{
			roads.BFS(i, connectivity);
			connectivity++;
		}
	}

	std::cout << '\n' << "Connectivities: \n" << connectivity << '\n';
	std::cout << "Connectivity attachment: "; //Хранение данных о принадлежности вершин к конкретной компоненте связности.
	for (size_t i = 0; i < n; i++)
	{
		std::cout << roads.getComp()[i] + 1 << " ";
	}
	std::cout << "\nMinimum roads to add: " << connectivity - 1; //Ответ на задачу кол-во компонент связности - 1.

	std::cin.get();
}