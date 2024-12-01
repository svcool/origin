#include "indexator.h"
//********************************************************************************************************************
   std::string clean_and_process_text(const std::string& html) {
    // �������� &nbsp; �� ������, ��������� �������
    std::string no_nbsp = std::regex_replace(html, std::regex(R"(&[^;\s]*;)", std::regex::icase), " ");

    // �������� �������� � ������
    std::string no_scripts = std::regex_replace(no_nbsp, std::regex(R"(<(script|style|code|noscript|a|button)[^>]*>[\s\S]*?</\1>|<input[^>]*\/?>)", std::regex::icase), " ");

    // �������� HTML-�����
    std::string no_html = std::regex_replace(no_scripts, std::regex(R"(<[^>]*>)"), " ");

    // �������� ������ ���������� � ������ ��������
    std::string cleaned_text = std::regex_replace(no_html, std::regex(R"([.,!?;:'\"(){}[\]<>-]|[\n\t])"), " ");
    cleaned_text = std::regex_replace(cleaned_text, std::regex(R"([\s]+)"), " ");

    // �������������� ������ � ������ �������
    std::transform(cleaned_text.begin(), cleaned_text.end(), cleaned_text.begin(),
        [](unsigned char c) { return std::tolower(c); });

    // �������� ������ �������� � ������ � ����� ������
    cleaned_text.erase(cleaned_text.begin(), std::find_if(cleaned_text.begin(), cleaned_text.end(), [](unsigned char c) { return !std::isspace(c); }));
    cleaned_text.erase(std::find_if(cleaned_text.rbegin(), cleaned_text.rend(), [](unsigned char c) { return !std::isspace(c); }).base(), cleaned_text.end());

    // ���������� ���� �� �����
    std::istringstream iss(cleaned_text);
    std::string word;
    std::string filtered_text;

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
//********************************************************************************************************************
// ������� ��� �������� ������� ���� � ������
std::map<std::string, int> countWordFrequency(const std::string& text) {
    std::map<std::string, int> word_freq; // ������� ����� ��� �������� ���� � �� ������
    std::istringstream iss(text); // ���������� istringstream ��� �������� ������ �� �����
    std::string word;

    while (iss >> word) {
        // ����������� ������� ����� � �����
        ++word_freq[word];
    }

    return move(word_freq); // ���������� ����� � ��������� ����
}

//********************************************************************************************************************

std::vector<std::string> extractLinks(const std::string& html, const std::string& domain) {
    // ���������� ��������� ��� ������ ������ � �������� href
    std::regex href_regex(R"(<a\s+[^>]*href=["']((http://[^"']+)|(https://[^"']+)|(/[^"']+))["'][^>]*>)");
    std::smatch match;

    std::vector<std::string> links;

    // ����� ���� ����������
    std::string::const_iterator searchStart(html.cbegin());
    while (std::regex_search(searchStart, html.cend(), match, href_regex)) {
        std::string link = match[1]; // ��������� ��������� ������

        // ��������, �������� �� ������ �������������
        if (link[0] == '/') {
            link = "http://" + domain + link; // ����������� � ������ ������
        }

        links.push_back(link); // ��������� ������
        searchStart = match.suffix().first; // ���������� �����
    }

    return move(links); // ���������� ������ ��������� ������
}
//********************************************************************************************************************
std::pair<std::string, std::string> fixURL(const std::string& url) {

    std::string host;
    std::string target;
    std::string cleanUrl = std::regex_replace(url, std::regex(R"(^https?://)"), "");  // ������� �������� (http:// ��� https://)
    size_t pos = cleanUrl.find("/");// ������� ������� ������� ������� '/' ����� �������� URL

    if (pos == std::string::npos) { // ���� '/' �� ������, ������, ���� URL - ��� ����
        host = cleanUrl;
        target = "/";
    }
    else {
        // ��������� ������� URL � ����
        host = cleanUrl.substr(0, pos); // ��������� ������� URL � ����
        target = cleanUrl.substr(pos);   // ����
    }
    return std::make_pair(host, target);
}
//*********************************************************************************************************************