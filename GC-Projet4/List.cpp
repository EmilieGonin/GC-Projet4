#include "List.h"

List::List(int currentMilk) {
	this->currentMilk = currentMilk;
	this->warning = 0;
	this->warning_message = "You don't have enough milk for the next 7 days.";
}

List::~List() {
	//
}

int List::getMilkToBuy(int weekly_milk) {
	int milkToBuy = weekly_milk - this->currentMilk;

	if (milkToBuy > 0) {
		this->warning = 1;
		return milkToBuy;
	}
	else {
		return 0;
	}
}

void List::addItem() {
	std::string name;
	int quantity;

	std::cout << "Item name : ";
	std::cin >> name;
	std::cout << "Item quantity : ";
	std::cin >> quantity;
}