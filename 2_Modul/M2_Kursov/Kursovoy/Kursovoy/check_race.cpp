#include "check_race.h"
std::string check_race(Transport* tr, Race* race) {
	std::cout << std::endl;
	if (tr->get_count() != 0) { std::cout << tr->get_name() << " уже зарегистрирован!" << std::endl; }
	else {
		if (tr->get_type() == race->get_type() || race->get_type() == 3) {
			std::cout << tr->get_name() << " успешно зарегистрирован!" << std::endl;
			tr->set_count(1);
			return tr->get_name();
		}
		else {
			std::cout << "Попытка зарегистрировать неправильный тип транспортного средства!" << std::endl;
			return "";
		}
	}
	return "";
}