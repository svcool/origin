#include <iostream> 

int main()
{
    //setlocale(LC_ALL, "Russian"); 
    //system("chcp 1251"); 
    const int size = 10;
    int arr[size]{ 10, -2, 3, 4, 5, 6, 20, 8, -9, 10 };
    int max{}, min{};
    max = arr[0];
    min = arr[0];
    std::cout << "Массив: ";
    for (int i{}; i < 10; i++) {
        std::cout << arr[i] << "\t";
        if (arr[i] > max) max = arr[i];
        if (arr[i] < min) min = arr[i];
    }
    std::cout << "\nМинимальный элемент: " << min << std::endl;
    std::cout << "Максимальный элемент: " << max << std::endl;
    return(0);
}