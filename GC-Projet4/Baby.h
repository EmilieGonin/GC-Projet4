#pragma once
#include <string>

class Baby
{
public:
	int min_quantity; //quantité min à mettre dans un biberon
	int take; //nombre de prise;
	int bottle_quantity; //quantité max présente dans le biberon (en ml)
	int drank_quantity;
	std::string name;
	Baby();
	Baby(int, int, int, std::string);
	~Baby();

	int getMinQuantity();
	int getBottleQuantity();
	void setBottleQuantity(int);
	int getGoalQuantity();
	int getDrankQuantity();
	void setDrankQuantity(int);
	int getWeeklyMilkQuantity();
};

