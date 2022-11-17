#include "functions.h"

Baby createBaby(sqlite3* db) {
	string name;
	int min_quantity, bottle_quantity, take;

	//On va chercher les infos dans la database
	const char* sql = "SELECT * FROM BABIES";
	vector<vector<Element>> datas = dataSQL(db, sql);
	bool existingBaby = datas.size();

	//Si les bébés existent, on récupère les données
	if (existingBaby) {
		cout << "Baby found !\n";
		min_quantity = stoi(datas[0][1].data);
		take = stoi(datas[0][2].data);
		bottle_quantity = stoi(datas[0][3].data);
		name = datas[0][4].data;

		for (int i = 0; i < datas.size(); i++)
		{
			for (int j = 0; j < datas[i].size(); j++) {
				cout << datas[i][j].name
					<< " : " << datas[i][j].data << endl;
			}
		}
	}
	//Sinon, on créé un nouveau bébé avec des input utilisateurs
	else {
		cout << "Hello ! What is the name of your baby ? ";
		cin >> name;

		//Easter Egg
		if (name == "Emilie" || name == "Hugo" || name == "Jimmy" || name == "Tom") {
			cout << "This name is just perfect ! ";
		}
		else if (name == "Leann") {
			cout << "Wow ! Like the superstar ??! ";
		}

		cout << "Now, enter the minimum quantity the baby must drink each time : ";
		cin >> min_quantity;
		cout << "Now, enter the number of bottle your baby needs to take : ";
		cin >> take;
		cout << "Now, enter the default quantity of your bottles : ";
		cin >> bottle_quantity;

		string sql = string(
			"INSERT INTO BABIES(MIN_QUANTITY,TAKE,BOTTLE_QUANTITY,NAME)"\
			"VALUES(" + to_string(min_quantity) + ", " + to_string(take) + ", " + to_string(bottle_quantity) + ", '" + name + "');");

		SQL(db, sql.c_str());
	}

	cout << "----------" << endl;
	Baby baby(min_quantity, bottle_quantity, take, name, db);
	return baby;
}

Bottle createBottle(sqlite3* db, Baby* baby) {
	int quantity, hour, minutes, interval;

	cout << "Enter the quantity drank : ";
	cin >> quantity;
	cout << "Enter the hour : ";
	cin >> hour;
	cout << "Minutes : ";
	cin >> minutes;
	cout << "Enter the interval for the alarm : ";
	cin >> interval;

	string sql = string(
		"INSERT INTO BOTTLES(QUANTITY, HOUR, MINUTES, INTERVAL, REGURGITATED)"\
		"VALUES(" + to_string(quantity) + ", " + to_string(hour) + ", " + to_string(minutes) + ", " + to_string(interval) + ", 0);");

	SQL(db, sql.c_str());

	cout << "----------" << endl;
	Bottle bottle(quantity, hour, interval, baby);
	return bottle;
}

List createList(sqlite3* db) {
	int currentMilk;

	//On va chercher les infos dans la database
	const char* sql = "SELECT * FROM LIST";
	vector<vector<Element>> datas = dataSQL(db, sql);
	bool existingList = datas.size();

	//Si on trouve des infos, on récupère celles du lait possédé par l'utilisateur
	if (existingList) {
		cout << "List found !\n";
		currentMilk = stoi(datas[0][2].data);
		cout << "currentMilk : " << currentMilk << endl;
	}
	//Sinon, on demande la quantité de lait possédé par l'utilisateur
	else {
		cout << "List not found ! Enter your current stock of milk : ";
		cin >> currentMilk;

		string sql = string("INSERT INTO LIST(NAME,QUANTITY) VALUES ('milk', " + to_string(currentMilk) + ");");

		SQL(db, sql.c_str());
	}

	cout << "----------" << endl;
	List list(currentMilk);
	return list;
}