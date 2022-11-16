#pragma once
#include <iostream>
#include <string>

class List
{
protected:
	int currentMilk;
	bool warning;
	std::string warning_message;
public:
	List(int);
	~List();
	int getMilkToBuy(int);
	void addItem();
};

