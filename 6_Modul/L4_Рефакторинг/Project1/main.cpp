#include <condition_variable>
#include <iostream>
#include <random>
#include <thread>
#include <mutex>
#include <queue>

std::mutex              g_lockprint;
std::mutex              g_lockqueue;
std::condition_variable g_queuecheck;
std::queue<int>         g_codes;
bool                    g_done;
bool                    g_notified;

void workerFunc(int id, std::mt19937& generator)
{
    // ��������� ���������
    {
        std::unique_lock<std::mutex> locker(g_lockprint);
        std::cout << "[worker " << id << "]\trunning..." << std::endl;
    }
    // ��������� ������
    std::this_thread::sleep_for(std::chrono::seconds(1 + generator() % 5));
    // ��������� ������
    int errorcode = id * 100 + 1;
    {
        std::unique_lock<std::mutex> locker(g_lockprint);
        std::cout << "[worker " << id << "]\tan error occurred: " << errorcode << std::endl;
    }
    // �������� �� ������
    {
        std::unique_lock<std::mutex> locker(g_lockqueue);
        g_codes.push(errorcode);
        g_notified = true;
        g_queuecheck.notify_one();
    }
}

void loggerFunc()
{
    // ��������� ���������
    {
        std::unique_lock<std::mutex> locker(g_lockprint);
        std::cout << "[logger]\trunning..." << std::endl;
    }
    // �� ��� ���, ���� �� ����� ������� ������
    while (!g_done)
    {
        std::unique_lock<std::mutex> locker(g_lockqueue);
        while (!g_notified) // �� ������ �����������
            g_queuecheck.wait(locker);
        // ���� ���� ������ � �������, ������������ ��
        while (!g_codes.empty())
        {
            std::unique_lock<std::mutex> locker(g_lockprint);
            std::cout << "[logger]\tprocessing error:  " << g_codes.front() << std::endl;
            g_codes.pop();
        }
        g_notified = false;
    }
}

int main()
{
    // ������������� ���������� ������-��������� �����
    std::mt19937 generator((unsigned int)std::chrono::system_clock::now().time_since_epoch().count());
    // ������ ������������
    std::thread loggerThread(loggerFunc);
    // ������ �������
    std::vector<std::thread> threads;
    for (int i = 0; i < 5; ++i)
        threads.push_back(std::thread(workerFunc, i + 1, std::ref(generator)));
    for (auto& t : threads)
        t.join();
    // �������� ������������ � ���������� � ������� ���
    g_done = true;
    loggerThread.join();
    return 0;
}