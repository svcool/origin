#include <iostream>

void counting_function() {

    static int i = 0;
    std::cout << "Количество вызовов функции counting_function() : " << ++i << std::endl;
}

int main(int argc, char** argv) {
    //setlocale(LC_ALL, "Russian");
   // system("chcp 1251"); 
    for (int i = 0; i < 15; i++)
    {
        counting_function();
    }
}