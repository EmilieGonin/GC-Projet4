#pragma once
#include <iostream>
#include <string>
#include "db.h"

class List
{
protected:
	int currentMilk; //lait possédé par l'utilisateur
	bool warning; //si l'alerte doit être affichée (lait insuffisant pour les 7 prochains jours)
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

