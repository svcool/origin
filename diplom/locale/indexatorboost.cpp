#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <boost/locale.hpp>

using namespace std;

string clean_html(const string& html) {
    // �������� HTML-�����
    return regex_replace(html, regex(R"(<[^>]*>)"), "");
}

string remove_punctuation_and_whitespace(const string& text) {
    // �������� ������ ���������� � ������ ��������
    string cleaned_text = regex_replace(text, regex(R"([\s]+)"), " "); // ������ ���������� �������� �� ����
    cleaned_text = regex_replace(cleaned_text, regex(R"([.,!?;:'\"(){}[\]<>]|\n|\t)"), ""); // �������� ������ ����������
    return cleaned_text;
}

string to_lowercase(const string& text) {
    return boost::locale::to_lower(text);
}

int main6() {
    // ������������� ������ Boost
    setlocale(LC_ALL, "Russian");
    system("chcp 1251");
    boost::locale::generator gen;
    std::locale loc = gen("en_US.UTF-8"); // �������� �� ���� ������
    std::locale::global(loc);

    // �������� HTML �����
    ifstream file("xgconsole.xml");
    if (!file.is_open()) {
        cerr << "������ ��� �������� �����!" << endl;
        return 1;
    }

    // ������ ����������� �����
    string html((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
    file.close();

    // ������� HTML
    string no_html = clean_html(html);

    // �������� ������ ���������� � ��������
    string cleaned_text = remove_punctuation_and_whitespace(no_html);

    // �������� �� ������� ���������� ������
    if (cleaned_text.empty()) {
        cerr << "��������� ����� ����!" << endl;
        return 1; // ��� ����������� ������ ������ ��������
    }

    // �������������� ������ � ������ �������
    string final_text;
    try {
        final_text = to_lowercase(cleaned_text);
    }
    catch (const std::exception& e) {
        cerr << "������ ��� �������������� ������ � ������ �������: " << e.what() << endl;
        return 1;
    }

    // ����� ����������
    cout << "��������� �����:" << endl;
    cout << final_text << endl;

    return 0;
}
