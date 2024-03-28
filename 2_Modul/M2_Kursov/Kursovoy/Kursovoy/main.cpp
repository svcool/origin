#include <iostream>
#include <string>
#include "2_Race.h"
#include "2_RaceFly.h"
#include "2_RaceGround.h"
#include "2_RaceGroundFly.h"
#include "1_TrFly.h"
#include "1_TrGround.h"
#include "1_Boots.h"
#include "1_Broom.h"
#include "1_Camel.h"
#include "1_CamelFast.h"
#include "1_Eagle.h"
#include "1_Kentavr.h"
#include "1_Carpet.h"	
#include "check_race.h"

enum class Enum_TransportName {	none, tn1, tn2,	tn3, tn4, tn5, tn6,	tn7,}; 
enum class Enum_RaceName { none, race1, race2, race3,};

int main() {
	setlocale(LC_ALL, "Russian");
	system("chcp 1251");
	//иницилизация транспорта
	T_ground t_ground(1, "Наземный транспорт");
	T_fly t_fly(2, "Воздушный транспорт");
	Camel camel(1,"Верблюд");
	Camel_fast camelfast(1, "Верблюд-быстроход");
	Kentavr	kentavr(1, "Кентавр");
	Boots boots(1, "Ботинки-вездеходы");
	Eagle eagle(2, "Орёл");
	Carpet carpet(2, "Ковер-самолет");
	Broom broom(2, "Метла");
	
//иницилизация характеристик движения
	camel.set_move(10,30,5,8);
	camelfast.set_move(40,10,5,6.5,8);
	kentavr.set_move(15,8,2);
	boots.set_move(6,60,10,5);
	eagle.set_move(8,6);
	carpet.set_move(10,3,10,5);
	broom.set_move(20);
//иницилизация типов гонок
	Race_fly racefly("Гонка для наземного транспорта", 1);
	Race_ground raceground("Гонка для воздушного транспорта", 2);
	Race_groundfly racegroundfly("Гонка для наземного и воздушного транспорта", 3);
	//массив указателей на объекты
	Transport* tr_arr[]{ &camel, &camelfast, &kentavr, &boots, &eagle, &carpet, &broom };
	Race race(0);
	Race* race_arr[]{ &racefly, &raceground, &racegroundfly };
	double S{};
	int type{}, a{}, d{}; //type-тип гонки, S - расстояние, a - транспорт, d - действие выбора
	const int size{7}; // количество транспорта
	std::string Rn{""}; //название гонки
begin:	
	std::string temp_name{}, name_transport{};
	std::cout << "Добро пожаловать в гоночный симулятор!" << std::endl;
	//обнуление счетчиков выбора
	int unsigned count{0}; //счетчик транспорных средств
	for (int i = 0; i < size; ++i) {
		tr_arr[i]->set_count(0);
	}
	do {
		std::cout << race_arr[0]->get_type() << " " << race_arr[0]->get_name() << std::endl;
		std::cout << race_arr[1]->get_type() << " " << race_arr[1]->get_name() << std::endl;
		std::cout << race_arr[2]->get_type() << " " << race_arr[2]->get_name() << std::endl;
		std::cout << "0. Выход" << std::endl;
		std::cout << "Выберите тип гонок: "; std::cin >> type;
		Enum_RaceName race_name = static_cast<Enum_RaceName>(type);
		switch (race_name) {
		case Enum_RaceName::none: std::cout << "До свидания" << std::endl; return 0;
		case Enum_RaceName::race1: Rn = race_arr[0]->get_name(); break;
		case Enum_RaceName::race2: Rn = race_arr[1]->get_name(); break;
		case Enum_RaceName::race3: Rn = race_arr[2]->get_name(); break;
		default: std::cout << "Неправильный номер!" << std::endl;
		}
	} while (type == 0 || Rn == "");
	std::cout << "Укажите длину дистанции (должна быть положительной): "; std::cin >> S;
	race.set_distance(S);
	//иницилизация характеристик гонки
	std::cout << "\nДолжно быть зарегистрировано хотя бы 2 транспортных средства" << std::endl;
do {
		std::cout << "1. Зарегистрировать транспорт" << std::endl;
		if (count >= 2) { 
			std::cout << "2. Начать гонку" << std::endl;  
		}
		std::cout << "Выберите действие: "; std::cin >> d;
		if (d == 2) break;
		if (d == 1) {

			std::cout << "\n" << race_arr[type - 1]->get_name() << ". Расстояние: " << S << std::endl;
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
				case Enum_TransportName::none: std::cout << std::endl; break;
				case Enum_TransportName::tn1: name_transport = check_race(&boots, race_arr[type-1]); break;
				case Enum_TransportName::tn2: name_transport = check_race(&broom, race_arr[type-1]); break;
				case Enum_TransportName::tn3: name_transport = check_race(&camel, race_arr[type-1]); break;
				case Enum_TransportName::tn4: name_transport = check_race(&kentavr, race_arr[type-1]); break;
				case Enum_TransportName::tn5: name_transport = check_race(&eagle, race_arr[type-1]); break;
				case Enum_TransportName::tn6: name_transport = check_race(&camelfast, race_arr[type-1]); break;
				case Enum_TransportName::tn7: name_transport = check_race(&carpet, race_arr[type-1]); break;
				default: std::cout << "Неправильный номер!" << std::endl;
				}
				std::cout << race_arr[type - 1]->get_name() << ". Расстояние: " << S << std::endl;
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
		}
} while (true);

double arr[size]{};
double temp{};
Transport* temp_tr{};
int n{1};
std::cout << "\nРезультат гонки:" << std::endl;
for (int i = 0; i < size; i++) {
	if (tr_arr[i]->get_count() == 1) {
		tr_arr[i]->set_distance(S); //иницилизация расстояния
		arr[i] = tr_arr[i]->comp();
	}
}
// сортировка массива включая Transport*
for (int i = 0; i < size - 1; ++i) {
	for (int j = 0; j < size - 1 - i; ++j) {
		if (arr[j] > arr[j + 1]) {
			temp = arr[j]; temp_tr = tr_arr[j];
			arr[j] = arr[j + 1]; tr_arr[j] = tr_arr[j + 1];
			arr[j + 1] = temp; tr_arr[j + 1] = temp_tr;
		}
	}
}

//вывод отсортированного результата
for (int i = 0; i < size; ++i) {
	if (arr[i] != 0) {
		std::cout << n << ". " << tr_arr[i]->get_name() << ". Время: " << tr_arr[i]->comp() << std::endl;
		n++;
	}
}
do {
	std::cout << "\n" << "1. Провести ещё одну гонку" << "\n";
	std::cout << "2. Выйти" << "\n";
	std::cout << "Выберите действие: "; std::cin >> d;
	if (d == 2) { std::cout << "Досвидания";  break; }
	if (d == 1) { std::cout << "\n"; goto begin; }
} while (true);

return 0;
}