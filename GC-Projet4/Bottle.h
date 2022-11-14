#pragma once
#include "Baby.h"

/* Quand le parent prépare un biberon, il crée un biberon sur l'application
Il faut préciser l'heure de prise du biberon + la quantité bu par le bébé
La quantité du biberon sera égale à la quantité entrée au début en paramètre
Le parent peut changer ce paramètre à tout moment
La liste de course se met à jour automatiquement à la création du biberon */

class Bottle
{
protected:
	int quantity; //quantité bu
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
//biberon créé -> déduire bottle_quantity de la liste de course