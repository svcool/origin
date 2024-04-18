#include <thread>
#include <iostream>
#include <Windows.h>
#include <vector>
#include <mutex>
#include "timer.h"
#include <iomanip>
#include <random>
#include <ctime>

HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

void SetXY(short X, short Y) {
    COORD coord = { X, Y };
    SetConsoleCursorPosition(hStdOut, coord);
}

enum ConsoleColor {
    Black = 0,
    Blue = 1,
    Green = 2,
    Cyan = 3,
    Red = 4,
    Brown = 6,
    White = 15
};


void SetColor(ConsoleColor text, ConsoleColor background) {
    SetConsoleTextAttribute(hStdOut, (WORD)((background) | text));
}

void clearScreen() {
    system("cls");
}
unsigned long seed = 1;
int my_rand() {
    seed = seed * 1103515245 + 12345;  // Линейный конгруэнтный метод
    return (seed / 65536) % 32768;     // Вернуть значение в диапазоне 0-32767
} 

std::mutex mt;

void print(int nt) {
    
std::cout << std::setw(2) << nt << std::setw(10) << std::this_thread::get_id() << std::setw(22) << "....................";
       
}

int nt = 0;
void doSomething(int nt, int N) {
 
    std::unique_lock<std::mutex> lock1(mt, std::defer_lock);
    lock1.lock();
    SetXY(0, nt);
   print(nt);
   lock1.unlock();
   char symbol = 219;
  int width = 20;

  auto start = std::chrono::high_resolution_clock::now();
  for (int i = 0; i < width; i++) {
      std::this_thread::sleep_for(std::chrono::milliseconds(my_rand() % 1000));
      std::unique_lock<std::mutex> lock2(mt, std::defer_lock);
      lock2.lock();
      SetXY(14 + i, nt);
      
      std::cout << symbol;
      lock2.unlock();

  }
  auto end = std::chrono::high_resolution_clock::now();
  
  SetXY(0, 1);

 
 std::chrono::duration<double> time = end - start;
 std::unique_lock<std::mutex> lock3(mt, std::defer_lock);
 lock3.lock();
  SetXY(40, nt);
  std::cout << time.count();
  lock3.lock();
  SetXY(0, 8);
  std::cout << "\n";
}


int main() {
    //setlocale(LC_ALL, "Russian");
   // system("chcp 1251");

     srand(time(NULL)); //для создания ряда псевдослучайных целых чисел

    std::cout << std::setw(2) << "#"  << std::setw(10) << "id" << std::setw(22) <<"Progress Bar"<< std::setw(12) << "Time";

   std::vector<std::thread> threads;

   int count = 5;
    for (auto i = 1; i <= count; ++i) {

        std::thread th(&doSomething, i, count);
        threads.push_back(std::move(th));
           

    }
 for (std::thread& th : threads)
        {
            if (th.joinable())
                th.join();
        }
}