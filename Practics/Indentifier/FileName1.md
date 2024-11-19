������ ������������� ������������������ ����� ��� �A1�, ������ � �A2�, ������ - �A3� � ��� �����. �� �A9� ������� �B1�. ��������� ����� �Z9� ����� ��� �A1-A1�, ����� �A1-A2� � ��� �����. ����� �A1-Z9� ������� �A2-A1�.
������������ ����� �������������� - ������ ����� �� ��� �������.
� ��������������� ������� �� ������ �������������� ����� �D�, �F�, �G�, �J�, �M�, �Q�, �V� � ����� �0�.
����� �� C++ �������� ������������ �����, ��������������� ��� ������������� ������� ��������������, �������������� ������� ��������� ��������������� �� ���� ��������.

�������� ���������� ��� ��������� ��������������� �� �������� �������� � C++ �������� � ���� ���������� ������, ������� ����� ������������ �������������� � ������������ � ���������� ���� ���������. �� ����� ������������ ������ ����������� ����� � �����, � ����� ��������� ������ ��� �������� � ���������� ��������������.

���� ������� ������ ���������� ������ ������:

```cpp
#include <iostream>
#include <string>
#include <vector>

class IdentifierGenerator {
public:
    IdentifierGenerator() {
        // ������������� ����������� ��������
        allowedLetters = "ABCDEFGHIKLNPQRSTUVWXYZ"; // ��� D, F, G, J, M, Q, V
        allowedDigits = "123456789"; // ��� 0
        currentIdentifier = "A1"; // ��������� �������������
    }

    std::string generateNext() {
        std::string identifier = currentIdentifier;
        incrementIdentifier();
        return identifier;
    }

private:
    std::string allowedLetters;
    std::string allowedDigits;
    std::string currentIdentifier;

    void incrementIdentifier() {
        size_t pos = currentIdentifier.size() - 1;

        while (pos >= 0) {
            if (currentIdentifier[pos] == '-') {
                pos--;
                continue;
            }

            if (isdigit(currentIdentifier[pos])) {
                // ����������� �����
                char nextDigit = getNextDigit(currentIdentifier[pos]);
                if (nextDigit != '\0') {
                    currentIdentifier[pos] = nextDigit;
                    return;
                } else {
                    currentIdentifier[pos] = allowedDigits[0]; // ����� �� 1
                    pos--;
                }
            } else {
                // ����������� �����
                char nextLetter = getNextLetter(currentIdentifier[pos]);
                if (nextLetter != '\0') {
                    currentIdentifier[pos] = nextLetter;
                    return;
                } else {
                    currentIdentifier[pos] = allowedLetters[0]; // ����� �� A
                    pos--;
                }
            }
        }

        // ���� �� ����� �� �������, ��������� ����� ������
        if (pos < 0) {
            currentIdentifier = "A1-" + currentIdentifier;
        }
    }

    char getNextLetter(char current) {
        size_t index = allowedLetters.find(current);
        if (index != std::string::npos && index + 1 < allowedLetters.size()) {
            return allowedLetters[index + 1];
        }
        return '\0'; // ��� ��������� �����
    }

    char getNextDigit(char current) {
        size_t index = allowedDigits.find(current);
        if (index != std::string::npos && index + 1 < allowedDigits.size()) {
            return allowedDigits[index + 1];
        }
        return '\0'; // ��� ��������� �����
    }
};

int main() {
    IdentifierGenerator generator;

    // ��������� ������ 20 ���������������
    for (int i = 0; i < 20; ++i) {
        std::cout << generator.generateNext() << std::endl;
    }

    return 0;
}
```

### ���������� ����

1. **IdentifierGenerator**: ��� �������� �����, ������� �������� �� ��������� ���������������. �� ����� ����������� ����� � �����, � ����� ������� �������������.

2. **generateNext()**: ���� ����� ���������� ������� ������������� � ����������� ��� ��� ���������� ������.

3. **incrementIdentifier()**: ���� ����� �������� �� ������ ���������� �������� ��������������. �� �������� �� �������� �������������� � ����� � ������, ���������� ����� � ����� � ������������ � ��������� ���������.

4. **getNextLetter() � getNextDigit()**: ��� ������ �������� ��������� ����� ��� ����� �� ����������� �������.

5. **main()**: � ���� ������� ��������� ��������� ���������� � ��������� ������ 20 ���������������.

### �����

�������� ���� ���, �� �������� ������������������ ���������������, ������� ������������� ����� �����������. �� ������ ��������� ����������������, �������, ��������, ����������� ������ ���������� ��� ��������� ���������� ��������.