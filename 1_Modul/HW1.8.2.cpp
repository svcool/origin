#include <iostream>

namespace plus {
    int calc(int x, int y) {
        return x + y;
    }
}
namespace minus {
    int calc(int x, int y) {
        return x - y;
    }
}
namespace multi {
    int calc(int x, int y) {
        return x * y;
    }
}
namespace dev {
    int calc(int x, int y) {
        return x / y;
    }
}


int main(int argc, char** argv) {
    setlocale(LC_ALL, "Russian");
    system("chcp 1251");
    int x = 6, y = 9;
    std::cout << "x = " << x << ",\ty = " << y << std::endl;
    std::cout << "��������: " << plus::calc(x, y) << std::endl;
    std::cout << "���������: " << minus::calc(x, y) << std::endl;
    std::cout << "���������: " << multi::calc(x, y) << std::endl;
    std::cout << "�������: " << dev::calc(x, y) << std::endl;
}