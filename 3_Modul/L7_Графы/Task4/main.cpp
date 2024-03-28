#include <iostream>
#include <fstream>

using namespace std;

void dfs_cids(int** graph, int vertex, int* cids, int size, int cid) {
	cids[vertex] = cid; // присваем cid номер вершины
	for (int i{}; i < size; ++i) {// проходим по все ребрам.
		if (graph[vertex][i] == 1 && cids[i] == 0) {// смотрим были ли мы в вершине раньше
			dfs_cids(graph, i, cids, size, cid);
		}
	}

};
//для обхода всего графа(не связного) 
int dfs_graph(int** arr_graph, int size, int* cids) {
	int cid = 0;
	for (int i{}; i < size; ++i) {
		if (cids[i] == 0) {
			cid++;
			dfs_cids(arr_graph, i, cids, size, cid);
		}
	}
	return cid;
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
	//массив компонентов связности
	int* arr_cids = new int[row] {};
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
			cout << arr_graph[i][j] << " ";
		}
		cout << endl;
	}

	int number{}; //количество компонентов связности
	number = dfs_graph(arr_graph, row, arr_cids);
	
	cout << "\nПринадлежность вершин компонентам связности:\n";
	//вывод связности графа
		for (int i = 0; i < row; ++i) {
			std::cout << i + 1 << " - " << arr_cids[i] << "\n";
	}
	cout << "Количество компонентов связности в графе: " << number << endl;


	//удалить массив из памяти
	for (int i{}; i < row; i++) {
		delete[] arr_graph[i];
	}
	delete[] arr_graph;

	delete[] arr_cids;
	//закрыть файл
	f.close();
	return 0;
}