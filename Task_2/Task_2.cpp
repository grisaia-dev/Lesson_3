#include <iostream>
#include <windows.h>

class Counter {
public:
    // Изменение числа
    void add_count() { count++; }
    void sub_count() { count--; }

    // Конструкторы
    Counter() { count = 0; }; // Дефолтный 
    Counter(const int num) { count = num; } // Если пользователь захочет поставить свое число

    // Получение числа
    const int get_count() { return count; }
private:
    int count;
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    const std::string yes_or_no[2] = { "да", "нет" }, command[4] = { "+", "-", "=", "x"};
    std::string user_ans;

    std::cout << "Вы хотите указать начальное значение счетчика? Введите да или нет: ";
    std::cin >> user_ans;
    if (user_ans == yes_or_no[0]) {
        std::cout << "Введите начальное значение счетчика: "; 
        int num_set = 0; // переменная для ввода начального значения
        std::cin >> num_set;
        
        Counter count(num_set);

        while ((user_ans != command[3]) && (user_ans != "х")) {
            std::cout << "Введите команду ('+', '-', '=' или 'x'): ";
            std::cin >> user_ans;
            
            if (user_ans == command[0])
                count.add_count();
            else if (user_ans == command[1])
                count.sub_count();
            else if (user_ans == command[2])
                std::cout << count.get_count() << std::endl;
        }
        std::cout << "До свидания!" << std::endl;
    } else if (user_ans == yes_or_no[1]) {
        Counter count;

        while ((user_ans != command[3]) && (user_ans != "х")) {
            std::cout << "Введите команду ('+', '-', '=' или 'x'): ";
            std::cin >> user_ans;

            if (user_ans == command[0])
                count.add_count();
            else if (user_ans == command[1])
                count.sub_count();
            else if (user_ans == command[2])
                std::cout << count.get_count() << std::endl;
        }
        std::cout << "До свидания!" << std::endl;
    } else {
        std::cout << "Нет такого значения!" << std::endl;
    }

    return 0;
}