//#include "pugixml.hpp"
//#include <iostream>
//
//int main() {
//    pugi::xml_document doc;
//
//    // �������� XML-�����
//    if (!doc.load_file("xgconsole.xml")) {
//        std::cerr << "Error loading XML file!" << std::endl;
//        return -1;
//    }
//
//    // ���������� XPath-������� ��� ��������� ���� ��������� <a>
//    pugi::xpath_query query_links("//a/@href");
//    pugi::xpath_node_set links = query_links.evaluate_node_set(doc);
//
//    std::cout << "Found links to other pages:" << std::endl;
//    for (size_t i = 0; i < links.size(); ++i) {
//        // �������� ���� <a>
//        pugi::xml_node a_node = links[i].node();
//
//        // �������� �������� �������� href
//        const char* href_value = a_node.attribute("href").value();
//
//        // ���������, ���� �� ������� href
//        if (href_value && *href_value) {
//            std::cout << "Href: " << href_value << std::endl; // ����� �������� �������� href
//        }
//        else {
//            std::cout << "Href attribute is missing or empty for this <a> element." << std::endl;
//        }
//
//        // ������� ���������� ���� <a>
//        std::cout << "Node content: " << a_node.child_value() << std::endl;
//    }
//
//    return 0;
//}
#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <vector>

using namespace std;

int main() {


    // ������� �������� ���
    string domain = "https://example.com"; // �������� �� ���� �������� ���
    // �������� HTML �����
    ifstream file("xgconsole.xml");
    if (!file.is_open()) {
        cerr << "������ ��� �������� �����!" << endl;
        return 1;
    }

    // ������ ����������� �����
    string html((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
    file.close();

    // ���������� ��������� ��� ������ ������ � �������� href
    regex href_regex(R"(<a\s+[^>]*href=["']([^"']+)["'][^>]*>)");
    smatch match;

    vector<string> links;

    // ����� ���� ����������
    string::const_iterator searchStart(html.cbegin());
    while (regex_search(searchStart, html.cend(), match, href_regex)) {
        string link = match[1]; // ��������� ��������� ������

        // ��������, �������� �� ������ �������������
        if (!link.empty() && link[0] == '/') {
            link = domain + link; // ����������� � ������ ������
        }

        links.push_back(link); // ��������� ������ (������ ��� �������������)
        searchStart = match.suffix().first; // ���������� �����
    }

    // ����� ��������� ������
    cout << "��������� ������:" << endl;
    for (const auto& link : links) {
        cout << link << endl;
    }

    return 0;
}