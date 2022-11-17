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
	int hour; //heure de prise
	int interval; //interval choisi pour l'alarme
	bool regurgitated; //si le biberon est regurgit�

public:
	Bottle(int, int, int, Baby*);
	~Bottle();
	Baby* baby;
	void show();
	void regurgitate();
};