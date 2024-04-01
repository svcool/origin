#include <iostream>
#include <WT/Dbo/Dbo.h>
#include <WT/Dbo/backend/Postgres.h>
#include <Windows.h>
using namespace std;
#pragma execution_character_set("utf-8")
class Book;
class Shop;


class Publisher {
public:
	string name = "";
	Wt::Dbo::collection<Wt::Dbo::ptr<Book>> books;

	template<typename Action>
	void persist(Action& a) {
		Wt::Dbo::field(a, name, "name");
		Wt::Dbo::hasMany(a, books, Wt::Dbo::ManyToOne, "publisher")
	}
};

	class Book {
	public:
		string title = "";
		Wt::Dbo::ptr<Publisher> publisher;
		Wt::Dbo::collection<Wt::Dbo::ptr<Stock>> stocks;

		template<typename Action>
		void persist(Action& a) {
			Wt::Dbo::field(a, title, "title");
			Wt::Dbo::belongsTo(a, publishers, "publisher");  //дописывает _id в таблице
			Wt::Dbo::hasMany(a, stocks, Wt::Dbo::ManyToOne, "book")
		}
	};

	class Stock {
	public:
		int count{};
		Wt::Dbo::ptr<Shop> shops;
		Wt::Dbo::ptr<Book> books;
		Wt::Dbo::collection<Wt::Dbo::ptr<Sale>> sales;

		template<typename Action>
		void persist(Action& a) {
			Wt::Dbo::field(a, count, "count");
			Wt::Dbo::belongsTo(a, Shop, "shop");
			Wt::Dbo::belongsTo(a, book, "book");
			Wt::Dbo::hasMany(a, sales, Wt::Dbo::ManyToOne, "stock");
		}
	};

	class Shop{
	public:
		string name = "";
		Wt::Dbo::collection<Wt::Dbo::ptr<Stock>> stocks;

		template<typename Action>
		void persist(Action& a) {
			Wt::Dbo::field(a, name, "name");
			Wt::Dbo::hasMany(a, stocks, Wt::Dbo::ManyToOne, "shop");
		}
	};

	class Sale {
	public:
		string name = "";
		int price{};
		string date_sale="";
		int count{};
		Wt::Dbo::ptr<Stock> stocks;

		template<typename Action>
		void persist(Action& a) {
			Wt::Dbo::field(a, name, "name");
			Wt::Dbo::field(a, date, "date");
			Wt::Dbo::field(a, price, "price");
			Wt::Dbo::belongsTo(a, stocks, "stock");
		}
	};

//подключается к PostgreSQL;
//создаёт все необходимые таблицы и связи между ними;
//заполняет таблицы тестовыми данными из С++ кода.Данные для заполнения выберите произвольно;
//выводит информацию об издателе(publisher), имя или идентификатор которого принимается через std::cin..
// Программа должна выводить список магазинов, в которых продают книги этого издателя.

int main() {

	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);
	setvbuf(stdout, nullptr, _IOFBF, 10000);
	//setlocale(LC_ALL, "Russian");
	try {
		string connectionString =
			"host = localhost "
			"port = 5432 "
			"dbname = postgres "
			"user = postgres "
			"password = postgres";

		unique_ptr<Wt::Dbo::backend::Postgres> connection = make_unique<Wt::Dbo::backend::Postgres>(connectionString);
		Wt::Dbo::Session s;
		
		
		s.setConnection(move(connection));
		s.mapClass<Publisher>("publisher");
		s.mapClass<Book>("book");
		s.mapClass<Sale>("sale");
		s.mapClass<Shop>("shop");
		s.mapClass<Stock>("stock");
		
		s.createTables();
		Wt::Dbo::Transaction t(s);



		std::unique_ptr<Publisher> joe(new Publisher{ "Roga", {} });
		joe-> = "Joe";
		joe->phone = "12345";
		joe->karma = 100;
		Wt::Dbo::ptr<user> joeDb = s.add(std::move(joe));
		
		t.commit();
	}
	catch (const exception& err) {
		cout << "Error happened: " << err.what() << endl;
	}



	return 0;
}