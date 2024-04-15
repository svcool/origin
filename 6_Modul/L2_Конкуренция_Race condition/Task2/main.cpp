#include <thread>
#include <iostream>
#include <Windows.h>
#include <vector>
#include <mutex>
#include "timer.h"

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
void doSomething(int nt) {
    mt.lock();
  std::cout << "\n1\t" << std::this_thread::get_id << "\tTime";
  mt.unlock();
  char symbol = 219;
  int count = 30;
int last_index = 0;
int progress = 0;
Timer x;
// имитация изменения прогресса
    while (last_index < count)
    {  
      //last_index += nt + rand() % 5;
      //if (last_index > count)  last_index = count;
      
      
      last_index += 1;

      if (last_index >= 1 / count) {
          progress = (last_index / count);
          SetColor(Red, Red); SetXY(50 + last_index, 3 + nt);
      }

        std::this_thread::sleep_for(std::chrono::milliseconds(400));
       // SetColor(Red, Red); SetXY(50+progress, 3+nt);
        std::cout << symbol;
        
    }
    SetColor(White, White); SetXY(50, 10 + nt);
}


//void f_thread(std::vector<int>& result, const std::vector<int>& v1, const std::vector<int>& v2, int count, int j) {
//
//    std::vector<std::thread> threads;
//
//    for (auto i = 0; i < count; ++i) {
//
//        std::thread th(&sum, std::ref(result), std::ref(v1), std::ref(v2), j, i);
//        threads.push_back(std::move(th));
//
//        for (std::thread& th : threads)
//        {
//            if (th.joinable())
//                th.join();
//        }
//
//    }
//}


int main() {
    //setlocale(LC_ALL, "Russian");
   // system("chcp 1251");

    std::cout << "#"  << "   id \t" << "Progress Bar\t" << "Time";
    //std::cout << std::this_thread::get_id << "Time";

   /* std::vector<std::thread> threads;
    std::vector<std::chrono::duration<double>> time_thr;
    std::chrono::steady_clock::time_point start;
    std::chrono::steady_clock::time_point end;*/
    int N = 5;
   // doSomething();
    std::thread t1(doSomething, 1);
    std::thread t2(doSomething, 2);
    int count = std::thread::hardware_concurrency();

    //for (auto j = 1; j < count + 1; ++j) { //количество потоков(ядер)
    //    std::cout << "\n" << j << " потоков\t";
    //    //перебор  потоков
    //        start = std::chrono::steady_clock::now();

    //        f_thread(result, v1, v2, count, j);

    //        end = std::chrono::steady_clock::now();

    //        std::chrono::duration<double> el = end - start;

    //        time_thr.push_back(std::move(el));

    //    for (auto& n : time_thr) {
    //        std::cout << n.count() << "\t";
    //    }
    //    time_thr.clear();
    //}

    t1.join();
    t2.join();

}