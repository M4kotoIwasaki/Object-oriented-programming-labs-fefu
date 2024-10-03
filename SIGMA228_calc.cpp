#include <iostream>
#include <limits>
double result = 0;

void menu()
{
	int choise;
		std::cout << "SIGMA228 калькулятор!\n\nВыберете операцию:\n";
		std::cout << "Сложение - 1\n";
		std::cout << "Вычитание - 2\n";
		std::cout << "Умножение - 3\n";
		std::cout << "Деление - 4\n";
		std::cout << "Чтобы выйти из программы, введите другоое число.\nВаш выбор: ";
		std::cin >> choise;
		if (std::cin.fail())
		{
			system("cls");
			std::cout << "Ошибка типа данных!\n";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			menu();
		}
		double a;
		double b;
	switch (choise)
	{
	case 1:
		system("cls");
		std::cout << "Введите первое число: ";
		std::cin >> a;
		if (std::cin.fail())
		{
			std::cout << "Ошибка типа данных!\n";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			menu();
		}
		std::cout << "Введите второе число: ";
		std::cin >> b;
		if (std::cin.fail())
		{
			std::cout << "Ошибка типа данных!\n";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			menu();
		}
		result = a + b;
		std::cout << "Результат: " << result << "\n\n-----------------\n";
		menu();
	case 2:
		system("cls");
		std::cout << "Введите первое число: ";
		std::cin >> a;
		if (std::cin.fail())
		{
			std::cout << "Ошибка типа данных!\n";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			menu();
		}
		std::cout << "Введите второе число: ";
		std::cin >> b;
		if (std::cin.fail())
		{
			std::cout << "Ошибка типа данных!\n";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			menu();
		}
		result = a - b;
		std::cout << "Результат: " << result << "\n\n-----------------\n";
		menu();
	case 3:
		system("cls");
		b;
		std::cout << "Введите первое число: ";
		std::cin >> a;
		if (std::cin.fail())
		{
			std::cout << "Ошибка типа данных!\n";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			menu();
		}
		std::cout << "Введите второе число: ";
		std::cin >> b;
		if (std::cin.fail())
		{
			std::cout << "Ошибка типа данных!\n";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			menu();
		}
		result = a * b;
		std::cout << "Результат: " << result << "\n\n-----------------\n";
		menu();
	case 4:
		system("cls");
		b = 1;
		std::cout << "Введите первое число: ";
		std::cin >> a;
		if (std::cin.fail())
		{
			std::cout << "Ошибка типа данных!\n";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			menu();
		}
		do
		{
			if (b == 0)
				std::cout << "Делить на ноль незьзя! Плохой пользователь >:(\n";
			std::cout << "Введите второе число: ";
			std::cin >> b;
			if (std::cin.fail())
			{
				std::cout << "Ошибка типа данных!\n";
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				menu();
			}
		} while (b == 0);
		result = a / b;
		std::cout << "Результат: " << result << "\n\n-----------------\n";
		menu();
	default:
		system("cls");
		std::cout << "\n\nПока, пока!\n\n";
	}
}

int main()
{
	setlocale(LC_ALL, "ru");
	menu();
	return 0;
}