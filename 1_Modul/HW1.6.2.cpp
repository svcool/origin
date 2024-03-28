#include <iostream>
void power(int, int, int);

int main(int argc, char** argv)
{
	power(5, 2, 1);
	power(3, 3, 1);
	power(4, 4, 1);
	return 0;
}

void power(int value, int power, int result) {
	for (int i = 0; i < power; i++) {
		result *= value;
		
	}
	std::cout << value << " в степени " << power << " = " << result << std::endl;
}
