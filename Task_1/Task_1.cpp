﻿#include <iostream>

class Calculator {
public:
	double add() { return num1 + num2; }
	double multiply() { return num1 * num2; }
	double subtract_1_2() { return num1 - num2; }
	double subtract_2_1() { return num2 - num1; }
	double divide_1_2() { return num1 / num2; }
	double divide_2_1() { return num2 / num1; }

	bool set_num1(double num1);
	bool set_num2(double num2);

private:
	double num1 = 0;
	double num2 = 0;
};

bool Calculator::set_num1(double num1) {
	while (num1 == 0) {
		std::cout << "Введите num1: ";
		std::cin >> num1;
		if (num1 != 0)
			this->num1 = num1;
		else
			std::cout << "Неверный ввод!" << std::endl;
	}
	return true;
}

bool Calculator::set_num2(double num2) {
	while (num2 == 0) {
		std::cout << "Введите num2: ";
		std::cin >> num2;
		if (num2 != 0)
			this->num2 = num2;
		else
			std::cout << "Неверный ввод!" << std::endl;
	}
	return true;
}

int main() {
	setlocale(LC_ALL, "Rus");

	Calculator calc;

	while ((calc.set_num1(0) && calc.set_num2(0)) == true) {
		std::cout << "num1 + num2 = " << calc.add() << std::endl;
		std::cout << "num1 - num2 = " << calc.subtract_1_2() << std::endl;
		std::cout << "num2 - num1 = " << calc.subtract_2_1() << std::endl;
		std::cout << "num1 * num2 = " << calc.multiply() << std::endl;
		std::cout << "num1 / num2 = " << calc.divide_1_2() << std::endl;
		std::cout << "num2 / num1 = " << calc.divide_2_1() << std::endl;
	}
	return 0;
}