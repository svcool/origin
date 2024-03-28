﻿#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <typeinfo>

class parser_error : public std::exception{
	std::string message;
public:
	parser_error(const std::string& message) : message{ message }
	{}
	const char* what() const noexcept override {
		return message.c_str();
	}
};

class parser_error_sintax : public std::exception{
	std::string message;
public:
	parser_error_sintax(const std::string& message, int count) {
		this->message = message + " - line " + std::to_string(count);
	}
	const char* what() const noexcept override{
		return message.c_str();
	}
};


//#############################################################################################
class ini_parser {
	std::string file_name{};
	std::ifstream file{};
	std::string V;
	std::string S;
	//std::map<std::string, std::string> data_value;
	std::map<std::string, std::map <std::string, std::string> > data;

void open_file() {
		file.open(file_name);
		if (!file.is_open()) {
			throw parser_error("File not found");
		}
	}

	void section_value(std::string sec_val) {
		if (sec_val.empty()) {
			throw parser_error("Data empty");
		}
<<<<<<< HEAD
		S = sec_val.substr(0, sec_val.find(".")); //секция
		V = sec_val.substr(sec_val.find(".") + 1);//параметр
	}
//проверка символов между значением и =
=======
		S = sec_val.substr(0, sec_val.find(".")); //������
		V = sec_val.substr(sec_val.find(".") + 1);//��������
	}
//�������� �������� ����� ��������� � =
>>>>>>> b86d4b2 (final)
	bool error(size_t val_end, size_t next_word, std::string& line) {

		for (size_t i = val_end; i < next_word; i++) {
			if (line[i] != ' ') return true;
		}
		return false; // правильный синтаксис между = и value
	}

<<<<<<< HEAD
	// проверка числа
=======
	// �������� �����
>>>>>>> b86d4b2 (final)
	bool is_number(const std::string& line) {
		if (!line.empty() && (line.find_first_not_of("0123456789.") == std::string::npos)) {
			return true;
		}
		return false;
	}

	void find_file() {
<<<<<<< HEAD
		std::string line, d_val, val; // иследуемая строка
		size_t section_start{}, section_end{}, section_find{};// начало и конец секции
		size_t val_start{}, val_end{}; //начало и конец value
		std::string section_temp; //временая секция для записи в map
		size_t comment{}; //комментарии
		size_t space{}; // пробел
=======
		std::string line, d_val, val; // ���������� ������
		size_t section_start{}, section_end{}, section_find{};// ������ � ����� ������
		size_t val_start{}, val_end{}; //������ � ����� value
		std::string section_temp; //�������� ������ ��� ������ � map
		size_t comment{}; //�����������
		size_t space{}; // ������
>>>>>>> b86d4b2 (final)
		std::string result{};
		const std::string separators{ " ,;:.\"!?'*\n\t" }; // разделители слов
		unsigned count{}; //счетчик строк
		bool find_section{ false };
		while (std::getline(file, line))
		{
<<<<<<< HEAD
			count++;//счетчик строк
			size_t word = line.find_first_not_of(separators);// идекс слова
			comment = line.find_first_of(';'); //поиск индекса начала комментария
			if (comment != std::string::npos) line.erase(comment);//удаляем комментарии после ;
			if (line.empty() || word == std::string::npos) continue;//если строка пустая или нет слов
			section_start = line.find('[');
			section_end = line.find(']');
			//поиск секции

			if (section_start != std::string::npos && section_end != std::string::npos) {
				find_section = false; // найдена секция, проверяем на соответствие
				section_find = line.find(S);// индекс начала искомой секции

				if (section_end > section_start) {
					//проверка отсутвия символов кроме пробела и табуляции до и после скобок
=======
			count++;//������� �����
			size_t word = line.find_first_not_of(separators);// ����� �����
			comment = line.find_first_of(';'); //����� ������� ������ �����������
			if (comment != std::string::npos) line.erase(comment);//������� ����������� ����� ;
			if (line.empty() || word == std::string::npos) continue;//���� ������ ������ ��� ��� ����
			section_start = line.find('[');
			section_end = line.find(']');
			//����� ������

			if (section_start != std::string::npos && section_end != std::string::npos) {
				find_section = false; // ������� ������, ��������� �� ������������
				section_find = line.find(S);// ������ ������ ������� ������

				if (section_end > section_start) {
					//�������� �������� �������� ����� ������� � ��������� �� � ����� ������
>>>>>>> b86d4b2 (final)
					if (line.find_first_not_of(" \t\n", section_end + 1) != std::string::npos) {
						throw parser_error_sintax("Incorrect syntax in the file", count);
					}

					for (size_t i = 0; i < section_start; i++) {
						if (line[i] == ' ' || line[i] == '\t') continue;
						throw parser_error_sintax("Incorrect syntax in the file", count);
					}

<<<<<<< HEAD
					//проверка целостнотсти названия секции без пробелов и табуляций на краях названия
					if(section_start == section_end -1 ) throw parser_error_sintax("Incorrect syntax in the file", count); //проверка, что секция не пустая [];
=======
					//�������� ������������ �������� ������ ��� �������� � ��������� �� ����� ��������
					if(section_start == section_end -1 ) throw parser_error_sintax("Incorrect syntax in the file", count); //��������, ��� ������ �� ������ [];
>>>>>>> b86d4b2 (final)
					for (size_t i = section_end - 1; i > section_start; i--) {
						if (line[i] == ' ' || line[i] == '\t') throw parser_error_sintax("Incorrect syntax in the file", count);
						if (line[i] != ' ' || line[i] != '\t') break;
					}

					for (size_t i = section_start + 1; i < section_end; i++) {
						if (line[i] == ' ' || line[i] == '\t') throw parser_error_sintax("Incorrect syntax in the file", count);
						if (line[i] != ' ' || line[i] != '\t') break;
						
					}

				}
				
<<<<<<< HEAD
				find_section = true; //найдена секция
				section_temp = line.substr(section_start + 1, section_end - section_start - 1);
				data[section_temp];//запись секции
=======
				find_section = true; //������� ������
				section_temp = line.substr(section_start + 1, section_end - section_start - 1);
				data[section_temp];//������ ������
>>>>>>> b86d4b2 (final)
				continue;
			}

			//Разбор переменных секции
			if (find_section) {
<<<<<<< HEAD
				size_t start_word = line.find_first_not_of(separators);//начала значения value
				size_t end_word = line.find_first_of(" =", start_word + 1); // находим, где кончается слово
				val_start = line.find(V);
				space = line.find_first_of('=');
				//нет в строке знака =
				if (line.find_first_of("=", start_word + 1) == std::string::npos) {
					throw parser_error_sintax("Incorrect syntax in the file", count);
				}
				//проверка отсуствия знаков кроме пробела до знака "="
				if (error(end_word, space, line)) {
					throw parser_error_sintax("Incorrect syntax in the file", count);
				}
				d_val = line.substr(start_word, end_word); // подстрока с именем параметра

				//обработка подстроки после =
				start_word = line.find_first_not_of(separators, space + 1); //начало значения после =
				end_word = line.size() - 1; //конец значения
				//проверка отсуствия знаков до значения кроме пробела 
=======
				size_t start_word = line.find_first_not_of(separators);//������ �������� value
				size_t end_word = line.find_first_of(" =", start_word + 1); // �������, ��� ��������� �����
				val_start = line.find(V);
				space = line.find_first_of('=');
				//��� � ������ ����� =
				if (line.find_first_of("=", start_word + 1) == std::string::npos) {
					throw parser_error_sintax("Incorrect syntax in the file", count);
				}
				//�������� ��������� ������ ����� ������� �� ����� "="
				if (error(end_word, space, line)) {
					throw parser_error_sintax("Incorrect syntax in the file", count);
				}
				d_val = line.substr(start_word, end_word); // ��������� � ������ ���������

				//��������� ��������� ����� =
				start_word = line.find_first_not_of(separators, space + 1); //������ �������� ����� =
				end_word = line.size() - 1; //����� ��������
				//�������� ��������� ������ �� �������� ����� ������� 
>>>>>>> b86d4b2 (final)
				if (error(space + 1, start_word, line) && start_word != std::string::npos) {
					throw parser_error_sintax("Incorrect syntax in the file", count);
				}
				//удаление лишних пробелов в конце строки
				while (true) {
					if (line[end_word] != ' ') {
						break;
					}
					end_word--;
				}
<<<<<<< HEAD
				//если нет значения записать "", иначе значение
=======
				//���� ��� �������� �������� "", ����� ��������
>>>>>>> b86d4b2 (final)
				if (start_word == std::string::npos) {
					val = "";
				}
				else {
					val = line.substr(start_word, end_word - start_word + 1); // значение переменной
				}
	
				data[section_temp][d_val] = val;
			}

		}
		file.close();
	}

<<<<<<< HEAD
	// контроль данных, вывод существующих секций и параметров, если не не надены
	void control_data() {
		std::map<std::string, std::string>::iterator itr1;
		std::map<std::string, std::map<std::string, std::string> >::iterator itr;
		// проверка секции и вывод существующи секций в файле

		itr = data.find(S);
		if (itr == data.end()) {
			std::cout << "Секция [" << S << "] не найдена. \nФайл содержит следующие секции: \n";
=======
	// �������� ������, ����� ������������ ������ � ����������, ���� �� �� ������
	void control_data() {
		std::map<std::string, std::string>::iterator itr1;
		std::map<std::string, std::map<std::string, std::string> >::iterator itr;
		// �������� ������ � ����� ����������� ������ � �����
	
		itr = data.find(S);
		if (itr == data.end()) {
			std::cout << "������ [" << S << "] �� �������. \n���� �������� ��������� ������: \n";
>>>>>>> b86d4b2 (final)
			for (itr = data.begin(); itr != data.end(); itr++)
			{
				std::cout << itr->first << "\n";
			}
			throw parser_error("The section is not found");
		}
<<<<<<< HEAD
		// проверка параметра и вывод существующих параметров в секции
		itr1 = itr->second.find(V);
		if (itr1 == itr->second.end()) {
			std::cout << "Переменная \"" << V << "\" не найдена. \nСекция [" << S << "] содержит следующие переменные: \n";
		for (auto it = data[S].cbegin(); it != data[S].cend(); ++it){
			std::cout << it->first << std::endl;
		}
			/*for (const auto& element : data[S]) {
				std::cout << element.first << std::endl;
			}
			throw parser_error("The parameter is not found");*/
		}
	

		//если у параметра нет значения
			if (data.at(S).at(V) == "") {
				std::cout << "Нет значения для параметра \"" << V << "\" в секции [" << S << "].\n";
				throw parser_error("No meaning for the variable");
			}
		}
		

	std::string get_value_string(std::string sec_val) {
	section_value(sec_val);
	control_data(); // контроль данных, вывод существующих секций и параметров, если не не надены
=======
		// �������� ��������� � ����� ������������ ���������� � ������
		itr1 = itr->second.find(V);
		if (itr1 == itr->second.end()) {
			std::cout << "���������� \"" << V << "\" �� �������. \n������ [" << S << "] �������� ��������� ����������: \n";

			for (const auto& element : data[S]) {
				std::cout << element.first << std::endl;
			}
			throw parser_error("The parameter is not found");
		}
	//���� � ��������� ��� ��������
		if (data.at(S).at(V) == "") {
			std::cout << "��� �������� ��� ��������� \"" << V << "\" � ������ [" << S << "].\n";
			throw parser_error("No meaning for the variable");
		}
	}
		
	std::string get_value_string(std::string sec_val) {
	section_value(sec_val);
	control_data(); // �������� ������, ����� ������������ ������ � ����������, ���� �� �� ������
>>>>>>> b86d4b2 (final)
		return data.at(S).at(V);
	}

public:
	ini_parser(std::string file_name) : file_name(file_name) {
		open_file();
		find_file();
	}
	template<typename T>
	T get_value(std::string sec_val) {
		
		static_assert(sizeof(T) == -1, "not implemented type for get_value");
	}
			
<<<<<<< HEAD
	//2. конкретный шаблон для стринга
=======
	//2. ���������� ������ ��� �������
>>>>>>> b86d4b2 (final)
	template<>
	std::string get_value(std::string sec_val) {
		return get_value_string(sec_val);
	}
<<<<<<< HEAD
	//3. конкретный шаблон для инта
=======
	//3. ���������� ������ ��� ����
>>>>>>> b86d4b2 (final)
	template<>
	int get_value(std::string sec_val) {
		std::string str_val = get_value_string(sec_val);
		if (!is_number(str_val)) {
			throw parser_error("Incorrect type of data requested");
		}
		return atoi(str_val.c_str());
	}

<<<<<<< HEAD
	//3. конкретный шаблон для double
	template<>
	double get_value(std::string sec_val) {
		std::string str_val = get_value_string(sec_val);
		if (!is_number(str_val)) {
			throw parser_error("Incorrect type of data requested");
		}
		if (str_val.find('.') != std::string::npos) {
			str_val = str_val.replace(str_val.find("."), 1, ",");
		}
		return atof(str_val.c_str());
	}


=======
>>>>>>> b86d4b2 (final)
	~ini_parser() {
		file.close();
	}
};



int main() {
	setlocale(LC_ALL, "Russian");
	std::string file = "txt.ini";
<<<<<<< HEAD
	std::string parametr = "Section1.var1"; 
	try {
		ini_parser parser(file);
		auto value = parser.get_value<double>(parametr);
		std::cout << "Найденый параметр: " << parametr << " = " << value;
=======
	std::string parametr = "Section4.Mode"; 
	try {
		ini_parser parser(file);
		auto value = parser.get_value<std::string>(parametr);
		std::cout << "�������� ��������: " << parametr << " = " << value;
>>>>>>> b86d4b2 (final)
	}
	catch (const parser_error& err) {
		std::cout << "Parser error: " << err.what() << std::endl;
	}
	catch (const parser_error_sintax& err) {
		std::cout << "Parser error: " << err.what() << std::endl;
	}
	// обработка остальных исключений
	catch (const std::exception&)
	{
		std::cout << "Something wrong" << std::endl;
	}
	return 0;
}