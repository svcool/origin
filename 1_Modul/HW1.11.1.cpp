#include <iostream>
#include <string>
using namespace std;
/*int main(){
	char name[100], lname[100];
	cout << "Enter your name: " << endl;
	cin >> name;
	cout << "Enter your last namt: " << endl;
	cin >> lname;
	cout << "Hello, " << name << " " << lname << "!" << endl;

}*/
int main() {
	string name, lname;
	cout << "Enter your name: " << endl;
	cin >> name;
	cout << "Enter your last namt: " << endl;
	cin >> lname;
	cout << "Hello, " << name + lname << "!" << endl;
}