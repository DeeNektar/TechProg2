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
#include "Aeroflot.h"
#include "Storage.h"
#include "Potoki.h"

int actionMain;
int action;
int val;
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
	std::cout << "-5- - Display By Type Aerocraft\n";
	std::cout << "-0- - Exit\n";
	std::cout << "Your choice: ";
	std::cin >> action;
}

void MenuAeroflot() {

	Keeper* k = new Keeper;
	Aeroflot* aeroflot;
	action = 1;

	while (action != 0) {
		MenuAeroflotPrint();
		switch (action) {
		case 0:
			break;
		case 1:
			system("cls");

			aeroflot = new Aeroflot;
			aeroflot->setData();
			k->addElement(aeroflot);
			k->sortTimeDeparture();

			system("pause");
			system("cls");
			break;
		case 2:
			system("cls");

			try {
				if (k->getCount() == 0) throw std::exception("Storage is empty\n");
				val = 0;
				std::cout << "If you want to delete last Element(enter -> " << k->getCount() << ")\n";

				std::cout << "Index of Elemnt to delete: ";
				std::cin >> val;

				if (val <= 0) throw std::exception("Index cannot <0 or =0\n");
				if (k->getCount() < val)  throw std::exception("This Element doesn't exist\n");
				(*(k))[val].getData();
				k->deleteElement(val);
			}
			catch (const std::exception& ex) {
				std::cout << ex.what() << '\n';
			}

			system("pause");
			system("cls");
			break;

		case 3:
			system("cls");

			try {
				if (k->getCount() == 0) throw std::exception("Storage is empty\n");
				val = 0;
				std::cout << "Index of Elemnt to edit: ";
				std::cin >> val;

				if (val <= 0) throw std::exception("Index cannot <0 or =0\n");
				if (k->getCount() < val)  throw std::exception("This Element doesn't exist\n");
				(*(k))[val].getData();
				k->editElement(val);
			}
			catch (const std::exception& ex) {
				std::cout << ex.what() << '\n';
			}

			system("pause");
			system("cls");
			break;
		case 4:
			system("cls");

			k->displayKeep();

			system("pause");
			system("cls");
			break;
		case 5:
			system("cls");

			k->displayByTypeAerocraft();

			system("pause");
			system("cls");
			break;
		default:
			system("cls");

			std::cout << "ERROR\n";

			system("pause");
			system("cls");
			break;
		}
	}
	delete k;
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

			MenuAeroflot();

			system("pause");
			system("cls");
			break;
		case 2:
			system("cls");

			threeSentence();

			system("pause");
			system("cls");
			break;
		default:
			system("cls");

			std::cout << "Comand again.\n";

			system("pause");
			system("cls");
			break;
		}
	}
	return 0;
}

