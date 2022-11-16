#include "List.h"


List::List() {
	this->currentMilk = 0;
	this->warning = 0;
	this->warning_message = "You don't have enough milk for the next 7 days.";
}

List::List(int currentMilk) {
	this->List::List();
	this->currentMilk = currentMilk;
}

List::~List() {
	//
}

int List::getCurrentMilk() {
	return this->currentMilk;
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

void List::addItem(sqlite3* db) {
	std::string name;
	int quantity;

	std::cout << "Item name : ";
	std::cin >> name;
	std::cout << "Name : " << name << "\nItem quantity : ";
	std::cin >> quantity;
	std::cout << "Quantity : " << quantity << "\n";

	std::string quantity_s = std::to_string(quantity);
	std::string sql_s = std::string("INSERT INTO ITEMS(NAME,QUANTITY) VALUES ('" + name + "', " + quantity_s + ");");
	const char* sql = sql_s.c_str();

	SQL(db, sql);
}