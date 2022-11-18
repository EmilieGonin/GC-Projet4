#include <ctime>
#include "SDL.h"
#include <stdio.h>
#include <stdlib.h>
#include "functions.h";
#include "window.h"
#undef main //remove _main function from SDL cause it breaks everything

int main()
{
	SDL_Event event;
	Window window ;

	window.init();
	int gradx = 0;
	int grady = 0;

	window.homeView();

	while (window.running)
	{
		window.WindowEvent();
		window.renderText("/Roboto/Robot-Bold");
		window.refreshRender();
    
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

	//On referme la database
	sqlite3_close(db);
  }
  window.destroy();
  return 0;
}
