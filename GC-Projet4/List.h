#pragma once
#include <iostream>
#include <string>
#include "db.h"

class List
{
protected:
	int currentMilk;
	bool warning;
	//std::vector<std::vector> items;
public:
	std::string warning_message;
	List();
	List(int);
	~List();
	int getCurrentMilk();
	int getMilkToBuy(int);
	void addItem(sqlite3*);
	void getItems(sqlite3*);
};

