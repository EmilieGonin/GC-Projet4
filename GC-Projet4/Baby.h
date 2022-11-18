#pragma once
#include <string>
#include "db.h"

class Baby
{
public:
	int min_quantity; //quantité min à mettre dans un biberon
	int take; //nombre de prise;
	int bottle_quantity; //quantité max présente dans le biberon (en ml)
	int drank_quantity; //quantité totale ingérée dans la journée
	std::string name; //nom
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

