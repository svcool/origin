#include <iostream>

class Fraction
{
private:
	int numerator_;
	int denominator_;

	friend std::ostream& operator<<(std::ostream& stream, const Fraction& fract)
	{
		stream << "Дробь(double): ";
		stream << fract.getValue();
		return stream;
	}
public:

	Fraction(int numerator, int denominator)
	{
		numerator_ = numerator;
		denominator_ = denominator;
		
	}
	double getValue()const { return static_cast<double>(numerator_) / static_cast<double>(denominator_); }

	bool operator==(Fraction other) { return getValue() == other.getValue() ? 1 : 0; }
	bool operator!=(Fraction other) { return !(*this == other); }
	bool operator>(Fraction other) { return getValue() > other.getValue() ? 1 : 0; }
	bool operator<(Fraction other) { return other > *this; }
	bool operator>=(Fraction other) { return !(*this < other); }
	bool operator<=(Fraction other) { return !(*this > other); }

};

int main()
{
	setlocale(LC_ALL, "Russian");
	Fraction f1(4, 3);
	Fraction f2(6, 11);
	std::cout << f1 << std::endl;
	std::cout << f2 << std::endl;
	std::cout << "f1" << ((f1 == f2) ? " == " : " not == ") << "f2" << '\n';
	std::cout << "f1" << ((f1 != f2) ? " != " : " not != ") << "f2" << '\n';
	std::cout << "f1" << ((f1 < f2) ? " < " : " not < ") << "f2" << '\n';
	std::cout << "f1" << ((f1 > f2) ? " > " : " not > ") << "f2" << '\n';
	std::cout << "f1" << ((f1 <= f2) ? " <= " : " not <= ") << "f2" << '\n';
	std::cout << "f1" << ((f1 >= f2) ? " >= " : " not >= ") << "f2" << '\n';
	return 0;
}