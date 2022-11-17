#pragma once
#include <iostream>
#include <string>
#include "db.h"

class List
{
protected:
	int currentMilk;
	bool warning;
public:
	std::string warning_message;
	List();
	List(int);
	~List();
	int getCurrentMilk();
	int getMilkToBuy(int);
	void addItem(sqlite3*);
	std::vector<Element> getItems(sqlite3*);
};

