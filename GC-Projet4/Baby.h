#pragma once
#include <string>
#include "db.h"

class Baby
{
public:
	int min_quantity; //quantit� min � mettre dans un biberon
	int take; //nombre de prise;
	int bottle_quantity; //quantit� max pr�sente dans le biberon (en ml)
	int drank_quantity;
	std::string name;
	Baby();
	Baby(int, int, int, std::string, sqlite3*);
	~Baby();

	int getMinQuantity();
	int getBottleQuantity();
	void setBottleQuantity(int);
	int getGoalQuantity();
	int getDrankQuantity();
	void setDrankQuantity(int);
	int getWeeklyMilkQuantity();
};

