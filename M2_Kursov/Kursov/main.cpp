#include <iostream>
#include <string>
#include "2_Race.h"
#include "1_Transport.h"	
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



//class Transport {
//protected:
//	std::string name{};
//public:
//	Transport(std::string name) :name(name) {}
//	virtual int get_type() { return 0; }
//	virtual int get_count() { return 0; }
//	virtual const std::string get_name() { return "0"; }
//	virtual void set_count(int cn) {};
//	virtual void set_distance(double dist) {};
//	virtual double comp() { return 0; };
//};

//class T_ground :public Transport {
//protected:
//	int type{};
//public:
//	T_ground(int type, std::string name) : Transport(name), type(type) {}
//	
//};

//class T_fly :public Transport {
//protected:
//	int type;
//public:
//	T_fly(int type, std::string name) :Transport(name), type(type) {}
//};

//class Camel : public T_ground {
//	int count{};
//	double distance{};
//	double speed_move{};
//	double time_move{}, time_out1{}, time_out2{};
//public:
//	Camel(int type, std::string name) : T_ground(type, name) {};
//	const std::string get_name() override { return name; }
//	void set_move(double speed, double tm, double t1, double t2) {
//		speed_move = speed; 
//		time_move = tm;  
//		time_out1 = t1, time_out2 = t2; 
//	}
//	int get_type() override { return type; }
//	int get_count() override { return count; }
//	void set_count(int cn) override { this->count = cn; }
//	void set_distance(double dist) { distance = dist; }
//	double comp() override {
//		double t{}; // общее время
//		double distance_move = speed_move * time_move; // расстояние без отдыха
//		double distance_ostatok_move = abs(distance - distance_move); //оставшееся расстояние после 1го отдыха
//		double distance_parts = distance_ostatok_move / distance_move; // количество оставшихся частей 
//		double distance_ostatok = static_cast<int>(distance_ostatok_move) % static_cast<int>(distance_move); // некратный остаток
//		if (distance >= distance_move) {
//			t = time_move + time_out1 + distance_parts * (time_move + time_out2) + distance_ostatok / speed_move;
//			if (distance_ostatok == 0) t = t - time_out2;
//			return t;
//		}
//		else return distance / speed_move;
//	}
//};
//class Camel_fast:public T_ground {
//	int count{};
//	double distance{};
//	double speed_move{};
//	double time_move{}, time_out1{}, time_out2{}, time_out3{};
//public:
//	Camel_fast(int type, std::string name) : T_ground(type, name) {}
//	void set_move(double speed, double tm, double t1, double t2, double t3) {
//		speed_move = speed;
//		time_move = tm;
//		time_out1 = t1, time_out2 = t2; time_out3 = t3;
//	}
//	const std::string get_name() override { return name; }
//	int get_type() override { return type; }
//	int get_count() override { return count; }
//	void set_count(int cn) override { this->count = cn; }
//	void set_distance(double dist) { distance = dist; }
//	double comp() {
//		double t{}; // общее время
//		double distance_move = speed_move * time_move; // расстояние без отдыха
//		double distance_ostatok_move = abs(distance - 2*distance_move); //оставшееся расстояние после 2х отдыхов
//		double distance_parts = distance_ostatok_move / distance_move; // количество оставшихся частей 
//		double distance_ostatok = static_cast<int>(distance_ostatok_move) % static_cast<int>(distance_move); // некратный остаток
//		if (distance >= 2 * distance_move) {
//			t = 2 * time_move + time_out1 + time_out2 + distance_parts * (time_move + time_out3) + distance_ostatok / speed_move;
//			if (distance_ostatok == 0) t = t - time_out3;
//			return t;
//		}
//		else if (distance >= distance_move) {
//			double distance_ostatok_move = distance - distance_move; //оставшееся расстояние после 1го отдыха
//			t = distance_move + time_out1 + distance_ostatok * time_move;
//			if (distance_ostatok == 0) t = t - time_out2;
//			return t;
//		}
//		else  return distance / speed_move;
//	}
//
//};

//class Boots :public T_ground {
//	int count{};
//	double distance{};
//	double speed_move{};
//	double time_move{}, time_out1{}, time_out2{};
//public:
//	Boots(int type, std::string name) : T_ground(type, name) {}
//	void set_move(double  speed, double  tm, double t1, double t2) {
//		speed_move = speed;
//		time_move = tm;
//		time_out1 = t1, time_out2 = t2;
//	}
//	const std::string get_name() override { return name; }
//	int get_type() override { return type; }
//	int get_count() override { return count; }
//	void set_count(int cn) override { this->count = cn; }
//	void set_distance(double  dist) { distance = dist; }
//	double comp() override {
//		double t{}; // общее время
//		double  distance_move = speed_move * time_move; // расстояние без отдыха
//		double  distance_ostatok_move = abs(distance - distance_move); //оставшееся расстояние после 1го отдыха
//		double  distance_parts = distance_ostatok_move / distance_move; // количество оставшихся частей 
//		double distance_ostatok = static_cast<int>(distance_ostatok_move) % static_cast<int>(distance_move); // некратный остаток
//		if (distance >= distance_move) {
//			t = time_move + time_out1 + distance_parts * (time_move + time_out2) + distance_ostatok / speed_move;
//			if (distance_ostatok == 0) t = t - time_out2;
//			return t;
//		}
//		else return distance / speed_move;
//	}
//};

//class Kentavr :public T_ground {
//	int count{};
//	double distance{};
//	double speed_move{};
//	double time_move{}, time_out1{};
//public:
//	Kentavr(int type, std::string name) : T_ground(type, name) {}
//	void set_move(double speed, double tm, double t1) {
//		speed_move = speed;
//		time_move = tm;
//		time_out1 = t1;
//	}
//	const std::string get_name() override { return name; }
//	int get_type() override { return type; }
//	int get_count() override { return count; }
//	void set_count(int cn) override { this->count = cn; }
//	void set_distance(double dist) { distance = dist; }
//	double comp() override {
//		double t{}; // общее время
//		double distance_move = speed_move * time_move; // расстояние без отдыха
//		double distance_parts = distance / distance_move; // количество частей дистанции
//		double distance_ostatok = static_cast<int>(distance) % static_cast<int>(distance_move); // некратный остаток
//		if (distance >= distance_move) {
//			t = distance_parts * (time_move + time_out1) + distance_ostatok / speed_move;
//			if (distance_ostatok == 0) t = t - time_out1;
//			return t;
//		}
//		else return distance/speed_move;
//	}
//};


//class Eagle : public T_fly {
//	int count{};
//	double distance{};
//	double speed_move{};
//	int k1{};
//public:
//	Eagle(int type, std::string name) : T_fly(type, name) {}
//	void set_move(double speed, int kp1) {
//		speed_move = speed;
//		k1 = kp1;
//	}
//	const std::string get_name() override { return name; }
//	int get_type() override { return type; }
//	int get_count() override { return count; }
//	void set_count(int cn) override { this->count = cn; }
//	void set_distance(double dist) { distance = dist; }
//	double comp() override {
//		k1 = 100 - k1;
//		double t = (distance * k1) / static_cast<double>(speed_move);
//		return t;
//	}
//};

//class Carpet : public T_fly {
//	int count{};
//	double distance{};
//	double speed_move{};
//	int k1{}, k2{}, k3{};
//public:
//	Carpet(int type, std::string name) : T_fly(type, name) {}
//	void set_move(double speed, int kp1, int kp2 , int kp3) {
//		speed_move = speed;
//		k1 = kp1; k2 = kp2; k3 = kp3;
//	}
//	const std::string get_name() override { return name; }
//	int get_type() override { return type; }
//	int get_count() override { return count; }
//	void set_count(int cn) override { this->count = cn; }
//	void set_distance(double dist) { distance = dist; }
//	double comp() override {
//		k1 = 100 - k1; k2 = 100 - k2; k3 = 100 - k3;
//		double t{};
//		if (distance >= 10000) {
//			t = (distance * k3) /  static_cast<double>(speed_move);
//			return t;
//		}
//		else if (distance >= 5000) {
//			t = (distance * k2) / static_cast<double>(speed_move);
//			return t;
//		}
//		else if (distance >= 1000) {
//			t = (distance * k1) /static_cast<double>(speed_move);
//			return t;
//		}
//		else return (static_cast<double>(distance) / static_cast<double>(speed_move));
//	}
//};

//class Broom : public T_fly {
//	int count{};
//	double distance{};
//	double speed_move{};
//public:
//	Broom(int type, std::string name) : T_fly(type, name){}
//	void set_move(int speed) {
//		speed_move = speed;
//	}
//	const std::string get_name() override { return name; }
//	int get_type() override { return type; }
//	int get_count() override { return count; }
//	void set_count(int cn) override { this->count = cn; }
//	void set_distance(double dist) { distance = dist; }
//	double comp() override {
//		int k{};
//		do {
//			k = static_cast<int>(distance);
//			distance /= 10;
//		} while (distance);
//		double t = (distance * k) / static_cast<double>(speed_move);
//		return t;
//	}
//};

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
	std::string temp_name, name_transport;
	RaceName racename; //наименование гонок
//иницилизация характеристик движения
	camel.set_move(10,30,5,8);
	camelfast.set_move(40,10,5,6.5,8);
	kentavr.set_move(15,8,2);
	boots.set_move(6,60,10,5);
	eagle.set_move(8,6);
	carpet.set_move(10,3,10,5);
	broom.set_move(20);
	

	
	double S{};
	int type{}, a{}, d{}; //type-тип гонки, S - расстояние, a - транспорт, d - действие выбора
	std::string Rn{""}; //название гонки
	std::cout << "Добро пожаловать в гоночный симулятор!" << std::endl;
begin:
	//обнуление счетчиков выбора
	int unsigned count{0}; //счетчик транспорных средств
	camel.set_count(0);
	camelfast.set_count(0);
	kentavr.set_count(0);
	boots.set_count(0);
	eagle.set_count(0);
	carpet.set_count(0);
	broom.set_count(0);
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
	Race race(type, S, Rn);//иницилизация гонки
	std::cout << "\nДолжно быть зарегистрировано хотя бы 2 транспортных средства" << std::endl;
do {
		std::cout << "1. Зарегистрировать транспорт" << std::endl;
		if (count >= 2) { 
			std::cout << "2. Начать гонку" << std::endl;  
		}
		std::cout << "Выберите действие: "; std::cin >> d;
		if (d == 2) break;
		if (d == 1) {

			std::cout << "\n" << race.get_name() << ". Расстояние: " << race.get_distance() << std::endl;
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
				case Enum_TransportName::none: std::cout << std::endl; break;
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
		}
} while (true);

Transport* tr_arr[]{ &camel, &camelfast, &kentavr, &boots, &eagle, &carpet, &broom };
double arr[7]{};
double temp{};
Transport* temp_tr{};
int n{1};
int size{7};
std::cout << "\nРезультат гонки:" << std::endl;
for (int i = 0; i < size - 1 ; i++) {
	if (tr_arr[i]->get_count() == 1) {
		tr_arr[i]->set_distance(S); //иницилизация расстояния
		arr[i] = tr_arr[i]->comp();
	}
}
// сортировка массива включая Transport
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


std::string check_race(Transport* tr, Race &race) {
	std::cout << std::endl;
if (tr->get_count() != 0) { std::cout << tr->get_name() << " уже зарегистрирован!" << std::endl; }
else {
		if (tr->get_type() == race.get_type()) {
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


