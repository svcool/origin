#include <globlas.h>
#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <locale>
#include <algorithm>
#include <cctype>
#include <sstream>
#include <map>
#include <windows.h> // ��� SetConsoleCP � SetConsoleOutputCP

using namespace std;

string clean_and_process_text(const string& html) {
    // �������� &nbsp; �� ������, ��������� �������
    string no_nbsp = regex_replace(html, regex(R"(&[^;\s]*;)", regex::icase), " ");

    // �������� �������� � ������
    string no_scripts = regex_replace(no_nbsp, regex(R"(<(script|style|code|noscript|a|button)[^>]*>[\s\S]*?</\1>|<input[^>]*\/?>)", regex::icase), " ");

    // �������� HTML-�����
    string no_html = regex_replace(no_scripts, regex(R"(<[^>]*>)"), " ");

    // �������� ������ ���������� � ������ ��������
    string cleaned_text = regex_replace(no_html, regex(R"([.,!?;:'\"(){}[\]<>]|\n|\t)"), " ");
    cleaned_text = regex_replace(cleaned_text, regex(R"([\s]+)"), " ");

    // �������������� ������ � ������ �������
    transform(cleaned_text.begin(), cleaned_text.end(), cleaned_text.begin(),
        [](unsigned char c) { return std::tolower(c); });

    // �������� ������ �������� � ������ � ����� ������
    cleaned_text.erase(cleaned_text.begin(), find_if(cleaned_text.begin(), cleaned_text.end(), [](unsigned char c) { return !isspace(c); }));
    cleaned_text.erase(find_if(cleaned_text.rbegin(), cleaned_text.rend(), [](unsigned char c) { return !isspace(c); }).base(), cleaned_text.end());

    // ���������� ���� �� �����
    istringstream iss(cleaned_text);
    string word;
    string filtered_text;

    while (iss >> word) {
        if (word.length() >= 3 && word.length() <= 32) {
            filtered_text += word + " "; // ��������� ������ ����� �����
        }
    }

    // ������� ������ ������ � �����
    if (!filtered_text.empty()) {
        filtered_text.pop_back(); // ������� ��������� ������
    }

    return filtered_text;
}

int main3777() {
    // setlocale(LC_ALL, "Russian");
   // system("chcp 1251");

    // ��������� ��������� ������� �� UTF-8
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    // �������� HTML �����
    ifstream file("xgconsole.xml");
    if (!file.is_open()) {
        cerr << "������ ��� �������� �����!" << endl;
        return 1;
    }

    // ������ ����������� �����
    string html((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
    file.close();

    // ������� � ��������� ������
    string cleaned_text = clean_and_process_text(html);

    // �������� �� ������� ���������� ������
    if (cleaned_text.empty()) {
        cerr << "��������� ����� ����!" << endl;
        return 1; // ��� ����������� ������ ������ ��������
    }

    // ����� ����������
    cout << "��������� �����:" << endl;
    cout << cleaned_text << endl;

    // ������� ����� ��� �������� ���� � �� ������
    map<string, int> word_freq;

    // ��������� ����� �� �����
    istringstream iss(cleaned_text);
    string word;
    while (iss >> word) {
        // ����������� ������� ����� � �����
        ++word_freq[word];
    }

    // ������� ����������
    cout << "������� ����:" << endl;
    for (const auto& pair : word_freq) {
        cout << pair.first << ": " << pair.second << endl;
    }


    return 0;
}
