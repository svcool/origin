#include <iostream>

int main() {
    setlocale(LC_ALL, "Russian");
    system("chcp 1251"); // настраиваем кодировку консоли
    int age = 0; //возраст
    std::string gender; //пол
    std::string zodiak; //знак зодиака
    std::string prediction; //предсказание
    bool type_zodiak = false; // тип зодиака
    std::cout << "Введите пол(м/ж): ";
    std::cin >> gender;
    std::cout << "Введите знак зодиака \n(дева, телец, козерог, рак, рыба, скорпион): ";
    std::cin >> zodiak;
    std::cout << "Введите возраст: ";
    std::cin >> age;
    if (zodiak == "дева" || zodiak == "телец" || zodiak == "козерог") type_zodiak = true; //землянной знак
    if (zodiak == "рак" || zodiak == "рыба" || zodiak == "скорпион") type_zodiak = false; //водный знак
    //std::cout << type_zodiak << "bool";
    if (age >= 15 && age <= 30 && gender == "ж" && type_zodiak == 0)
        prediction = "Сегодняшний вечер подходит для общения с друзьями, проведения домашних праздников и импровизированных вечеринок.Будет не только весело, но и интересно : найдётся дело, которое увлечёт всех.";
    else if (age <= 40 && gender == "м" && type_zodiak == 1)
        prediction = "Сегодня очень плодотворный день.Можно добиться того, что прежде казалось почти невозможным.";
    else prediction = "Гороскоп для вас находится в разработке. Приходите чуточку позже ;)";

    std::cout << "Ваше предсказание:\n" << prediction;

    return 0;
}