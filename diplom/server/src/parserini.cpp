#include "parserini.h"
//***********************************************************************************************************
void checkRequiredKeys(const boost::property_tree::ptree& pt, const std::vector<std::string>& keys) {
	std::vector<std::string> missingKeys;

	for (const auto& key : keys) {
		if (!pt.get_optional<std::string>(key)) {
			missingKeys.push_back(key);
		}
	}

	if (!missingKeys.empty()) {
		std::string errorMessage = "Не найдены ключи:";
		for (const auto& key : missingKeys) {
			errorMessage += "\n- " + key;
		}
		throw ParserError(errorMessage);
	}
	else {
		std::cout << "Все ключи в ini файле найдены" << std::endl;
	}
}
//***********************************************************************************************************
void readSettings(const std::string& filename, boost::property_tree::ptree& pt) {
	std::ifstream s(filename);
	if (!s) {
		throw std::runtime_error("Файл " + filename + " недоступен");
	}
	boost::property_tree::ini_parser::read_ini(filename, pt);
}
//***********************************************************************************************************
void writeSettings(const std::string& filename, boost::property_tree::ptree& pt) {
	boost::property_tree::ini_parser::write_ini(filename, pt);
	std::cout << "INI file updated successfully." << std::endl;
}
//***********************************************************************************************************
