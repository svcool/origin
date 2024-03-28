#include <iostream>
unsigned long long* arr;

unsigned long long fib(int n)
{
    if (n <= 1) {
        arr[n] = n;
        return n;
    }
    if (arr[n] == -1) {
        arr[n] = fib(n - 1) + fib(n - 2);
     }
    return  arr[n];
}

int main()
{
    setlocale(LC_ALL, "Russian");
    int n = 0;
    int i = 0;
    //int arr[2]{0,1};
    std::cout << "Введите число: ";
    std::cin >> n;
    arr = new unsigned long long[n] {};
    for (int i = 0; i < n; ++i) {
        arr[i] = -1;
    }
    while (i < n) {
        std::cout << fib(i) << " ";
        ++i;
    }
    delete[] arr;
    return 0;

}
