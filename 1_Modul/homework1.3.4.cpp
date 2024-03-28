#include <iostream>

int main() {
    setlocale(LC_ALL, "Russian");
    int num1 = 0, num2 = 0; // объявление и иницилизация чисел 1 и2
    int num; //временные переменная для чисел
    std::string num_word = ""; //временная переменная для прописи
    std::cout << "Введите целое число: ";
    std::cin >> num1;
    std::cout << "Введите целое число: ";
    std::cin >> num2;
    //############################### 
      //проверка диапазона значений
    if (((num1 < -100) || (num1 > 100)) || ((num2 < -100) || (num2 > 100))) {
        std::cout << "\nОшибка! Одно из чисел вне диапазона!" << std::endl;
        exit(0);
    }
    //###############################
        //обработка первого числа
    num = num1;
    //пропись знака
    if (num < 0) {
        num_word += "минус ";
        num *= -1;
    }
    if (num > 19 || num < 10) {
        switch (num / 10) {
        case 0: num_word += ""; break;
        case 2: num_word += "двадцать "; break;
        case 3: num_word += "тридцать "; break;
        case 4: num_word += "сорок "; break;
        case 5: num_word += "пятьдесят "; break;
        case 6: num_word += "шестьдесят "; break;
        case 7: num_word += "семьдесят "; break;
        case 8: num_word += "восемьдесят "; break;
        case 9: num_word += "девяносто "; break;
        case 10: num_word += "сто "; break;
            // default: std::cout << "Число не задано"; break;
        }
        switch (num % 10) {
        case 0: (num / 10) == 0 ? num_word += "ноль " : ""; break;
        case 1: num_word += "один "; break;
        case 2: num_word += "два "; break;
        case 3: num_word += "три "; break;
        case 4: num_word += "четыре "; break;
        case 5: num_word += "пять "; break;
        case 6: num_word += "шесть "; break;
        case 7: num_word += "семь "; break;
        case 8: num_word += "восемь "; break;
        case 9: num_word += "девять "; break;
            //default: std::cout << "Число не задано"; break;
        }
    }
    else {
        switch (num) {
        case 10: num_word += "десять "; break;
        case 11: num_word += "одиннадцать "; break;
        case 12: num_word += "двенадцать "; break;
        case 13: num_word += "тринадцать "; break;
        case 14: num_word += "четырнадцать "; break;
        case 15: num_word += "пятнадцать "; break;
        case 16: num_word += "шестнадцать "; break;
        case 17: num_word += "семнадцать "; break;
        case 18: num_word += "восемнадцать "; break;
        case 19: num_word += "девятнадцать"; break;
            //default: std::cout << "Число не задано"; break;
        }
    }
    //##################################  
      // пропись сравнения
    if (num1 < num2) {
        num_word += "меньше чем ";
    }
    else if (num1 == num2) {
        num_word += "равно числу ";
    }
    else num_word += "больше чем ";
    //##################################  
    // обработка второго числа
    num = num2;
    //пропись знака
    if (num < 0) {
        num_word += "минус ";
        num *= -1;
    }
    if (num > 19 || num < 10) {
        switch (num / 10) {
        case 0: num_word += ""; break;
        case 2: num_word += "двадцать "; break;
        case 3: num_word += "тридцать "; break;
        case 4: num_word += "сорок "; break;
        case 5: num_word += "пятьдесят "; break;
        case 6: num_word += "шестьдесят "; break;
        case 7: num_word += "семьдесят "; break;
        case 8: num_word += "восемьдесят "; break;
        case 9: num_word += "девяносто "; break;
        case 10: num_word += "сто "; break;
            // default: std::cout << "Число не задано"; break;
        }
        switch (num % 10) {
        case 0: (num / 10) == 0 ? num_word += "ноль " : ""; break;
        case 1: num_word += "один "; break;
        case 2: num_word += "два "; break;
        case 3: num_word += "три "; break;
        case 4: num_word += "четыре "; break;
        case 5: num_word += "пять "; break;
        case 6: num_word += "шесть "; break;
        case 7: num_word += "семь "; break;
        case 8: num_word += "восемь "; break;
        case 9: num_word += "девять "; break;
            //default: std::cout << "Число не задано"; break;
        }
    }
    else {
        switch (num) {
        case 10: num_word += "десять "; break;
        case 11: num_word += "одиннадцать "; break;
        case 12: num_word += "двенадцать "; break;
        case 13: num_word += "тринадцать "; break;
        case 14: num_word += "четырнадцать "; break;
        case 15: num_word += "пятнадцать "; break;
        case 16: num_word += "шестнадцать "; break;
        case 17: num_word += "семнадцать "; break;
        case 18: num_word += "восемнадцать "; break;
        case 19: num_word += "девятнадцать"; break;
            //default: std::cout << "Число не задано"; break;
        }
    }

    std::cout << "\n" << num_word;
    return 0;
}