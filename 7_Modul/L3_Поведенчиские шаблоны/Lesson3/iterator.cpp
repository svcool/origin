#include<iostream>
#include<array>
#include<vector>
using namespace std;
template<typename T>
class MyIter
{
public:
	MyIter() {};
	MyIter(T& val) { Ptr = &val; };
	void operator=(T val)
	{
		*Ptr = val;
	}
	int operator*()
	{
		return *Ptr;
	}
	void operator++()
	{
		Ptr++;
	}
private:
	T* Ptr = nullptr;
};


int main_it()
{
	setlocale(LC_ALL, "Russian");
	int k = 7;
	MyIter<int> it(k);
	it = 20;
	int Arr[5] = { 0, 5, 2, 3, 4 };
	for(MyIter<int> it1 : Arr)
		cout << *it1 << endl;
	
	vector<int> V10 = { 10, 20, 30 };
	for (MyIter<int> it1 : V10)
		cout << *it1 << endl;

	vector<double> V = { 1.2, 2.5, 3.3, 4.0, 5.9 };

	vector<double>::iterator first = V.begin();
	cout << *first << endl;
	return 0;
}