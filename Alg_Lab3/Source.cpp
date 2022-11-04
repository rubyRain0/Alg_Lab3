#include "Graph.h"

int main()
{	// ������������� ����� (��������� ������ ���������� �� � 0 � � 1)
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
	// ����� � ������� DFS � ��������� ��������� ��������� (connectivity) 
	std::cout << "Vertexes order: ";
	/*for (size_t i = 0; i < n; i++)
	{
		if (!roads.getVisited()[i])
		{
			roads.DFS(i, connectivity);
			connectivity++;
		}
	}*/

	// ����� � ������ BFS � ��������� ��������� ��������� (connectivity)
	for (size_t i = 0; i < n; i++)
	{
		if (!roads.getVisited()[i])
		{
			roads.BFS(i, connectivity);
			connectivity++;
		}
	}

	std::cout << '\n' << "Connectivities: \n" << connectivity << '\n';
	std::cout << "Connectivity attachment: "; //�������� ������ � �������������� ������ � ���������� ���������� ���������.
	for (size_t i = 0; i < n; i++)
	{
		std::cout << roads.getComp()[i] + 1 << " ";
	}
	std::cout << "\nMinimum roads to add: " << connectivity - 1; //����� �� ������ ���-�� ��������� ��������� - 1.

	std::cin.get();
}