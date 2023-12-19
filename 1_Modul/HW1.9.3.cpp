#include <iostream>

void reverse(int* arr, const int size) {
    
    int temp{};
    for (int j = 0; j <= (size-1)/2; j++)
    {
        temp = arr[size - 1 -j];
        arr[size - 1 - j] = arr[j];
        arr[j] = temp;
    }
}


int main() {
    const int size = 10;
    int arr[size]{};

    std::cout << "До функции reverse: ";
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 10;
        std::cout << arr[i] << "\t";
    }
    std::cout << std::endl;
    
    reverse(arr, size);//реверс массива
    
    std::cout << arr[5] << "После функции reverse: ";
    for (int j = 0; j < size; j++) {
        std::cout << arr[j] << "\t";
    }
    std::cout << std::endl;
    return 0;
}

