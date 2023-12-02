#pragma once
/*Определить класс с именем АЕRОFLОТ, содержащий следующие поля :
● название пункта назначения рейса;
● номер рейса;
● тип самолета.
Определить методы доступа к этим полям и перегруженные операции
извлечения и вставки для объектов типа АЕRОFLОТ.*/

#include <iostream>

class Aeroflot {

private:
	std::string nameDestination;
	int numberFlight;
	std::string typeAerocraft;

public:
	Aeroflot();
	~Aeroflot();

	std::string& getNameDestination() {
		return nameDestination;
	}

	int& getNumberFlight() {
		return numberFlight;
	}

	std::string& getTypeAerocraft() {
		return typeAerocraft;
	}

	void setNameDestination(std::string& str) {
		nameDestination = str;
	}

	void setNumber(int& a) {
		numberFlight = a;
	}

	void setTypeAerocraft(int& a) {
		typeAerocraft = a;
	}

	void getData();
	void setData();
};