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



void Start() {
    SetColor(Cyan, Black); SetXY(12, 3); 
    std::cout << "To start the game, select a theme:" << std::endl;
}

void clearScreen() {
    system("cls");
}
//
//
//
//
//
//class consol_parameter
//{
//public:
//    static void SetColor(int text, int background)
//    {
//        SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
//    }
//    static void SetPosition(int x, int y)
//    {
//        COORD point;
//        point.X = x;
//        point.Y = y;
//        SetConsoleCursorPosition(hStdOut, point);
//    }
//private:
//    static HANDLE hStdOut;
//};
//HANDLE consol_parameter::hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

//Прогресс - бар
//
//Создайте консольное приложение для имитации многопоточного расчёта.<br / >
//Количество потоков, длина расчёта должны быть заданы переменными.<br / >
//В консоль во время работы программы должны построчно для каждого потока выводиться :
//
//• номер потока по порядку;
//
//• идентификатор потока;
//
//• заполняющийся индикатор наподобие прогресс - бара, визуализирующий процесс «расчёта»;
//
//• после завершения работы каждого потока в соответствующей строке суммарное время, затраченное на работу потока.
//
//Строки прогресс - баров каждого потока должны выводиться одновремено.Время появления каждого нового символа в строке прогресс - бара подберите так, чтобы процесс заполнения строки был виден.Пример работы программы[по ссылке.](https://cloud.mail.ru/public/MZVL/AqpmAkcMp)

//void task2() {
//	int N = 5;
//	for (size_t i = 0; i < 0; i++) {
//		t[i] = thread(drawRowProgress, i, N);
//		for (size_t i = 0; i < N; i++) {
//			t[i].join();
//			consol_paramer::SetPosition(0, 6);
//		}
//	}
//
//}
std::mutex mt;
std::condition_variable data_cond;
bool vvv = false;
int xxx = 0;
void print(int nt) {

 
std::cout << std::setw(2) << nt << std::setw(10) << std::this_thread::get_id() << std::setw(22) << "...................." << std::setw(12);
    

    
}




int nt = 0;
void doSomething(int nt, int progress) {
    Timer x;
    
    mt.lock();
SetXY(0, nt);
   print(nt);
   mt.unlock();

  char symbol = 219;
  int width = 20;
  int last_index = 0;
 //имитация изменения прогресса
    while (progress < width)
    {  
      progress += 1;
        

          SetColor(White, White); 
          SetXY(12 + progress, nt);
   

        std::this_thread::sleep_for(std::chrono::milliseconds(400));
        std::cout << symbol;
        
    }
    SetColor(White, White); SetXY(50, 10 + nt);
}


int main() {
    //setlocale(LC_ALL, "Russian");
   // system("chcp 1251");

    std::cout << std::setw(2) << "#"  << std::setw(10) << "id" << std::setw(22) <<"Progress Bar"<< std::setw(12) << "Time";
    //std::cout << std::this_thread::get_id << "Time";

   std::vector<std::thread> threads;
    std::vector<std::chrono::duration<double>> time_thr;
    std::chrono::steady_clock::time_point start;
    std::chrono::steady_clock::time_point end;
    int count = 5;
    int progress = 0;
   // doSomething();
    //std::thread t1(doSomething, 5, progress);
   // std::this_thread::sleep_for(std::chrono::milliseconds(100));
   // std::thread t2(doSomething, 2, progress);
    //int count = std::thread::hardware_concurrency();

    for (auto i = 1; i <= count; ++i) {

        std::thread th(&doSomething, i, progress);
        threads.push_back(std::move(th));
           

    }
 for (std::thread& th : threads)
        {
            if (th.joinable())
                th.join();
        }
}