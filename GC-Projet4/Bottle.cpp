#include "Bottle.h"
#include <iostream>

using namespace std;

Bottle::Bottle(int quantity, int hour, int interval, Baby* baby) {
	regurgitated = false;
	timer = 0;
	cout << "Quantity before set : " << baby->drank_quantity << "\n";

	this->quantity = quantity;
	this->hour = hour;
	this->interval = interval;
	this->baby = baby;
	this->baby->setDrankQuantity(quantity);
	cout << "Quantity after set : " << this->baby->drank_quantity << "\n";
}

Bottle::~Bottle() {}

void Bottle::show() {
	cout << "-----\nQuantity : " << quantity
		<< "\nRegurgitated : " << regurgitated
		<< "\n-----\n";
}

void Bottle::regurgitate() {
	regurgitated = true;
	this->baby->drank_quantity = this->baby->drank_quantity - quantity;
}