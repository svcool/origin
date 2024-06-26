﻿#include <iostream>
#include <ctime>
#include <iomanip>
#include <future>
#include <thread>
#include <Windows.h>
#include <random>
using namespace std;


void Sort2(int* arr, int size, int i, std::promise<int> prom) // сортировка выбором
{
    int min = i;
    for (int j = i + 1; j < size; ++j) {
        if (arr[min] > arr[j]) {
            min = j;
        }
      
    }

    prom.set_value(min);
}

int main()
{
    
    srand(time(NULL)); //для создания ряда псевдослучайных целых чисел
    setlocale(LC_ALL, "rus");
    cout << "Введите размер массива: ";
    int size; // размер массива
    cin >> size;

    int* arr = new int[size]; // одномерный динамический массив
    for (int counter = 0; counter < size; counter++)
    {
        arr[counter] = rand() % 100; // заполняем массив случайными числами
        cout << setw(2) << arr[counter] << "  "; // вывод массива на экран
    }
    cout << "\n\n";

    int min{};
    for (int i = 0; i < size; ++i) {
            std::promise<int> prom;
            std::future<int> ft_res = prom.get_future();
            auto ft = std::async(Sort2, arr, size, i, std::move(prom));
            min = ft_res.get();
            if (i != min)
            {
                swap(arr[i], arr[min]);
            }    
    }
    
    for (int n = 0; n < size; n++)
    {
        std::cout << arr[n] << " ";
    }

    //for (int i = 0; i < size; ++i) {
    //std::packaged_task<int(int*, int, int)> task(Sort);
    //std::future<int> ft = task.get_future();
    //std::thread th(std::move(task), arr, size, 2);
    //th.join();
    
    std::cout << "\n";
    delete[] arr; // высвобождаем память
    return 0;
}

