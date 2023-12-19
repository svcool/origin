#include <iostream>

void print(int* arr, const int size) {
    for (int i = 0; i < size; i++) {

        std::cout << arr[i] << "\t";
    }
    std::cout << std::endl;
}
void random(int* arr, const int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 10;
    }
}


int main() {
    const int size1{ 5 }, size2{ 10 }, size3{ 8 };
    int arr1[size1]{}, arr2[size2]{}, arr3[size3]{};
    std::cout << arr1 << "\t" << *arr1 << std::endl;
    // заполняем массив
    random(arr1, size1);
    random(arr2, size2);
    random(arr3, size3);
    //выводим массив
    print(arr1, size1);
    print(arr2, size2);
    print(arr3, size3);
}