#include "Aeroflot.h"

Aeroflot::Aeroflot() {

	nameDestination = "";
	numberFlight = 0;
	typeAerocraft = "";
}

Aeroflot::~Aeroflot(){
	//std::cout << "Destructor AF\n";
}

void Aeroflot::setData() {

	std::cout << "nameDestination: ";
	std::cin >> this->nameDestination;
	std::cout << '\n';

	std::cout << "numberFlight: ";
	while (!(std::cin >> this->numberFlight)) {
		std::cout << "Enter a number >0.\n";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits <std::streamsize>::max(), '\n');
		if (std::cin >> this->numberFlight)
			break;
	}
	if (((this->numberFlight) < 0))
		this->numberFlight = 0;
	std::cout << '\n';

	std::cout << "typeAerocraft: ";
	std::cin >> this->typeAerocraft;
	std::cout << '\n';
}

void Aeroflot::getData() {
	std::cout << "Aeroflot\n";
	std::cout << "nameDestination: " << nameDestination << '\n';
	std::cout << "number\t       : " << numberFlight << '\n';
	std::cout << "typeAerocraft  : " << typeAerocraft << '\n';
}