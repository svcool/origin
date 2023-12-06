#include <iostream>
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
	std::string name;
	Transport(std::string name) :name(name) {}
};

class T_ground :public Transport {
protected:
	int type;
	std::string name;
public:
	T_ground(int type, std::string name) : Transport(name) {
		this->type = type;
		this->name = name;
	}
};
class T_fly :public Transport {
protected:
	int type;
public:
	T_fly(int type, std::string name) :Transport(name) {
		this->type = type;
		this->name = name;
	}
};

class Camel : public T_ground {
public:
	using T_ground::T_ground;
	std::string get_name() { return name; }
	int get_type() { return type; }
};
class Camel_fast:public T_ground {
public:
	using T_ground::T_ground;
	std::string get_name() { return name; }
	int get_type() { return type; }
};

class Boots :public T_ground {
public:
	using T_ground::T_ground;
	std::string get_name() { return name; }
	int get_type() { return type; }
};

class Kentavr :public T_ground {
public:
	using T_ground::T_ground;
	std::string get_name() { return name; }
	int get_type() { return type; }
};


class Eagle : public T_fly {
public:
	using T_fly::T_fly;
	std::string get_name() { return name; }
	int get_type() { return type; }
};

class Carpet : public T_fly {
public:
	using T_fly::T_fly;
	std::string get_name() { return name; }
	int get_type() { return type; }
};

class Broom : public T_fly {
public:
	using T_fly::T_fly;
	std::string get_name() { return name; }
	int get_type() { return type; }
};

void check_race(std::string t_name, int t_type, int r_type);

int main() {
	setlocale(LC_ALL, "Russian");
	system("chcp 1251");
	T_ground t_ground(1, "Наземный транспорт");
	T_fly t_fly(2, "Воздушный транспорт");
	Camel camel(1,"Верблюд");
	Camel_fast camelfast(1, "Верблюд");
	Kentavr	kentavr(1, "Кентавр");
	Boots boots(1, "Ботинки-вездеходы");
	Eagle eagle(2, "Орёл");
	Carpet carpet(2, "Ковер-самолет");
	Broom broom(2, "Метла");


	RaceName racename; //наименование гонок
	int count{}; //счетчик транспорных средств
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
		do {
			std::cout << "1. Зарегистрировать транспорт" << std::endl;
			if (count > 2) { std::cout << "2. Начать гонку" << std::endl; }
			std::cout << "Выберите действие: "; std::cin >> d;
		} while (d != 1);
		std::cout << race.get_name() << ". Расстояние: " << race.get_distance() << std::endl;
		std::cout << "1. " << boots.get_name() << std::endl;
		std::cout << "2. " << broom.get_name() << std::endl;
		std::cout << "3. " << camel.get_name() << std::endl;
		std::cout << "4. " << kentavr.get_name() << std::endl;
		std::cout << "5. " << eagle.get_name() << std::endl;
		std::cout << "6. " << camelfast.get_name() << std::endl;
		std::cout << "7. " << carpet.get_name() << std::endl;
		std::cout << "0. Закончить регистрацию" << std::endl;
		std::cout << "Выберите транспорт или 0 для окончания процесса регистрации: "; std::cin >> a;
		Enum_TransportName transport_name = static_cast<Enum_TransportName>(type);
		switch (transport_name) {
			std::cout << race.get_type();
		case Enum_TransportName::none: break;
		case Enum_TransportName::tn1: check_race(boots.get_name(), boots.get_type(), race.get_type()); break;
		case Enum_TransportName::tn2: check_race(broom.get_name(), broom.get_type(), race.get_type()); break;
		case Enum_TransportName::tn3: check_race(camel.get_name(), camel.get_type(), race.get_type()); break;
		case Enum_TransportName::tn4: check_race(kentavr.get_name(), kentavr.get_type(), race.get_type()); break;
		case Enum_TransportName::tn5: check_race(eagle.get_name(), eagle.get_type(), race.get_type()); break;
		case Enum_TransportName::tn6: check_race(camelfast.get_name(), camelfast.get_type(), race.get_type()); break;
		case Enum_TransportName::tn7: check_race(carpet.get_name(), carpet.get_type(), race.get_type()); break;
		default: std::cout << "Неправильный номер!" << std::endl;
		}
	} while (true);

}
	void check_race(std::string t_name, int t_type, int r_type) {
		if (r_type == t_type) {
			
			std::cout << t_name << " успешно зарегистрирован!" << std::endl;
		}
		else {
			std::cout << "Попытка зарегистрировать неправильный тип транспортного средства!" << std::endl;
		}
	}
