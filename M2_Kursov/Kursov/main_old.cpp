#include <iostream>
#include <string>
#include "2_race.h"
//#include "1_transport.h"
struct RaceName
{
	std::string race1 = "Гонка для наземного транспорта";
	std::string race2 = "Гонка для воздушного транспорта";
	std::string race3 = "Гонка для наземного и воздушного транспорта";
};

enum class Enum_TransportName {
	none,
	tn1,
	tn2,
	tn3,
	tn4,
	tn5,
	tn6,
	tn7,
}; 
enum class Enum_RaceName {
	none,
	race1,
	race2,
	race3,
};



class Transport {
protected:
	std::string name{};
	int count;
	int type{};
	int compute{};
public:
	Transport(std::string name) :name(name) {}
	int get_type() { return type; };
	int get_count() { return count; };
	int set_count() { return count = 1; }
	const std::string get_name() { return name; };
	
	//int compute() { return compute; }
};

class T_ground :public Transport {
protected:
	int type{};	int count{};
	T_ground(int type, std::string name, int count) : Transport(name), type(type) {}
public:
	T_ground(int type, std::string name) : Transport(name), type(type) {}
	int get_count() { return count; };
	int set_count() { return count = 1; }
};

class T_fly :public Transport {
protected:
	int type; int count{};
	T_fly(int type, std::string name, int count) :Transport(name), type(type) {}
public:
	T_fly(int type, std::string name) :Transport(name), type(type) {}
	int get_count() { return count; };
	int set_count() { return count = 1; }
};

class Camel : public T_ground {
	int distance{};
	int compute{};
	Camel(int type, std::string name, int count) : T_ground(type, name, count) {}
public:
	Camel(int type, std::string name) : T_ground(type, name) {}	
};
class Camel_fast:public T_ground {
	Camel_fast(int type, std::string name, int count) : T_ground(type, name, count) {}
public:
	Camel_fast(int type, std::string name) : T_ground(type, name) {}
};

class Boots :public T_ground {
	Boots(int type, std::string name, int count) : T_ground(type, name, count) {}
public:
	Boots(int type, std::string name) : T_ground(type, name) {}

};

class Kentavr :public T_ground {
	Kentavr(int type, std::string name, int count) : T_ground(type, name, count) {}
public:
	Kentavr(int type, std::string name) : T_ground(type, name) {}

};


class Eagle : public T_fly {
	Eagle(int type, std::string name, int count) : T_fly(type, name, count) {}
public:
	Eagle(int type, std::string name) : T_fly(type, name) {}

};

class Carpet : public T_fly {
	Carpet(int type, std::string name, int count) : T_fly(type, name, count) {}
public:
	Carpet(int type, std::string name) : T_fly(type, name) {}

};

class Broom : public T_fly {
	Broom(int type, std::string name, int count) : T_fly(type, name, count) {}
public:
	Broom(int type, std::string name) : T_fly(type, name){}

};

std::string check_race(Transport* tr, Race& race);

int main() {
	setlocale(LC_ALL, "Russian");
	system("chcp 1251");
	T_ground t_ground(1, "Наземный транспорт");
	T_fly t_fly(2, "Воздушный транспорт");
	Camel camel(1,"Верблюд");
	Camel_fast camelfast(1, "Верблюд-быстроход");
	Kentavr	kentavr(1, "Кентавр");
	Boots boots(1, "Ботинки-вездеходы");
	Eagle eagle(2, "Орёл");
	Carpet carpet(2, "Ковер-самолет");
	Broom broom(2, "Метла");
	Transport* tr_arr[]{&camel, &camelfast, &kentavr, &boots, &eagle, &carpet, &broom };
	std::string temp_name, name_transport;
	RaceName racename; //наименование гонок
	static unsigned count{}; //счетчик транспорных средств
	int type{}, S{}, a{}, d{}; //type-тип гонки, S - расстояние, a - транспорт, d - действие выбора
	std::string Rn{""}; //название гонки
	std::cout << "Добро пожаловать в гоночный симулятор!" << std::endl;
	
	do {
		std::cout << "1. " << racename.race1 << std::endl;
		std::cout << "2. " << racename.race2 << std::endl;
		std::cout << "3. " << racename.race3 << std::endl;
		std::cout << "0. Выход" << std::endl;
		std::cout << "Выберите тип гонок: "; std::cin >> type;
		Enum_RaceName race_name = static_cast<Enum_RaceName>(type);
		switch (race_name) {
		case Enum_RaceName::none: std::cout << "До свидания" << std::endl; return 0;
		case Enum_RaceName::race1: Rn = racename.race1; break;
		case Enum_RaceName::race2: Rn = racename.race2; break;
		case Enum_RaceName::race3: Rn = racename.race3; break;
		default: std::cout << "Неправильный номер!" << std::endl;
		}
	} while (type == 0 || Rn == "");
	std::cout << "Укажите длину дистанции (должна быть положительной): "; std::cin >> S;
	Race race(type, S, Rn);
	std::cout << race.get_type() << std::endl;

	std::cout << "Должно быть зарегистрировано хотя бы 2 транспортных средства" << std::endl;
do {
		std::cout << "1. Зарегистрировать транспорт" << std::endl;
		if (count > 2) { std::cout << "2. Начать гонку" << std::endl; }
		std::cout << "Выберите действие: "; std::cin >> d;
		std::cout << race.get_name() << ". Расстояние: " << race.get_distance() << std::endl;
	do {
		std::cout << "1. " << boots.get_name() << std::endl;
		std::cout << "2. " << broom.get_name() << std::endl;
		std::cout << "3. " << camel.get_name() << std::endl;
		std::cout << "4. " << kentavr.get_name() << std::endl;
		std::cout << "5. " << eagle.get_name() << std::endl;
		std::cout << "6. " << camelfast.get_name() << std::endl;
		std::cout << "7. " << carpet.get_name() << std::endl;
		std::cout << "0. Закончить регистрацию" << std::endl;
		std::cout << "Выберите транспорт или 0 для окончания процесса регистрации: "; std::cin >> a;
		//if (a > 0 || a < 8) ++count;
		Enum_TransportName transport_name = static_cast<Enum_TransportName>(a);
		switch (transport_name) {
			//0std::cout << race.get_type();
		case Enum_TransportName::none: break;
		case Enum_TransportName::tn1: name_transport = check_race(&boots, race); break;
		case Enum_TransportName::tn2: name_transport = check_race(&broom, race); break;
		case Enum_TransportName::tn3: name_transport = check_race(&camel, race); break;
		case Enum_TransportName::tn4: name_transport = check_race(&kentavr, race); break;
		case Enum_TransportName::tn5: name_transport = check_race(&eagle, race); break;
		case Enum_TransportName::tn6: name_transport = check_race(&camelfast, race); break;
		case Enum_TransportName::tn7: name_transport = check_race(&carpet, race); break;
		default: std::cout << "Неправильный номер!" << std::endl;
		}
		std::cout << race.get_name() << ". Расстояние: " << race.get_distance() << std::endl;
		std::cout << "Зарегистрированные транспортные стредства:";
		if (name_transport != "") {
			temp_name = temp_name + name_transport;
			std::cout << temp_name << std::endl;
			temp_name = temp_name + ", ";
			name_transport = "";
			++count;
		}
		else {
			if (temp_name != "") {
				std::string trp = temp_name;
				std::cout << trp.replace(trp.length() - 2, 2, "") << std::endl;
			}
			else std::cout << std::endl;
		}

	} while (a != 0);
} while (true);
//for (const auto& tr_number : tr_arr) {
//	tr_number->get_count();
//}
//for (int i = 0; i < 0; i++) {
//	tr_arr[i]->get_count();
//}

}


std::string check_race(Transport* tr, Race &race) {
	std::cout << std::endl;
if (tr->get_count() != 0) { std::cout << tr->get_name() << " уже зарегистрирован!" << std::endl; }
else {
		if (tr->get_type() == race.get_type()) {
			std::cout << tr->get_name() << " успешно зарегистрирован!" << std::endl;
			tr->set_count();
			return tr->get_name();
		}
		else {
			std::cout << "Попытка зарегистрировать неправильный тип транспортного средства!" << std::endl;
			return "";
		}
	}
	return "";
}


