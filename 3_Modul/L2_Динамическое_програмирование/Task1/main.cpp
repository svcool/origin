#include <iostream>
unsigned int fib(int n)
{
    return  n < 2 ? n : fib(n - 1) + fib(n - 2);
}

int main()
{
    setlocale(LC_ALL, "Russian");
    unsigned int n = 0;
    int i = 0;
    std::cout << "Введите число: "; 
    std::cin >> n;
    while (i < n) {
        std::cout << fib(i) << " ";
        ++i;
    }
    return 0;
//https://translated.turbopages.org/proxy_u/en-ru.ru.547d0e0c-6585303f-e9e29000-74722d776562/https/www.geeksforgeeks.org/cpp-program-for-fibonacci-numbers/
}
