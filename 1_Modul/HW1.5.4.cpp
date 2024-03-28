#include <iostream> 

int main()
{
    //setlocale(LC_ALL, "Russian"); 
    //system("chcp 1251"); 
    const int size = 10;
    int arr[size]{ -144, -2, 3, -4, 5, 6, 20, 8, -9, 46 };
    int temp{}, i{};
    std::cout << "Массив до сортировки: ";
    for (int x : arr) {
        std::cout << x << "\t";
    }

    for (int j = size - 1; j >= 0; j--) {

        for (int i = size - 1; i > size - j - 1; i--) {
            temp = arr[i];
            if (arr[i] < arr[i - 1]) {
                arr[i] = arr[i - 1];
                arr[i - 1] = temp;
            }
        }
    }

    std::cout << "\nМассив после сортировки: ";
    for (int x : arr) {
        std::cout << x << "\t";
    }
    std::cout << std::endl;
    return(0);
}