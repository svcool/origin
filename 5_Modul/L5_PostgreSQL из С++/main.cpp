#include <iostream>
#include <pqxx/pqxx>
int main()
{
	std::cout<<"Hello"<<std::endl;
	pqxx::connection c(
		"host=localhost "
		"port=5432 "
		"dbname=musicsite "
		"user=postgres "
		"password=postgres");
	return 0;

return 0;
}