#include <iostream>
#include <ctime>
#include <iomanip>
#include <future>
#include <thread>
#include <Windows.h>
#include <random>
using namespace std;

void Sort1(int* arrayPtr, int length_array, int rp, std::promise<int> prom) // сортировка выбором
{
    int temp = arrayPtr[0]; // временная переменная для хранения значения перестановки
    for (int elem = rp + 1; elem < length_array; elem++)
    {
        if (arrayPtr[rp] > arrayPtr[elem])
        {
            temp = arrayPtr[rp];
            arrayPtr[rp] = arrayPtr[elem];
            arrayPtr[elem] = temp;
        }
    }

    prom.set_value(arrayPtr[rp]);
     //std::this_thread::sleep_for(std::chrono::seconds(1));
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

    
    for (int i = 0; i < size; ++i) {
        std::promise<int> prom;
        std::future<int> ft_res = prom.get_future();
        auto ft = std::async(Sort1, arr, size, i, std::move(prom));

        std::cout << ft_res.get() << "  ";
    }
   /* for (int i = 0; i < size; ++i) {
    std::packaged_task<int(int*, int, int)> task(Sort);
    std::future<int> ft = task.get_future();
    std::thread th(std::move(task), arr, size, 2);
    th.join();*/
    
    cout << "\n";
    delete[] arr; // высвобождаем память
    system("pause");
    return 0;
}

