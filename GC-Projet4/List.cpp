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

	std::string sql = std::string("INSERT INTO LIST(NAME,QUANTITY) VALUES ('" + name + "', " + std::to_string(quantity) + ");");

	SQL(db, sql.c_str());
}

vector<vector<Element>> List::getItems(sqlite3* db) {
	const char* sql = "SELECT * FROM LIST";
	vector<vector<Element>> datas = dataSQL(db, sql);
	return datas;
}