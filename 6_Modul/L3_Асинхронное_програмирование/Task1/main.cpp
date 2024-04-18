#include <iostream>
#include <ctime>
#include <iomanip>
#include <future>
#include <thread>
#include <Windows.h>
#include <random>
using namespace std;

void Sort1(int* arrayPtr, int length_array, int rp, std::promise<int> prom) // ���������� �������
{
    int temp = arrayPtr[0]; // ��������� ���������� ��� �������� �������� ������������
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
    
    srand(time(NULL)); //��� �������� ���� ��������������� ����� �����
    setlocale(LC_ALL, "rus");
    cout << "������� ������ �������: ";
    int size; // ������ �������
    cin >> size;

    int* arr = new int[size]; // ���������� ������������ ������
    for (int counter = 0; counter < size; counter++)
    {
        arr[counter] = rand() % 100; // ��������� ������ ���������� �������
        cout << setw(2) << arr[counter] << "  "; // ����� ������� �� �����
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
    delete[] arr; // ������������ ������
    system("pause");
    return 0;
}

