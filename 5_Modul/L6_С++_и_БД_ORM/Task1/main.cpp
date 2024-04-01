#include <iostream>
#include <WT/Dbo/Dbo.h>
#include <WT/Dbo/backend/Postgres.h>
#include <Windows.h>
using namespace std;
#pragma execution_character_set("utf-8")
class Book;
class Shop;
class Publisher;
class Stock;
class Sale;

class Publisher {
public:
	string name = "";
	Wt::Dbo::collection<Wt::Dbo::ptr<Book>> books;

	template<class Action>
	void persist(Action& a) {
		Wt::Dbo::field(a, name, "name");
		Wt::Dbo::hasMany(a, books, Wt::Dbo::ManyToOne, "publisher");
	}
};

	class Book {
	public:
		string title = "";
		Wt::Dbo::ptr<Publisher> publisher;
		Wt::Dbo::collection<Wt::Dbo::ptr<Stock>> stocks;

		template<class Action>
		void persist(Action& a) {
			Wt::Dbo::field(a, title, "title");
			Wt::Dbo::belongsTo(a, publisher, "publisher");  //дописывает _id в таблице
			Wt::Dbo::hasMany(a, stocks, Wt::Dbo::ManyToOne, "book");
		}
	};

	class Stock {
	public:
		int count{};
		Wt::Dbo::ptr<Shop> shops;
		Wt::Dbo::ptr<Book> books;
		Wt::Dbo::collection<Wt::Dbo::ptr<Sale>> sales;

		template<class Action>
		void persist(Action& a) {
			Wt::Dbo::field(a, count, "count");
			Wt::Dbo::belongsTo(a, shops, "shop");
			Wt::Dbo::belongsTo(a, books, "book");
			Wt::Dbo::hasMany(a, sales, Wt::Dbo::ManyToOne, "stock");
		}
	};

	class Shop{
	public:
		string name = "";
		Wt::Dbo::collection<Wt::Dbo::ptr<Stock>> stocks;

		template<class Action>
		void persist(Action& a) {
			Wt::Dbo::field(a, name, "name");
			Wt::Dbo::hasMany(a, stocks, Wt::Dbo::ManyToOne, "shop");
		}
	};

	class Sale {
	public:
		int price{};
		string date_sale="";
		int count{};
		Wt::Dbo::ptr<Stock> stocks;

		template<class Action>
		void persist(Action& a) {
			Wt::Dbo::field(a, date_sale, "date");
			Wt::Dbo::field(a, price, "price");
			Wt::Dbo::field(a, count, "count");
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
		
		s.dropTables();
		s.createTables();
		Wt::Dbo::Transaction t(s);

		// издательство
		std::unique_ptr<Publisher> p1(new Publisher{ "Roga", {} }); //установка значений
		std::unique_ptr<Publisher> p2(new Publisher{ "Piter", {} });
		std::unique_ptr<Publisher> p3(new Publisher{ "XXX", {} });

		Wt::Dbo::ptr<Publisher>  p1db = s.add(std::move(p1)); // добавление в БД
		Wt::Dbo::ptr<Publisher>  p2db = s.add(std::move(p2));
		Wt::Dbo::ptr<Publisher>  p3db = s.add(std::move(p3));

		//магазин
		std::unique_ptr<Shop> shop1(new Shop{ "Ogonek", {} });
		std::unique_ptr<Shop> shop2(new Shop{ "Knigniy", {} });
		std::unique_ptr<Shop> shop3(new Shop{ "My book", {} });

		Wt::Dbo::ptr<Shop>  shop1db = s.add(std::move(shop1));
		Wt::Dbo::ptr<Shop>  shop2db = s.add(std::move(shop2));
		Wt::Dbo::ptr<Shop>  shop3db = s.add(std::move(shop3));

		//Книги в базе book
		std::unique_ptr<Book> book1{ new Book };
		book1->title = "Война и мир";
		book1->publisher = p1db;
		std::unique_ptr<Book> book2(new Book{ "Преступление и наказание", p2db, {} });
		std::unique_ptr<Book> book3(new Book{ "Горе от ума", p3db, {} });

		Wt::Dbo::ptr<Book>  book1db = s.add(std::move(book1));
		Wt::Dbo::ptr<Book>  book2db = s.add(std::move(book2));
		Wt::Dbo::ptr<Book>  book3db = s.add(std::move(book3));

		//Stock
		std::unique_ptr<Stock> stock1(new Stock{ 10, shop1db, book1db, {} });
		std::unique_ptr<Stock> stock2(new Stock{ 10, shop2db, book2db, {} });
		std::unique_ptr<Stock> stock3(new Stock{ 10, shop3db, book3db, {} });

		Wt::Dbo::ptr<Stock>  stock1db = s.add(std::move(stock1));
		Wt::Dbo::ptr<Stock>  stock2db = s.add(std::move(stock2));
		Wt::Dbo::ptr<Stock>  stock3db = s.add(std::move(stock3));

	
		//Sale
		std::unique_ptr<Sale> sale1(new Sale{ 22, "2024-01-10", 4, stock1db });
		std::unique_ptr<Sale> sale2(new Sale{ 20, "2024-02-20", 1, stock1db });
		std::unique_ptr<Sale> sale3(new Sale{ 19, "2024-03-15", 2, stock1db });

		Wt::Dbo::ptr<Sale>  sale1db = s.add(std::move(sale1));
		Wt::Dbo::ptr<Sale>  sale2db = s.add(std::move(sale2));
		Wt::Dbo::ptr<Sale>  sale3db = s.add(std::move(sale3));

		t.commit();
		string input{};
		int id{};

		Wt::Dbo::ptr<Publisher> pub;
		pub = s.find<Publisher>().where("id=?").bind(id);
		pub = s.find<Publisher>().where("name=?").bind(input);

	}
	catch (const exception& err) {
		cout << "Error happened: " << err.what() << endl;
	}



	return 0;
}