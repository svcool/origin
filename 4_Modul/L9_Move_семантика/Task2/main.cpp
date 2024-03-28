#include <iostream>
#include <vector>
#include <string>

class big_integer {
public:
	std::string num;
	long num_size = static_cast<long>(num.size());
public:
	big_integer(std::string num) : num(num) {}

	//оператор сложения объектов
	big_integer operator+ (const big_integer& other) const {
		return sum(other);
	}
	//оператор умножения объектов
	big_integer operator* (const big_integer& other) const {
		return mult(other);
	}

	//оператора сложения с числом
	std::string operator+ (const int& num_other) {
		big_integer number_other(std::to_string(num_other));
		big_integer result = *this + number_other;
		return result.num;
	}

	//оператора умножения с числом
	std::string operator* (const int& num_other) {
		big_integer number_other(std::to_string(num_other));
		big_integer result = *this * number_other;
		return result.num;
	}

	////конструктор копирования S1(S2)
	//big_integer(const big_integer& other)
	//	: big_integer(other.num) {}

	////конструктор копирующего присваивания
	//big_integer& operator=(const big_integer& other) {
	//	return *this = big_integer(other);
	//}
	 
	//- конструктор перемещения  S1(S2);
	big_integer(big_integer&& other) noexcept
		: num(std::exchange(other.num, 0)) {}

	//-перемещающий оператор присваивания;
	big_integer& operator=(big_integer&& other) noexcept {
		std::swap(num, other.num);
		return *this;
	}
	 
	//оператор <<
	friend std::ostream& operator<<(std::ostream& stream, const big_integer& other)
	{
		stream << other.num;
		return stream;
	}
	
	// сложение больших чисел
	big_integer sum(const big_integer& num_other) const{
		std::string a = num;
		int a_size = num_size;
		std::string b = num_other.num;
		int b_size = num_other.num_size;
		//разница между длинами чисел
		int length = abs(a_size - b_size);
		//реверс строк
		reverse(a.begin(), a.end());
		reverse(b.begin(), b.end());
		//приравниваем длину строк добавлением нуля
		for (int i = 0; i < length; i++) {
			if (a_size > b_size) b.push_back('0');
			else a.push_back('0');
		}
		//добавочный 0 для работы цикла на следующий десяток
		if (a.size() == b.size()) {
			b.push_back('0');
			a.push_back('0');
		}
		//результирующая строк + 1 для перхода на следующий десяток
		std::string result(a.size()+1, 0);
		//сложение строк
		for (int i= 0; i < a.size(); i++) {
			result[i] += b[i] + a[i] - 2*'0';
			result[i+1] += (result[i] / 10);
			result[i] %= 10;
			result[i] += '0';
		}

		while(result[result.size() - 1] == 0 || result[result.size() - 1] == '0') {
			result.pop_back();
		}
		reverse(result.begin(), result.end()); 
		return result;
	}

	big_integer mult(const big_integer& num_other) const{
		std::string a = num;
		int a_size = num_size;
		std::string b = num_other.num;
		int b_size = num_other.num_size;

		//максимальная длина итогового числа
		int length = a.size() + b.size() + 1;
		//меняем местами
		if (a.size() < b.size()) { 
			swap(a, b); 
		}

		//разница между длинами чисел
		int l = abs(a_size - b_size);
		
		//реверс строк
		reverse(a.begin(), a.end());
		reverse(b.begin(), b.end());

		//приравниваем длину строк добавлением нуля
		for (int i = 0; i < l; i++) {
			if (a.size() > b.size()) b.push_back('0');
			else a.push_back('0');
		}

		//добавочный 0 для работы цикла на следующий десяток
		if (a.size() == b.size()) {
			b.push_back('0');
			a.push_back('0');
		}
		bool all_next_null = false;
		std::vector<std::string> vec{};
		//чтобы не делать лишние умножения на нуль
		for (int i = 0; i < b.size(); i++) {
					for (int k = i; k < b.size(); k++) {
				all_next_null = true;
				if (b[k] != '0') {
					all_next_null = false;
					break;
				}
			}
			if (all_next_null) break;
			std::string result(b.size(), '0');//обнуляем

			for (int j = 0; j < a.size(); j++) {
				result[j] += (a[j] - '0') * (b[i] - '0') - '0';
				result[j + 1] += (result[j] / 10) - '0';
				result[j] %= 10;
				result[j] += '0';
				result[j + 1] += '0';
			}
		//добавочный 0 для следующего десятка при дальнейшем сложении
			result.push_back('0');
			vec.push_back(result);
		}
		
		//итоговый массив + vec.size для учета смещения(не обязательно, если удаляются в предыдущем цикле нулевые result)
		std::string result(length + vec.size(), '0');

		for (int i = 0; i < vec.size(); i++) {
			for (int j = 0; j < vec[i].size()-1; j++) {
			result[j + i] = result[j + i] + vec[i].at(j) -2*'0';
			result[j + i + 1] = result[j + i + 1] + result[j + i] / 10;
			result[j + i] = result[j + i] % 10;
			result[j + i] += '0';
			}
			vec[i] = result;
		}
		while (result[result.size() - 1] == '0') {
			result.pop_back();
		}
		reverse(result.begin(), result.end());
		return result;
	}

	//деструктор
	~big_integer() {

	}
};

int main() {
	auto number1 = big_integer("7");
	auto number2 = big_integer("23422");
	auto number3 = big_integer("1111");
	int num = 5;
	
	auto result1 = number1 + number2;
	std::string result2 = number1 + num;
	std::cout << "\nSum of numbers:" << number1.num << " + " << number2.num << " = " << result1;
	std::cout << "\nSum of numbers:" << number1.num << " + " << num << " = " << result2;

	auto result3 = number1 * number2;
	auto result4 = number1 * num;
	std::cout << "\nMult of numbers:" << number1.num << " * " << number2.num << " = " << result3;
	std::cout << "\nMult of numbers:" << number1.num << " * " << num << " = " << result4;

	//-перемещающий оператор присваивания;
	number3 = big_integer{ "3333333" };
	std::cout << "\n" << number3.num;

	//перемещение
	number1 = std::move(number3) ;
	std::cout << "\n" << number1.num;
	std::cout << "\n" << number3.num;
	return 0;
}