#include <thread>
#include <iostream>
#include <Windows.h>
#include <vector>
#include <mutex>
#include "timer.h"
#include <iomanip>

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


std::mutex mt;

void print(int nt) {
    
std::cout << std::setw(2) << nt << std::setw(10) << std::this_thread::get_id() << std::setw(22) << "....................";
       
}

int nt = 0;
void doSomething(int nt, int N) {
 
    mt.lock();
    SetXY(0, nt);
   print(nt);
   mt.unlock();
   char symbol = 219;
  int width = 20;

  std::chrono::steady_clock::time_point start;
  std::chrono::steady_clock::time_point end;
  
  SetXY(0, 1);


mt.lock();
start = std::chrono::steady_clock::now();

  for (int i = 0; i < width; i++) {
      std::this_thread::sleep_for(std::chrono::milliseconds(100));

      SetXY(14+i, nt);
      
      std::cout << symbol;
  }
end = std::chrono::steady_clock::now();
 mt.unlock();
 
 std::chrono::duration<double> time = end - start;

  SetXY(40, nt);
  std::cout << time.count();
  SetXY(0, 8);
  std::cout << "\n";
}


int main() {
    //setlocale(LC_ALL, "Russian");
   // system("chcp 1251");

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