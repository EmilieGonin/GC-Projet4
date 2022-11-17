// projet4.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <ctime>
#include "SDL.h"
#include <stdio.h>
#include <stdlib.h>
#include "functions.h";
#undef main //remove _main function from SDL cause it breaks everything

int main() 
{            
	//Création base de données
	cout << "Loading database...\n";
	sqlite3* db = createDatabase();

	//Le parent ouvre l'appli
	cout << "Checking for babies...\n";
	Baby baby = createBaby(db);

	//Le parent utilise la fonctionnalité de liste
	cout << "Checking for list...";
	List list = createList(db);

	//Le parent ajoute un item dans la liste
	cout << "Adding item...\n";
	list.addItem(db);

	//Le parent veut afficher la liste
	cout << "Fetching items...";
	list.getItems(db);
	//cout << "Milk to Buy : " << list.getMilkToBuy(baby.getWeeklyMilkQuantity()) << "\n";

	//Le parent crée un biberon (heures de prise + quantité de lait ingéré)
	cout << "Creating bottle...\n";
	Bottle bottle = createBottle(db, &baby);

	//Vérification alarme (SDL)
	//l'heure actuelle
	//if (heure actuelle >= (bottle.hour + bottle.interval)) { afficher rappel }

	// Création test d'une seconde bouteille
	//Bottle bottle2 = createBottle(&baby);

	//Le bébé regurgite
	cout << "Regurgitating...\n";
	bottle.regurgitate();
	cout << "\nQuantity after regurgitate: " << bottle.baby->getDrankQuantity() << "\n----------" << endl;
	
	//cout << "\nWeekly Milk Quantity : " << bottle.baby->getWeeklyMilkQuantity();

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
