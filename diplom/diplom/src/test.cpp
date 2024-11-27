#include <httpclient.h>
#include <tempfile.h>

int main() {
    // Установка кодировки консоли на UTF-8
    setlocale(LC_ALL, "Russian");
    //system("chcp 1251");
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    try {
        // Параметры запроса
        std::string host = "otzovik.com";
        std::string port = "80";
        std::string target = "review_14198894.html";
        int version = 11;


        // Выполняем GET запрос и получаем имя временного файла
        auto parserHtml = http_get(host, port, target, version);
        TmpFile tempFile("./tmp");
        tempFile.writeToFile(parserHtml);
        std::cout << "Имя временного файла: " << tempFile.getUniqueName() << std::endl;
        //tempFile.readFromFile;

    }
    catch (const HttpClientError& e) {
        std::cerr << "HTTP ошибка: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }
    catch (const std::exception& e) {
        std::cerr << "Ошибка:" << e.what() << std::endl;
        return EXIT_FAILURE;
    }

}