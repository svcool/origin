#include <iostream>
#include <memory>
using namespace std;
int main() {

	unique_ptr<int> ptr(new int(6));
	ptr.release();
	cout << ptr;

}