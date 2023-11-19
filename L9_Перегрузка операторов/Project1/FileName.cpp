// domain_error.cpp
// compile with: /EHsc
#include <exception>
#include <iostream>
#include <stdexcept>
#include <typeinfo>
using namespace std;
#include <iostream>
#include <functional>

int main()
{
    std::function<int(2)> f = 0;
    try {
        f();
    }
    catch (const std::bad_function_call& e) {
        std::cout << e.what() << '\n';
    }
}