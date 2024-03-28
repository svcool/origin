#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

void dfs_visit(int** graph, int vertex, bool* visited, int* arr_vertex, int size) {
	queue<int> q;
	static unsigned k{};
	//arr_vertex[k] = vertex + 1;// массив пройденного пути
	q.push(vertex);
	for (int i{}; i < size; ++i) {
		// проверяем вершину введенную пользователем
		if (q.size() > 0 && q.front() == vertex) {
			arr_vertex[k] = vertex + 1;// массив пройденного пути
			visited[vertex] = true; //ставим метку, что посетили данную вершину
		}
		else if (visited[i] == false) {
			q.push(i);//помещаем в очередь, если не посещена
			arr_vertex[k] = i + 1;// массив пройденного пути
			visited[i] = true; //ставим метку, что посетили данную вершину
		}
		else continue;
		while (q.size()>0) {
			vertex = q.front();
			q.pop();// извлекаем вершину из очерди
			for (int j{}; j < size; ++j) {
				if (graph[vertex][j] == 1 && visited[j] == false) {// смотрим были ли мы в вершине раньше
					q.push(j);//помещаем в очередь
					visited[j] = true; //ставим метку, что посетили данную вершину
					k++;
					arr_vertex[k] = j + 1;// массив пройденного пути
				}

			}
		}
	}
};



int main() {
	setlocale(LC_ALL, "Russian");
	system("chcp 1251");
	std::ifstream f("input.txt");

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
	//запрос вершины для обхода
	int vertex{};
	do {
		cout << "\nВ графе " << row << " вершин. Введите номер вершины, с которой начнётся обход: ";
		cin >> vertex;
		if (vertex < 1 || vertex > row) {
			cout << "\nНет такой вершины в графе!";
				continue;
		}
		break;
	} while (true);
	//обход в глубину
	dfs_visit(arr_graph, vertex - 1, arr_visited, arr_vertex, row);

//вывод массива посещенных вершин
	cout << "\nПорядок обхода вершин: ";
	for (int i = 0; i < row; ++i) {
		cout << arr_vertex[i] << " ";
	}

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