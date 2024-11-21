#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/ini_parser.hpp>
#include <iostream>

int main() {
    boost::property_tree::ptree pt;

    // Reading from an INI file
    try {
        boost::property_tree::ini_parser::read_ini("config.ini", pt);
        std::string value = pt.get<std::string>("SectionName.KeyName");
        std::cout << "Value: " << value << std::endl;
    } catch (const boost::property_tree::ini_parser::ini_parser_error& e) {
        std::cerr << "Error reading INI file: " << e.what() << std::endl;
    }

    // Writing to an INI file
    try {
        pt.put("SectionName.KeyName", "NewValue");
        boost::property_tree::ini_parser::write_ini("config.ini", pt);
    } catch (const boost::property_tree::ini_parser::ini_parser_error& e) {
        std::cerr << "Error writing INI file: " << e.what() << std::endl;
    }

    return 0;
}

; Это комментарий, который объясняет, что делает секция
[General]
; Настройки общего характера
app_name = MyApplication
version = 1.0.0
author = John Doe

[Database]
host = localhost
port = 5432
username = user
password = secret

[Logging]
; Уровень логирования: DEBUG, INFO, WARN, ERROR
log_level = INFO
log_file = app.log

[Features]
enable_feature_x = true
enable_feature_y = false

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/ini_parser.hpp>
#include <iostream>
#include <string>

int main() {
    boost::property_tree::ptree pt;

    // Чтение из INI файла
    try {
        boost::property_tree::ini_parser::read_ini("config.ini", pt);

        // Получение значений из секции General
        std::string app_name = pt.get<std::string>("General.app_name");
        std::string version = pt.get<std::string>("General.version");
        std::string author = pt.get<std::string>("General.author");

        std::cout << "Application Name: " << app_name << std::endl;
        std::cout << "Version: " << version << std::endl;
        std::cout << "Author: " << author << std::endl;

        // Получение значений из секции Database
        std::string db_host = pt.get<std::string>("Database.host");
        int db_port = pt.get<int>("Database.port");
        std::string db_username = pt.get<std::string>("Database.username");
        std::string db_password = pt.get<std::string>("Database.password");

        std::cout << "Database Host: " << db_host << std::endl;
        std::cout << "Database Port: " << db_port << std::endl;
        std::cout << "Database Username: " << db_username << std::endl;
        // Не выводим пароль для безопасности
        // std::cout << "Database Password: " << db_password << std::endl;

        // Получение значений из секции Logging
        std::string log_level = pt.get<std::string>("Logging.log_level");
        std::string log_file = pt.get<std::string>("Logging.log_file");

        std::cout << "Log Level: " << log_level << std::endl;
        std::cout << "Log File: " << log_file << std::endl;

        // Получение значений из секции Features
        bool enable_feature_x = pt.get<bool>("Features.enable_feature_x");
        bool enable_feature_y = pt.get<bool>("Features.enable_feature_y");

        std::cout << "Enable Feature X: " << (enable_feature_x ? "true" : "false") << std::endl;
        std::cout << "Enable Feature Y: " << (enable_feature_y ? "true" : "false") << std::endl;

    } catch (const boost::property_tree::ini_parser::ini_parser_error& e) {
        std::cerr << "Error reading INI file: " << e.what() << std::endl;
    }

    // Изменение значений и запись обратно в INI файл
    try {
        pt.put("General.version", "1.0.1"); // Обновление версии
        pt.put("Logging.log_level", "DEBUG"); // Изменение уровня логирования

        boost::property_tree::ini_parser::write_ini("config.ini", pt);
        std::cout << "INI file updated successfully." << std::endl;
    } catch (const boost::property_tree::ini_parser::ini_parser_error& e) {
        std::cerr << "Error writing INI file: " << e.what() << std::endl;
    }

    return 0;
}

Find More