#include <iostream> // std::cout
#include <thread>   // std::thread

#include <Windows.h> // WinApi

auto handle = GetStdHandle(STD_OUTPUT_HANDLE);

// устанавливает курсор в консоли на указанную позицию
void set_cursor(int x, int y)
{
    SetConsoleCursorPosition(handle, { static_cast<SHORT>(x), static_cast<SHORT>(y) });
}

// отрисовывает прогресс-бар в консоли по указанным координатам
// x - х-координата для прогресс-бара
// y - у-координата для прогресс-бара
// width - ширина прогресс-бара
// progress - пройденный прогресс [0; 1]
// fill_symbol - символ, которым будет заполнятся пройденный отрезок
//
void render_progress_bar(int x, int y, int width, double progress, char fill_symbol)
{
    int fill_w = static_cast<int>(width * progress);
    int empty_w = width - fill_w;

    set_cursor(x, y);

    for (int i = 0; i < fill_w; ++i)
        std::cout << fill_symbol;

    for (int i = 0; i < empty_w; ++i)
        std::cout << ".";
}

int main()
{
    const int progress_x = 1;
    const int progress_y = 0;
    const int progress_width = 30;
    double progress = 0;

    // поток отрисовки
    auto thread = std::thread{ [progress_x, progress_y,
            progress_width, &progress]
    {
        const int size = 3;
        char symbols[size] = { 219, 219, 219 };
        int symbol_idx = 0;

        do
        {
            render_progress_bar(progress_x, progress_y, progress_width, progress, symbols[symbol_idx]);

            std::this_thread::sleep_for(std::chrono::milliseconds(100));

            ++symbol_idx;

            if (symbol_idx >= size)
                symbol_idx = 0;
        } while (progress < 1);

        render_progress_bar(progress_x, progress_y, progress_width, progress, symbols[symbol_idx]);
    }};

    int count = 100;
    int last_index = 0;

    // имитация изменения прогресса
    while (last_index < count)
    {
        last_index += 1 + rand() % 5;

        if (last_index > count)
            last_index = count;

        progress = static_cast<double>(last_index) / count;

        std::this_thread::sleep_for(std::chrono::milliseconds(400));
    }

    thread.join();

    return 0;
}
//#include <iostream>
//
//int main() {
//    float progress = 0.0;
//    while (progress < 1.0) {
//        int barWidth = 70;
//
//        std::cout << "[";
//        int pos = barWidth * progress;
//        for (int i = 0; i < barWidth; ++i) {
//            if (i < pos) std::cout << "=";
//            else if (i == pos) std::cout << ">";
//            else std::cout << " ";
//        }
//        std::cout << "] " << int(progress * 100.0) << " %\r";
//        std::cout.flush();
//
//        progress += 0.16; // for demonstration only
//    }
//    std::cout << std::endl;
//
//    return 0;
//}