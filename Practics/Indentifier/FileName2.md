 ������� ������������� ��� ��������� ���������� ��������� �� ������� ����������� ����: ����� � ������������ ������� ������ �������� �����������, ���������� �������:
/// <Summary>
/// ������� ���������� ����� ������������� �� ������ �������� ����������� ������������
/// </Summary>
/// <param name="indentifier"> ����������� ������������������ </param>
/// <returns>
std::string GenerateIndentifier(const std::string &indentifier);

������� ������� ����� `IdentifierGenerator`, ����� �� �������������� ������ ����������. �� ������� ����� `GenerateIdentifier`, ������� ����� ��������� ������� ������������� � �������� ��������� � ������������ ��������� ������������� �� ������ ����� ��������.

��� ����������� ������ ������ � ����������� �����������:

```cpp
#include <iostream>
#include <string>

class IdentifierGenerator {
public:
    /// <summary>
    /// ������� ���������� ����� ������������� �� ������ �������� ����������� ��������������.
    /// </summary>
    /// <param name="identifier">������������� ������������������.</param>
    /// <returns>����� ��������������� �������������.</returns>
    std::string GenerateIdentifier(const std::string &identifier) {
        currentIdentifier = identifier;
        incrementIdentifier();
        return currentIdentifier;
    }

private:
    std::string allowedLetters = "ABCDEFGHIKLNPQRSTUVWXYZ"; // ��� D, F, G, J, M, Q, V
    std::string allowedDigits = "123456789"; // ��� 0
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

    // ������ ������������� ����������
    std::string currentId = "A1"; // ��������� �������������

    for (int i = 0; i < 20; ++i) {
        std::string newId = generator.GenerateIdentifier(currentId);
        std::cout << "Generated Identifier: " << newId << std::endl;
        currentId = newId; // ��������� ������� �������������
    }

    return 0;
}
```

### ���������� ���������

1. **GenerateIdentifier**: ����� ������ ��������� ������� ������������� � �������� ��������� � �������� `incrementIdentifier`, ����� ������������� ��������� �������������.

2. **currentIdentifier**: ��� ����������, ������� ������ ������� �������������, ���������� � �����.

3. **main()**: � ���� ������� �� ���������� `GenerateIdentifier` ��� ��������� ����� ���������������, ������� � "A1".

### �����

������ ����� `IdentifierGenerator` ������������� ����� ����������� � ����� �������������� ��� ��������� ��������������� �� ������ ����������� ��������. �� ������ ����� �������� ��������� ������������� � �������� ��������� ������������� � ������������������.