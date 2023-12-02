// TechProg2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
/*1. Стандартные потоки
Определить класс с именем АЕRОFLОТ, содержащий следующие поля :
● название пункта назначения рейса;
● номер рейса;
● тип самолета.
Определить методы доступа к этим полям и перегруженные операции
извлечения и вставки для объектов типа АЕRОFLОТ.
Заранее число объектов не известно.
Написать программу, выполняющую следующие действия :
● записи должны быть размещены в алфавитном порядке по названиям
пунктов назначения;
● вывод на экран пунктов назначения и номеров рейсов,
обслуживаемых самолетом, тип которого введен с клавиатуры;
● если таких рейсов нет, выдать на дисплей соответствующее
сообщение*/

#include <iostream>
int actionMain;
int action;
void MenuMain() {

	std::cout << "Commands\n";
	std::cout << "-1- - 1 zadanie\n";
	std::cout << "-2- - 2 zadanie\n";
	std::cout << "-0- - Exit\n";
	std::cout << "Your choice: ";
	std::cin >> actionMain;
}

void MenuAeroflotPrint() {

	std::cout << "Commands\n";
	std::cout << "-1- - Add Element\n";
	std::cout << "-2- - Delete Element\n";
	std::cout << "-3- - Change Element\n";
	std::cout << "-4- - Display All\n";
	std::cout << "-5- - Display By Name Destination\n";
	std::cout << "-0- - Exit\n";
	std::cout << "Your choice: ";
	std::cin >> action;
}

int main()
{
	actionMain = 1;
	while (actionMain != 0) {
		MenuMain();
		switch (actionMain) {
		case 0:
			break;
		case 1:
			system("cls");

			//MenuAeroflot();

			system("pause");
			system("cls");
			break;
		case 2:
			system("cls");

			//quote();

			system("pause");
			system("cls");
			break;
		default:
			system("cls");

			std::cout << "Trouble maaaann. Select comand again.\n";

			system("pause");
			system("cls");
			break;
		}
	}
	return 0;
}

