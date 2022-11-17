#pragma once
#include <iostream>
#include <string>
#include "db.h"

class List
{
protected:
	int currentMilk; //lait poss�d� par l'utilisateur
	bool warning; //si l'alerte doit �tre affich�e (lait insuffisant pour les 7 prochains jours)
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

