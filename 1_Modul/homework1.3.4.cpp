#include <iostream>

int main() {
    setlocale(LC_ALL, "Russian");
    int num1 = 0, num2 = 0; // ���������� � ������������ ����� 1 �2
    int num; //��������� ���������� ��� �����
    std::string num_word = ""; //��������� ���������� ��� �������
    std::cout << "������� ����� �����: ";
    std::cin >> num1;
    std::cout << "������� ����� �����: ";
    std::cin >> num2;
    //############################### 
      //�������� ��������� ��������
    if (((num1 < -100) || (num1 > 100)) || ((num2 < -100) || (num2 > 100))) {
        std::cout << "\n������! ���� �� ����� ��� ���������!" << std::endl;
        exit(0);
    }
    //###############################
        //��������� ������� �����
    num = num1;
    //������� �����
    if (num < 0) {
        num_word += "����� ";
        num *= -1;
    }
    if (num > 19 || num < 10) {
        switch (num / 10) {
        case 0: num_word += ""; break;
        case 2: num_word += "�������� "; break;
        case 3: num_word += "�������� "; break;
        case 4: num_word += "����� "; break;
        case 5: num_word += "��������� "; break;
        case 6: num_word += "���������� "; break;
        case 7: num_word += "��������� "; break;
        case 8: num_word += "����������� "; break;
        case 9: num_word += "��������� "; break;
        case 10: num_word += "��� "; break;
            // default: std::cout << "����� �� ������"; break;
        }
        switch (num % 10) {
        case 0: (num / 10) == 0 ? num_word += "���� " : ""; break;
        case 1: num_word += "���� "; break;
        case 2: num_word += "��� "; break;
        case 3: num_word += "��� "; break;
        case 4: num_word += "������ "; break;
        case 5: num_word += "���� "; break;
        case 6: num_word += "����� "; break;
        case 7: num_word += "���� "; break;
        case 8: num_word += "������ "; break;
        case 9: num_word += "������ "; break;
            //default: std::cout << "����� �� ������"; break;
        }
    }
    else {
        switch (num) {
        case 10: num_word += "������ "; break;
        case 11: num_word += "����������� "; break;
        case 12: num_word += "���������� "; break;
        case 13: num_word += "���������� "; break;
        case 14: num_word += "������������ "; break;
        case 15: num_word += "���������� "; break;
        case 16: num_word += "����������� "; break;
        case 17: num_word += "���������� "; break;
        case 18: num_word += "������������ "; break;
        case 19: num_word += "������������"; break;
            //default: std::cout << "����� �� ������"; break;
        }
    }
    //##################################  
      // ������� ���������
    if (num1 < num2) {
        num_word += "������ ��� ";
    }
    else if (num1 == num2) {
        num_word += "����� ����� ";
    }
    else num_word += "������ ��� ";
    //##################################  
    // ��������� ������� �����
    num = num2;
    //������� �����
    if (num < 0) {
        num_word += "����� ";
        num *= -1;
    }
    if (num > 19 || num < 10) {
        switch (num / 10) {
        case 0: num_word += ""; break;
        case 2: num_word += "�������� "; break;
        case 3: num_word += "�������� "; break;
        case 4: num_word += "����� "; break;
        case 5: num_word += "��������� "; break;
        case 6: num_word += "���������� "; break;
        case 7: num_word += "��������� "; break;
        case 8: num_word += "����������� "; break;
        case 9: num_word += "��������� "; break;
        case 10: num_word += "��� "; break;
            // default: std::cout << "����� �� ������"; break;
        }
        switch (num % 10) {
        case 0: (num / 10) == 0 ? num_word += "���� " : ""; break;
        case 1: num_word += "���� "; break;
        case 2: num_word += "��� "; break;
        case 3: num_word += "��� "; break;
        case 4: num_word += "������ "; break;
        case 5: num_word += "���� "; break;
        case 6: num_word += "����� "; break;
        case 7: num_word += "���� "; break;
        case 8: num_word += "������ "; break;
        case 9: num_word += "������ "; break;
            //default: std::cout << "����� �� ������"; break;
        }
    }
    else {
        switch (num) {
        case 10: num_word += "������ "; break;
        case 11: num_word += "����������� "; break;
        case 12: num_word += "���������� "; break;
        case 13: num_word += "���������� "; break;
        case 14: num_word += "������������ "; break;
        case 15: num_word += "���������� "; break;
        case 16: num_word += "����������� "; break;
        case 17: num_word += "���������� "; break;
        case 18: num_word += "������������ "; break;
        case 19: num_word += "������������"; break;
            //default: std::cout << "����� �� ������"; break;
        }
    }

    std::cout << "\n" << num_word;
    return 0;
}