#include <iostream>

class Fraction
{
private:
	int numerator_;
	int denominator_;

public:
	Fraction(int numerator, int denominator)
	{
		numerator_ = numerator;
		denominator_ = denominator;
		if (denominator == 0) {throw std::exception("знаменатель равен 0");}
	}
	// сокращение дроби
	Fraction nod(Fraction& obj)
	{
		int num = obj.numerator_, denom = obj.denominator_, rem;
		if (num < denom)
		{
			int temp = num;
			num = denom;
			denom = temp;
		}
		while (rem = num % denom)
		{
			num = denom;
			denom = rem;
		}
		obj.numerator_ /= (denom < 0) ? abs(denom) : denom;
		obj.denominator_ /= abs(denom);
		
		return *this;
	}

	bool operator==(Fraction other) { return (numerator_ / denominator_) == (other.numerator_ / other.denominator_) ? 1 : 0; }
	bool operator!=(Fraction other) { return !(*this  == other); }
	bool operator>(Fraction other) { return (numerator_ / denominator_) > (other.numerator_ / other.denominator_) ? 1 : 0; }
	bool operator<(Fraction other) { return other > *this; }
	bool operator>=(Fraction other) { return !(*this < other); }
	bool operator<=(Fraction other) { return !(*this > other); }
	Fraction operator+(Fraction other) {
		Fraction temp = Fraction((numerator_ * other.denominator_) + (other.numerator_ * denominator_), denominator_ * other.denominator_);
		nod(temp);
		return temp;
	}
	Fraction operator-(Fraction other) {
		Fraction temp = Fraction((numerator_ * other.denominator_) - (other.numerator_ * denominator_), denominator_ * other.denominator_);
		nod(temp);
		return temp;
	}
	Fraction operator*(Fraction other) {
		Fraction temp = Fraction((numerator_ * other.numerator_), denominator_ * other.denominator_);
		nod(temp);
		return temp;
	}
	Fraction operator/(Fraction other) {
		Fraction temp = Fraction((numerator_ * other.denominator_), denominator_ * other.numerator_);
		nod(temp);
		return temp;
	}
	
	/* Инкременты декременты */
		//префикс
	Fraction& operator++() { 
		*this = *this + Fraction(1,1); 
		return  *this; 
	}
	Fraction& operator--() { 
		*this = *this - Fraction(1, 1);
	return	*this; 
	}
		// постфикс
	Fraction operator++(int) { 
		Fraction copy = *this; ++(*this); 
	return copy; 
	}
	Fraction operator--(int) { 
		Fraction copy = *this; --(*this); 
	return copy;
	}

	/* Унарный минус*/
	Fraction operator-() { 
		*this = *this * Fraction(-1, 1); 
		return *this;
	}


	void print_info() {
		std::cout << numerator_ << "/" << denominator_;
	}

};

void print(Fraction f1, Fraction f2, Fraction result, std::string op) {
	f1.print_info(); std::cout << op ; f2.print_info(); std::cout << " = "; result.print_info(); std::cout << "\n";
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int a1{}, b1{};
	int a2{}, b2{};
	std::cout << "Введите числитель дроби 1: "; std::cin >> a1;
	std::cout << "Введите знаменатель дроби 1: "; std::cin >> b1;
	std::cout << "Введите числитель дроби 1: "; std::cin >> a2;
	std::cout << "Введите знаменатель дроби 1: "; std::cin >> b2;
	try {
		Fraction f1(a1, b1);
		Fraction f2(a2, b2);
	
	std::cout << "Проверка арифметики" << std::endl;
	Fraction add_fraction = f1 + f2;
	print(f1, f2, add_fraction, " + ");
	Fraction sub_fraction = f1 - f2;
	print(f1, f2, sub_fraction, " - ");
	Fraction multi_fraction = f1 * f2;
	print(f1, f2, multi_fraction, " * ");
	Fraction div_fraction = f1 / f2;
	print(f1, f2, div_fraction, " / ");
	/* инкремент декремент */
	 //проверка префикса  и постфикса
	std::cout << "\nПроверка префикса и постфикса" << std::endl;
	std::cout << "++"; f1.print_info(); std::cout << " * "; f2.print_info();
	Fraction inkrement_pref = ++f1 * f2;
	std::cout << " = "; inkrement_pref.print_info(); std::cout << "\n";
	std::cout << "Значение дроби 1 = "; f1.print_info(); std::cout << std::endl;

	f1.print_info(); std::cout << "-- * "; f2.print_info();
	Fraction dekrement_post = f1-- * f2;
	std::cout << " = "; dekrement_post.print_info(); std::cout << "\n";
	std::cout << "Значение дроби 1 = "; f1.print_info(); std::cout << std::endl;

	//проверка префикса  и постфикса
	f1.print_info(); std::cout << "++ * "; f2.print_info();
	Fraction inkrement_post = f1++ * f2;
	std::cout << " = "; inkrement_post.print_info(); std::cout << "\n";
	std::cout << "Значение дроби 1 = "; f1.print_info(); std::cout << std::endl;

	std::cout << "--"; f1.print_info(); std::cout << " * "; f2.print_info();
	Fraction dekrement_pref = --f1 * f2;
	std::cout << " = "; dekrement_pref.print_info(); std::cout << "\n";
	std::cout << "Значение дроби 1 = "; f1.print_info(); std::cout << std::endl;

	//проверка унарного минуса
	std::cout << "\nУнарный минус" << std::endl;
	std::cout << "-"; f1.print_info(); std::cout << " * "; f2.print_info();
	Fraction dekrement_minus = -f1 * f2;
	std::cout << " = "; dekrement_minus.print_info(); std::cout << "\n";
	std::cout << "Значение дроби 1 = "; f1.print_info(); std::cout << std::endl;


	std::cout << "\nСравнение:" << std::endl;
	std::cout << "f1" << ((f1 == f2) ? " == " : " not == ") << "f2" << '\n';
	std::cout << "f1" << ((f1 != f2) ? " != " : " not != ") << "f2" << '\n';
	std::cout << "f1" << ((f1 < f2) ? " < " : " not < ") << "f2" << '\n';
	std::cout << "f1" << ((f1 > f2) ? " > " : " not > ") << "f2" << '\n';
	std::cout << "f1" << ((f1 <= f2) ? " <= " : " not <= ") << "f2" << '\n';
	std::cout << "f1" << ((f1 >= f2) ? " >= " : " not >= ") << "f2" << '\n';

	return 0;

	}
	catch (const std::exception ex) {
		std::cout << "Ошибка создания объекта: " << ex.what() << std::endl;
	}
	catch (...) { std::cout << "Неизвестная ошибка" << std::endl; }
}