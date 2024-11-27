#include <globals.h>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/ini_parser.hpp>
#include <boost/property_tree/detail/file_parser_error.hpp>


void checkRequiredKeys(const boost::property_tree::ptree& pt, const std::vector<std::string>& keys) {
    std::vector<std::string> missingKeys;

    for (const auto& key : keys) {
        if (!pt.get_optional<std::string>(key)) {
            missingKeys.push_back(key);
        }
    }

    if (!missingKeys.empty()) {
        std::string errorMessage = "Missing keys in INI file:";
        int x = missingKeys.size();
        for (const auto& key : missingKeys) {
            errorMessage += "\n- " + key;
        }
        throw ParserError(errorMessage); // Выбрасываем исключение
    }
    else {
        std::cout << "All required keys are present." << std::endl;
    }
}

int main3() {
    
    boost::property_tree::ptree pt;

    // Список необходимых ключей
    std::vector<std::string> requiredKeys = {
        "Database.host",
        "Database.port",
        "Database.dbname",
        "Database.user",
        "Database.password",
        "Spider.page",
        "Spider.recursion",
        "Crowler.address",
        "Crowler.port"
    };

    try {
        // Чтение из INI файла
        std::ifstream s("settings.ini");
        if (!s) {
            throw std::runtime_error("Unable to open settings.ini file.");
        }

        boost::property_tree::ini_parser::read_ini("settings.ini", pt);
        
          checkRequiredKeys(pt, requiredKeys); // Проверка наличия всех необходимых ключей
         

          // Значения из секции Database
          std::string dbHost = pt.get<std::string>("Database.host");
          int dbPort = pt.get<int>("Database.port");
          std::string dbName = pt.get<std::string>("Database.dbname");
          std::string dbUsername = pt.get<std::string>("Database.user");
          std::string dbPassword = pt.get<std::string>("Database.password");
          
          std::cout << "Database DB Name: " << dbName << std::endl;
          std::cout << "Database Host: " << dbHost << std::endl;
          std::cout << "Database Port: " << dbPort << std::endl;
          std::cout << "Database Username: " << dbUsername << std::endl;

          //Значения из секции Spider
          std::string page = pt.get<std::string>("Spider.page");
          std::string recursion = pt.get<std::string>("Spider.recursion");

          std::cout << "Page: " << page << std::endl;
          std::cout << "Recursion: " << recursion << std::endl;

          // Значения из секции Crowler
          std::string addressCrowler = pt.get<std::string>("Crowler.address");
          int portCrowler = pt.get<int>("Crowler.port");
          
          std::cout << "Crowler Address: " << addressCrowler << std::endl;
          std::cout << "Crowler Port: " << portCrowler << std::endl;

    }
    catch (const boost::property_tree::ini_parser::ini_parser_error& e) {
        std::cerr << "Error reading INI file: " << e.what() << std::endl;
    }
    catch (const ParserError& err) {
        std::cout << err.what() << std::endl;
    }

    // Изменение значений и запись обратно в INI файл
    try {
        pt.put("Crowler.address", "1.0.1"); // Обновление версии

        boost::property_tree::ini_parser::write_ini("settings.ini", pt);
        std::cout << "INI file updated successfully." << std::endl;
    }
    catch (const boost::property_tree::ini_parser::ini_parser_error& e) {
        std::cerr << "Error writing INI file: " << e.what() << std::endl;
    }

    return 0;
}