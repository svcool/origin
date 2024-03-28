#include <iostream>
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
		S = sec_val.substr(0, sec_val.find(".")); //������
		V = sec_val.substr(sec_val.find(".") + 1);//��������
	}
//�������� �������� ����� ��������� � =
	bool error(size_t val_end, size_t next_word, std::string& line) {

		for (size_t i = val_end; i < next_word; i++) {
			if (line[i] != ' ') return true;
		}
		return false; // ���������� ��������� ����� = � value
	}

	// �������� �����
	bool is_number(const std::string& line) {
		if (!line.empty() && (line.find_first_not_of("0123456789.") == std::string::npos)) {
			return true;
		}
		return false;
	}

	void find_file() {
		std::string line, d_val, val; // ���������� ������
		size_t section_start{}, section_end{}, section_find{};// ������ � ����� ������
		size_t val_start{}, val_end{}; //������ � ����� value
		std::string section_temp; //�������� ������ ��� ������ � map
		size_t comment{}; //�����������
		size_t space{}; // ������
		std::string result{};
		const std::string separators{ " ,;:.\"!?'*\n\t" }; // ����������� ����
		unsigned count{}; //������� �����
		bool find_section{ false };
		while (std::getline(file, line))
		{
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
					if (line.find_first_not_of(" \t\n", section_end + 1) != std::string::npos) {
						throw parser_error_sintax("Incorrect syntax in the file", count);
					}

					for (size_t i = 0; i < section_start; i++) {
						if (line[i] == ' ' || line[i] == '\t') continue;
						throw parser_error_sintax("Incorrect syntax in the file", count);
					}

					//�������� ������������ �������� ������ ��� �������� � ��������� �� ����� ��������
					if(section_start == section_end -1 ) throw parser_error_sintax("Incorrect syntax in the file", count); //��������, ��� ������ �� ������ [];
					for (size_t i = section_end - 1; i > section_start; i--) {
						if (line[i] == ' ' || line[i] == '\t') throw parser_error_sintax("Incorrect syntax in the file", count);
						if (line[i] != ' ' || line[i] != '\t') break;
					}

					for (size_t i = section_start + 1; i < section_end; i++) {
						if (line[i] == ' ' || line[i] == '\t') throw parser_error_sintax("Incorrect syntax in the file", count);
						if (line[i] != ' ' || line[i] != '\t') break;
						
					}

				}
				
				find_section = true; //������� ������
				section_temp = line.substr(section_start + 1, section_end - section_start - 1);
				data[section_temp];//������ ������
				continue;
			}

			//������ ���������� ������
			if (find_section) {
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
				if (error(space + 1, start_word, line) && start_word != std::string::npos) {
					throw parser_error_sintax("Incorrect syntax in the file", count);
				}
				//�������� ������ �������� � ����� ������
				while (true) {
					if (line[end_word] != ' ') {
						break;
					}
					end_word--;
				}
				//���� ��� �������� �������� "", ����� ��������
				if (start_word == std::string::npos) {
					val = "";
				}
				else {
					val = line.substr(start_word, end_word - start_word + 1); // �������� ����������
				}
	
				data[section_temp][d_val] = val;
			}

		}
		file.close();
	}

	// �������� ������, ����� ������������ ������ � ����������, ���� �� �� ������
	void control_data() {
		std::map<std::string, std::string>::iterator itr1;
		std::map<std::string, std::map<std::string, std::string> >::iterator itr;
		// �������� ������ � ����� ����������� ������ � �����
		itr = data.find(S);
		if (itr == data.end()) {
			std::cout << "������ [" << S << "] �� �������. \n���� �������� ��������� ������: \n";
			for (itr = data.begin(); itr != data.end(); itr++)
			{
				std::cout << itr->first << "\n";
			}
			throw parser_error("The section is not found");
		}
		// �������� ��������� � ����� ������������ ���������� � ������
		itr1 = itr->second.find(V);
		if (itr1 == itr->second.end()) {
			std::cout << "���������� \"" << V << "\" �� �������. \n������ [" << S << "] �������� ��������� ����������: \n";

			for (const auto& element : data[S]) {
				std::cout << element.first << std::endl;
			}
			throw parser_error("The parameter is not found");
		}
	
	}



public:
	ini_parser(std::string file_name) : file_name(file_name) {
		open_file();
		find_file();
	}




	//#######################################################################
	template<typename T>
	T get_value1(std::string sec_val) {
		
		static_assert(sizeof(T) == -1, "not implemented type for get_value");
	}
	std::string get_value_string(std::string sec_val) {
	section_value(sec_val);
	control_data(); // �������� ������, ����� ������������ ������ � ����������, ���� �� �� ������
		return data.at(S).at(V);
	}
	
	//2. ���������� ������ ��� �������
	template<>
	std::string get_value1(std::string sec_val) {
		return get_value_string(sec_val);
	}
	//3. ���������� ������ ��� ����
	template<>
	int get_value1(std::string sec_val) {
		std::string str_val = get_value_string(sec_val);
		if (!is_number(str_val)) {
			throw parser_error("Incorrect type of data requested");
		}
		return atoi(str_val.c_str());
	}


	//################################################3
	template <class T>
	T get_value(std::string sec_val) {
		section_value(sec_val);
		T result{};
		std::string value{};
				
		control_data();
			/*for (std::map<std::string, std::map<std::string, std::string> >::const_iterator ptr = data.begin(); ptr != data.end(); ptr++) {
				std::cout << ptr->first << "\n";
				for (std::map<std::string, std::string>::const_iterator eptr = ptr->second.begin(); eptr != ptr->second.end(); eptr++) {
					std::cout << eptr->first << std::endl;
				}
			}

				for (itr2 = data.begin(); itr2 != data.end(); itr2++) {
					std::cout << itr2->first;
					for (itr1 = data_value.begin(); itr1 != data_value.end(); itr1++)
					{
						std::cout << itr1->first << " = " << itr1->second << "\n";
					}
				}*/

		value = data.at(S).at(V);
		if constexpr (std::is_same_v<T, int>) {
			if (!is_number(value)) {
				throw parser_error("Incorrect type of data requested");
			}
			return T{ atoi(value.c_str()) };
		}
		else if constexpr (std::is_same_v<T, double>) {
			if (value.find('.') != std::string::npos) {
				value = value.replace(value.find("."), 1, ",");
			}
			return T{ atof(value.c_str()) };
		}
		else if constexpr (std::is_same_v<T, std::string>) {
			return T{ value };
		}
		else throw parser_error("Incorrect type of data requested");
	}

	
	~ini_parser() {
		file.close();
	}
};



int main() {
	setlocale(LC_ALL, "Russian");
	std::string file = "txt.ini";
	std::string parametr = "Section1.var6"; 
	try {
		ini_parser parser(file);
		auto value = parser.get_value1<int>(parametr);
		std::cout << "�������� ��������: " << parametr << " = " << value;
	}
	catch (const parser_error& err) {
		std::cout << "Parser error: " << err.what() << std::endl;
	}
	catch (const parser_error_sintax& err) {
		std::cout << "Parser error: " << err.what() << std::endl;
	}
	// ��������� ��������� ����������
	catch (const std::exception&)
	{
		std::cout << "Something wrong" << std::endl;
	}
	return 0;
}