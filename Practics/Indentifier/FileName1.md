Первый идентификатор последовательности имеет вид «A1», второй — «A2», третий - «A3» и так далее. За «A9» следует «B1». Следующий после «Z9» имеет вид «A1-A1», потом «A1-A2» и так далее. После «A1-Z9» следует «A2-A1».
Максимальная длина идентификатора - десять групп по два символа.
В идентификаторах никогда не должны присутствовать буквы «D», «F», «G», «J», «M», «Q», «V» и цифра «0».
Нужно на C++ написать библиотечный класс, предназначенный для использования другими программистами, обеспечивающий функцию генерации идентификаторов по этим правилам.

Создание библиотеки для генерации идентификаторов по заданным правилам в C++ включает в себя реализацию класса, который будет генерировать идентификаторы в соответствии с описанными вами условиями. Мы будем использовать только разрешенные буквы и цифры, а также реализуем логику для перехода к следующему идентификатору.

Ниже приведён пример реализации такого класса:

```cpp
#include <iostream>
#include <string>
#include <vector>

class IdentifierGenerator {
public:
    IdentifierGenerator() {
        // Инициализация разрешенных символов
        allowedLetters = "ABCDEFGHIKLNPQRSTUVWXYZ"; // Без D, F, G, J, M, Q, V
        allowedDigits = "123456789"; // Без 0
        currentIdentifier = "A1"; // Начальный идентификатор
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
                // Увеличиваем цифру
                char nextDigit = getNextDigit(currentIdentifier[pos]);
                if (nextDigit != '\0') {
                    currentIdentifier[pos] = nextDigit;
                    return;
                } else {
                    currentIdentifier[pos] = allowedDigits[0]; // Сброс на 1
                    pos--;
                }
            } else {
                // Увеличиваем букву
                char nextLetter = getNextLetter(currentIdentifier[pos]);
                if (nextLetter != '\0') {
                    currentIdentifier[pos] = nextLetter;
                    return;
                } else {
                    currentIdentifier[pos] = allowedLetters[0]; // Сброс на A
                    pos--;
                }
            }
        }

        // Если мы вышли за пределы, добавляем новую группу
        if (pos < 0) {
            currentIdentifier = "A1-" + currentIdentifier;
        }
    }

    char getNextLetter(char current) {
        size_t index = allowedLetters.find(current);
        if (index != std::string::npos && index + 1 < allowedLetters.size()) {
            return allowedLetters[index + 1];
        }
        return '\0'; // Нет следующей буквы
    }

    char getNextDigit(char current) {
        size_t index = allowedDigits.find(current);
        if (index != std::string::npos && index + 1 < allowedDigits.size()) {
            return allowedDigits[index + 1];
        }
        return '\0'; // Нет следующей цифры
    }
};

int main() {
    IdentifierGenerator generator;

    // Генерация первых 20 идентификаторов
    for (int i = 0; i < 20; ++i) {
        std::cout << generator.generateNext() << std::endl;
    }

    return 0;
}
```

### Объяснение кода

1. **IdentifierGenerator**: Это основной класс, который отвечает за генерацию идентификаторов. Он имеет разрешенные буквы и цифры, а также текущий идентификатор.

2. **generateNext()**: Этот метод возвращает текущий идентификатор и увеличивает его для следующего вызова.

3. **incrementIdentifier()**: Этот метод отвечает за логику увеличения текущего идентификатора. Он проходит по символам идентификатора с конца к началу, увеличивая цифры и буквы в соответствии с заданными правилами.

4. **getNextLetter() и getNextDigit()**: Эти методы получают следующую букву или цифру из разрешенных наборов.

5. **main()**: В этой функции создается экземпляр генератора и выводятся первые 20 идентификаторов.

### Вывод

Запустив этот код, вы получите последовательность идентификаторов, которые соответствуют вашим требованиям. Вы можете расширить функциональность, добавив, например, возможность сброса генератора или установку начального значения.