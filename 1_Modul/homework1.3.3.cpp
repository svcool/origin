#include <iostream>

int main() {
    setlocale(LC_ALL, "Russian");
    system("chcp 1251"); // ����������� ��������� �������
    int age = 0; //�������
    std::string gender; //���
    std::string zodiak; //���� �������
    std::string prediction; //������������
    bool type_zodiak = false; // ��� �������
    std::cout << "������� ���(�/�): ";
    std::cin >> gender;
    std::cout << "������� ���� ������� \n(����, �����, �������, ���, ����, ��������): ";
    std::cin >> zodiak;
    std::cout << "������� �������: ";
    std::cin >> age;
    if (zodiak == "����" || zodiak == "�����" || zodiak == "�������") type_zodiak = true; //��������� ����
    if (zodiak == "���" || zodiak == "����" || zodiak == "��������") type_zodiak = false; //������ ����
    //std::cout << type_zodiak << "bool";
    if (age >= 15 && age <= 30 && gender == "�" && type_zodiak == 0)
        prediction = "����������� ����� �������� ��� ������� � ��������, ���������� �������� ���������� � ����������������� ���������.����� �� ������ ������, �� � ��������� : ������� ����, ������� ������� ����.";
    else if (age <= 40 && gender == "�" && type_zodiak == 1)
        prediction = "������� ����� ������������ ����.����� �������� ����, ��� ������ �������� ����� �����������.";
    else prediction = "�������� ��� ��� ��������� � ����������. ��������� ������� ����� ;)";

    std::cout << "���� ������������:\n" << prediction;

    return 0;
}