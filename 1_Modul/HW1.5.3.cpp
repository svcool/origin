#include <iostream> 
#include <iomanip>

int main()
{
    //setlocale(LC_ALL, "Russian"); 
   // system("chcp 1251"); 
    const int row = 3, col = 6;
    int arr[row][col]{
        {10, -2, 9, -734, 5, 63},
        {0, -5, 3, 24, 54, 444},
        {14, -66, 27, 666, 5, 66}
    };
    int maxR{}, maxC{}, minC{}, minR{};
    int max{}, min{};
    max = arr[0][0];
    min = arr[0][0];
    std::cout << "Массив: \n";
    for (int i{}; i < row; ++i) {
        for (int j{}; j < col; ++j) {
            std::cout << std::setw(5) << arr[i][j];
            if (arr[i][j] > max) { maxR = i; maxC = j; max = arr[i][j]; }
            if (arr[i][j] < min) { minR = i; minC = j; min = arr[i][j]; }

        }
        std::cout << "\n";
    }
    std::cout << "\nИндекс минимального элемента: " << minR << " " << minC << std::endl;
    std::cout << "Индек максимальный элемента: " << maxR << " " << maxC << std::endl;
    return(0);
}