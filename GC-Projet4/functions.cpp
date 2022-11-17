#include "functions.h"

Baby createBaby(sqlite3* db) {
	string name;
	int min_quantity, bottle_quantity, take;

	//On va chercher 

	const char* sql = "SELECT * FROM BABIES";
	std::vector<Element> data = dataSQL(db, sql);
	bool existingBaby = data.size();

	if (existingBaby) {
		cout << "Baby found !\n";
		min_quantity = stoi(data[1].data);
		bottle_quantity = stoi(data[2].data);
		take = stoi(data[3].data);
		name = data[4].data;
		cout << name;
	}
	else {
		cout << "Hello ! What is the name of your baby ? ";
		cin >> name;
		cout << "What a cute name ! Now, enter the minimum quantity the baby must drink each time : ";
		cin >> min_quantity;
		cout << "Now, enter the number of bottle your baby needs to take : ";
		cin >> take;
		cout << "Now, enter the default quantity of your bottles : ";
		cin >> bottle_quantity;

		std::string sql = std::string(
			"INSERT INTO BABIES(MIN_QUANTITY,TAKE,BOTTLE_QUANTITY,NAME)"\
			"VALUES(" + std::to_string(min_quantity) + ", " + std::to_string(take) + ", " + std::to_string(bottle_quantity) + ", '" + name + "');");

		SQL(db, sql.c_str());
	}

	Baby baby(min_quantity, bottle_quantity, take, name, db);
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

List createList(sqlite3* db) {
	int currentMilk;

	const char* sql = "SELECT * FROM LIST";
	std::vector<Element> data = dataSQL(db, sql);
	bool existingList = data.size();

	if (existingList) {
		cout << "List found !\n";
		for (int i = 0; i < existingList; i++)
		{
			cout << data[i].data;
		}
		cout << "\nEnd of list";
	}
	else {
		cout << "List not found !\n";
	}

	cout << "Enter your current stock of milk : ";
	cin >> currentMilk;

	List list(currentMilk);
	return list;
}