#ifndef SETTINGS_H
#define SETTINGS_H

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/ini_parser.hpp>
#include <boost/property_tree/detail/file_parser_error.hpp>
#include <iostream>
#include <fstream>
#include "except.h"
#include <string>
#include <vector>

void checkRequiredKeys(const boost::property_tree::ptree& pt, const std::vector<std::string>& keys);// Проверяет наличие обязательных ключей в ptree

void readSettings(const std::string& filename, boost::property_tree::ptree& pt);// Читает настройки из INI файла

void writeSettings(const std::string& filename, boost::property_tree::ptree& pt);// Записывает настройки в INI файл

#endif // SETTINGS_H
