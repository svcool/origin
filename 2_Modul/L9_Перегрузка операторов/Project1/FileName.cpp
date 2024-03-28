#include <iostream>
class ComplexNumber
{
	double re_, im_;
public:
	ComplexNumber(double re, double im) { re_ = re; im_ = im; }
	ComplexNumber operator+(ComplexNumber other)
	{
		return ComplexNumber(re_ + other.re_, im_ + other.im_);
	}
	ComplexNumber operator+(int other) { return ComplexNumber(re_ + other, im_); }
	ComplexNumber operator-(ComplexNumber other)
	{
		return ComplexNumber(re_ - other.re_, im_ - other.im_);
	}
	ComplexNumber operator-(int other) { return ComplexNumber(re_ - other, im_); }
	void Print() { std::cout << re_ << (im_ < 0 ? "" : "+") << im_ << "i\n"; }

	double Abs() { return std::sqrt(re_ * re_ + im_ * im_); }
	bool operator==(ComplexNumber other) { return Abs() == other.Abs(); }
	bool operator!=(ComplexNumber other) { return !(*this == other); }
	bool operator>(ComplexNumber other) { return Abs() > other.Abs(); }
	bool operator<(ComplexNumber other) { return other > *this; }
	bool operator>=(ComplexNumber other) { return !(*this < other); }
	bool operator<=(ComplexNumber other) { return !(*this > other); }
	ComplexNumber& operator++() { re_++; im_++; return *this; }
	ComplexNumber operator++(int)
	{
		ComplexNumber temp = *this;
		++(*this);
		return temp;
	}
};
int main(int argc, char** argv)
{
	//ComplexNumber c1(1, 1), c2(4, 2);
	//ComplexNumber sum_c_c = c1 + c2;
	//ComplexNumber sum_c_i = c1 + 3;
	//ComplexNumber sub_c_c = c1 - c2;
	//ComplexNumber sub_c_i = c1 - 5;
	//sum_c_c.Print(); // 5+3i
	//sum_c_i.Print(); // 4+1i
	//sub_c_c.Print(); // -3-1i
	//sub_c_i.Print(); // -4+1i
	ComplexNumber c1(1, 1), c2(4, 2), c3(1, 1);
	ComplexNumber sum_pre = ++c1 + c2;
	ComplexNumber sum_post = c3++ + c2;
	sum_pre.Print(); // 6+4i
	sum_post.Print(); // 5+3i
	c1.Print(); // 2+2i
	c3.Print(); // 2+2i
}