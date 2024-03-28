#include <iostream>
#include <fstream>
#include <list>

using namespace std;

void dfs_visit(int** graph, int vertex, bool* visited, int size, list<int>& order) {
	visited[vertex] = true; //ставим метку, что посетили данную вершину
	for (int i{}; i < size; ++i) {// проходим по все ребрам.
		if (graph[vertex][i] == 1 && visited[i] == false) {// смотрим были ли мы в вершине раньше
			dfs_visit(graph, i, visited, size, order);
		order.push_front(i+1);
		}

	}
//
};
//для обхода всего графа(не связного) 
list<int> dfs_graph(int** arr_graph, int size) {
	list<int> order;
	bool* arr_visited = new bool[size] {};
	for (int i{}; i < size; ++i) {
		if (arr_visited[i] == false) {
			dfs_visit(arr_graph, i, arr_visited, size, order);
			order.push_front(i+1);
		}
	}
	delete[] arr_visited;
	return order;
}

int main() {
	setlocale(LC_ALL, "Russian");
	system("chcp 1251");
	ifstream file("input2.txt");

	//проверка открытия файла
	if (!file.is_open()) {
		cout << "Fail to open file!" << endl;
		return 0;
	}

	int vertex{};
	file >> vertex;
	//создаем динамический массив смежности орграфа
	int** arr_vertex = new int* [vertex];
	for (int i{}; i < vertex; ++i) {
		arr_vertex[i] = new int[vertex];
	}
	//читаем файл в массив
	for (int i{}; i < vertex; ++i) {
		for (int j{}; j < vertex; ++j) {
			file >> arr_vertex[i][j];
		}
	}
	//выводим графa
	for (int i{}; i < vertex; ++i) {
		for (int j{}; j < vertex; ++j) {
			cout << arr_vertex[i][j] << " ";
		}
		cout << endl;
	}


	list<int> order;
	order = dfs_graph(arr_vertex, vertex);

	// перебор в цикле
	cout << "Топологический порядок вершин: ";
	for (int n : order)
		std::cout << n << " ";
	std::cout << std::endl;

	//удалить массив из памяти
	for (int i{}; i < vertex; ++i) {
		delete[] arr_vertex[i];
	}
	delete[] arr_vertex;

	return 0;
}