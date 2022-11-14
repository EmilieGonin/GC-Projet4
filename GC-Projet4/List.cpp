#include "List.h"

List::List() {
	this->currentMilk = 0;
}

List::List(int currentMilk) {
	this->currentMilk = currentMilk;
}

List::~List() {
	//
}

int List::getMilkToBuy(int weekly_milk) {
	int milkToBuy = weekly_milk - this->currentMilk;

	if (milkToBuy > 0) {
		return milkToBuy;
	}
	else {
		return 0;
	}
}