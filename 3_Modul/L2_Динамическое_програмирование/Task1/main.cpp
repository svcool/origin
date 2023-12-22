#include <iostream>
int fib(int n)
{
    if (n <= 1)
        return n;
    return fib(n - 1) + fib(n - 2);
}

int main()
{
    int n = 20;
    std::cout << fib(n);
    getchar();
    return 0;
//https://translated.turbopages.org/proxy_u/en-ru.ru.547d0e0c-6585303f-e9e29000-74722d776562/https/www.geeksforgeeks.org/cpp-program-for-fibonacci-numbers/
}
