#include <iostream>

int main() {
		int count{};
		int distance{1000};
		int compute{};
		int speed_move{ 10 }, time_move{ 30 };
	
		
		
			int distance_move = 500; // расстояние без отдыха
			int distance_ostatok_move = distance - distance_move; //оставшееся расстояние после отдыха
			int distance_parts = distance_ostatok_move / distance_move; // количество оставшихся частей 
			int distance_ostatok = distance_ostatok_move % distance_move; // некратный остаток
			
			std::cout << distance_parts << "\n" << distance_ostatok;
	

}