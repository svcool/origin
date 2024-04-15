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

//�������� - ���
//
//�������� ���������� ���������� ��� �������� �������������� �������.<br / >
//���������� �������, ����� ������� ������ ���� ������ �����������.<br / >
//� ������� �� ����� ������ ��������� ������ ��������� ��� ������� ������ ���������� :
//
//� ����� ������ �� �������;
//
//� ������������� ������;
//
//� ������������� ��������� ��������� �������� - ����, ��������������� ������� ��������;
//
//� ����� ���������� ������ ������� ������ � ��������������� ������ ��������� �����, ����������� �� ������ ������.
//
//������ �������� - ����� ������� ������ ������ ���������� �����������.����� ��������� ������� ������ ������� � ������ �������� - ���� ��������� ���, ����� ������� ���������� ������ ��� �����.������ ������ ���������[�� ������.](https://cloud.mail.ru/public/MZVL/AqpmAkcMp)

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
    std::unique_lock<std::mutex> lk(mt);
    data_cond.wait(lk, [] {return vvv == 1; });
   
 
std::cout << "\n"<< std::setw(2) << nt << std::setw(10) << std::this_thread::get_id() << std::setw(22) << "...................." << std::setw(12);
    
    lk.unlock();
    
}




int nt = 0;
void doSomething(int nt, int progress) {
    Timer x;
    
    std::lock_guard<std::mutex> lk(mt);
    if (nt == xxx) {
    vvv = true;
    xxx++;
    }
    data_cond.notify_one();
print(nt);



  char symbol = 219;
  int width = 20;
int last_index = 0;
 //�������� ��������� ���������
    while (last_index < width)
    {  
      //last_index += nt + rand() % 5;
      //if (last_index > count)  last_index = count;
            
      last_index += 1;


      if (last_index >= 1 / width) {
          progress = (last_index / width);
          SetColor(Red, Red); SetXY(12 + last_index, 1 + nt);
      }

        std::this_thread::sleep_for(std::chrono::milliseconds(400));
       // SetColor(Red, Red); SetXY(50+progress, 3+nt);
        std::cout << symbol;
        
    }
  //  SetColor(White, White); SetXY(50, 10 + nt);
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

    for (auto i = 0; i < count; ++i) {

        std::thread th(&doSomething, i, progress);
        threads.push_back(std::move(th));
           

    }
 for (std::thread& th : threads)
        {
            if (th.joinable())
                th.join();
        }
}