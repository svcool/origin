#include <iostream>
#include <fstream>

using namespace std;

// поиск цикла
void dfs_visit(int** graph, int vertex, bool* visited, int* arr_vertex, int size, int prev) { //prev - вершина предка
	visited[vertex] = true; //ставим метку, что посетили данную вершину
	static unsigned k{};
	arr_vertex[k] = vertex + 1;
	k++;

	for (int i{}; i < size; ++i) {// проходим по все ребрам.
		if (graph[vertex][i] == 1 && visited[i] == false) {// смотрим были ли мы в вершине раньше
			dfs_visit(graph, i, visited, arr_vertex, size, vertex);
			
		}
		else if (i != prev && graph[vertex][i] != 0) { //проверка посещенной вершины, что она не та из которой пришли
			cout << "\nВ графе есть цикл\n";
			exit(0);
		}
	}
	cout << "\nВ графе нет циклов\n";
	exit(0);
};
//для обхода всего графа(не связного) 
void dfs_graph(int** arr_graph, bool* arr_visited, int size, int* arr_vertex) {
	for (int i{}; i < size; ++i) {
		if (arr_visited[i] == false) {
			dfs_visit(arr_graph, i, arr_visited, arr_vertex, size, i);
		}
	}
}

int main() {
	setlocale(LC_ALL, "Russian");
	system("chcp 1251");
	std::ifstream f("input2.txt"); // input1.txt, input2.txt

	//проверка открытия файла
	if (!f.is_open()) {
		std::cout << "Fail to open file!" << std::endl;
		return 0;
	}
	int col{}, row{};
	f >> row;
	col = row;
	//массив для хранения посещенных вершин
	bool* arr_visited = new bool[row] {};
	//массив посещенных вершиш
	int* arr_vertex = new int[row];
	// создаем динамический массив смежности графа
	int** arr_graph = new int* [row];
	
	for (int i{}; i < row; ++i) {
		arr_graph[i] = new int[col];
	}
	//читаем файл в массив
	for (int i{}; i < row; ++i) {
		for (int j{}; j < col; ++j) {
			f >> arr_graph[i][j];
		}
	}

	//выводим граф
	for (int i{}; i < row; i++) {
		for (int j{}; j < col; ++j) {
			std::cout << arr_graph[i][j] << " ";
		}
		std::cout << std::endl;
	}

	//обход в глубину и поиск цикла
	dfs_visit(arr_graph, 0, arr_visited, arr_vertex, row, 0);
	//dfs_graph(arr_graph, arr_visited, row, arr_vertex);



	//удалить массив из памяти
	for (int i{}; i < row; i++) {
		delete[] arr_graph[i];
	}
	delete[] arr_graph;

	delete[] arr_visited;
	delete[] arr_vertex;
	//закрыть файл
	f.close();
	return 0;
}