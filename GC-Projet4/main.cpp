// projet4.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <ctime>
#include "db.h"
#include "Bottle.h"
#include "Baby.h"
#include "List.h"
#include "SDL.h"
#include <stdio.h>
#include <stdlib.h>
#undef main //remove _main function from SDL cause it breaks everything

using namespace std;

Baby createBaby() {
	string name;
	int min_quantity, bottle_quantity, take;

	cout << "Hello ! What is the name of your baby ? ";
	cin >> name;
	cout << "What a cute name ! Now, enter the minimum quantity the baby must drink each time : ";
	cin >> min_quantity;
	cout << "Now, enter the number of bottle your baby needs to take : ";
	cin >> take;
	cout << "Now, enter the default quantity of your bottles : ";
	cin >> bottle_quantity;

	Baby baby(min_quantity, bottle_quantity, take, name);
	return baby;
	// ajouter conditions
}

Bottle createBottle(Baby* baby) {
	int quantity, hour, minutes, interval;

	cout << "Enter the quantity drank : ";
	cin >> quantity;
	cout << "Enter the hour : ";
	cin >> hour;
	cout << "Minutes : ";
	cin >> minutes;
	cout << "Enter the interval for the alarm : ";
	cin >> interval;

	Bottle bottle(quantity, hour, interval, baby);
	return bottle;
	/* quantity doit être entre min_quantity et bottle_quantity
	hour doit être entre 0 et 23
	minutes doit être entre 0 et 59*/
}

List createList() {
	int currentMilk;

	cout << "Enter your current stock of milk : ";
	cin >> currentMilk;

	List list(currentMilk);
	return list;
}

int main() 
{            
	//Création base de données
	sqlite3* db = createDatabase();

	//Le parent ouvre l'appli
	Baby baby = createBaby();

	//Le parent utilise la fonctionnalité de liste
	List list = createList();

	//Le parent veut afficher la liste
	cout << "Milk to Buy : " << list.getMilkToBuy(baby.getWeeklyMilkQuantity());

	//Le parent ajoute un item dans la liste
	//

	//Le parent crée un biberon (heures de prise + quantité de lait ingéré)
	Bottle bottle = createBottle(&baby);

	//Vérification alarme (SDL)
	//l'heure actuelle
	//if (heure actuelle >= (bottle.hour + bottle.interval)) { afficher rappel }

	// Création test d'une seconde bouteille
	Bottle bottle2 = createBottle(&baby);

	//Le bébé regurgite
	bottle.regurgitate();
	cout << "\ngetDrank : " << bottle.baby->getDrankQuantity()
		<< "\nWeekly Milk Quantity : " << bottle.baby->getWeeklyMilkQuantity();

	sqlite3_close(db);
	return 0;
}

// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
