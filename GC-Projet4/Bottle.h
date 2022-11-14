#pragma once
#include "Baby.h"

/* Quand le parent pr�pare un biberon, il cr�e un biberon sur l'application
Il faut pr�ciser l'heure de prise du biberon + la quantit� bu par le b�b�
La quantit� du biberon sera �gale � la quantit� entr�e au d�but en param�tre
Le parent peut changer ce param�tre � tout moment
La liste de course se met � jour automatiquement � la cr�ation du biberon */

class Bottle
{
protected:
	int quantity; //quantit� bu
	int timer;
	int hour;
	int interval;
	bool regurgitated;

public:
	Bottle(int, int, int, Baby*);
	~Bottle();
	Baby* baby;
	void show();
	void regurgitate();
};

//biberon bu en entier ? oui alors quantity = bottle_quantity
//biberon cr�� -> d�duire bottle_quantity de la liste de course