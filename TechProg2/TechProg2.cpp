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
	std::cout << "-5- - Display By Name Destination\n";
	std::cout << "-0- - Exit\n";
	std::cout << "Your choice: ";
	std::cin >> action;
}

void MenuAeroflot() {

	Storage* store = new Storage;
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
			store->addElement(aeroflot);
			store->sortTimeDeparture();

			system("pause");
			system("cls");
			break;
		case 2:
			system("cls");

			try {
				if (store->getCount() == 0) throw std::exception("Storage is empty\n");
				val = 0;
				std::cout << "If you want to delete last Element(enter -> " << store->getCount() << ")\n";

				std::cout << "Index of Elemnt to delete: ";
				std::cin >> val;

				if (val <= 0) throw std::exception("Index cannot <0 or =0\n");
				if (store->getCount() < val)  throw std::exception("This Element doesn't exist\n");
				(*(store))[val].getData();
				store->deleteElement(val);
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
				if (store->getCount() == 0) throw std::exception("Storage is empty\n");
				val = 0;
				std::cout << "Index of Elemnt to edit: ";
				std::cin >> val;

				if (val <= 0) throw std::exception("Index cannot <0 or =0\n");
				if (store->getCount() < val)  throw std::exception("This Element doesn't exist\n");
				(*(store))[val].getData();
				store->editElement(val);
			}
			catch (const std::exception& ex) {
				std::cout << ex.what() << '\n';
			}

			system("pause");
			system("cls");
			break;
		case 4:
			system("cls");

			store->displayKeep();

			system("pause");
			system("cls");
			break;
		case 5:
			system("cls");

			store->displayByNameDestination();

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
	delete store;
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

