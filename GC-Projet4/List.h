#pragma once
#include <string>

class List
{
protected:
	int currentMilk;
public:
	List();
	List(int);
	~List();
	int getMilkToBuy(int);
};

