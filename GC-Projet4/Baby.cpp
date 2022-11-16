#include "Baby.h"

Baby::Baby() {
	this->min_quantity = 0;
	this->bottle_quantity = 0;
	this->drank_quantity = 0;
	this->name = "Test";
}

Baby::Baby(int min_quantity, int bottle_quantity, int take, std::string name, sqlite3* db) {
	this->drank_quantity = 0;

	this->min_quantity = min_quantity;
	this->bottle_quantity = bottle_quantity;
	this->take = take;
	this->name = name;

	std::string sql = std::string(
		"INSERT INTO BABIES(MIN_QUANTITY,TAKE,BOTTLE_QUANTITY,NAME)"\
		"VALUES(" + std::to_string(min_quantity) + ", " + std::to_string(take) + ", " + std::to_string(bottle_quantity) + ", '" + name + "');");

	SQL(db, sql.c_str());
}

Baby::~Baby() {}

int Baby::getMinQuantity() {
	return this->min_quantity;
}

int Baby::getBottleQuantity() {
	return this->bottle_quantity;
}

void Baby::setBottleQuantity(int quantity) {
	this->bottle_quantity = quantity;
}

int Baby::getGoalQuantity() {
	return this->min_quantity * this->take;
}

int Baby::getDrankQuantity() {
	return this->drank_quantity;
}

void Baby::setDrankQuantity(int quantity) {
	this->drank_quantity = drank_quantity + quantity;
}

int Baby::getWeeklyMilkQuantity() {
	return this->getGoalQuantity() * 7;
}