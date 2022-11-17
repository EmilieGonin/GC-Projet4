#include "functions.h"

Baby createBaby(sqlite3* db) {
	string name;
	int min_quantity, bottle_quantity, take;

	//On va chercher 

	const char* sql = "SELECT * FROM BABIES";
	vector<vector<Element>> datas = dataSQL(db, sql);
	bool existingBaby = datas.size();

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
	vector<vector<Element>> datas = dataSQL(db, sql);
	bool existingList = datas.size();

	if (existingList) {
		cout << "List found !\n";
		currentMilk = stoi(datas[0][2].data);
		cout << "currentMilk : " << currentMilk << endl;
	}
	else {
		cout << "List not found ! Enter your current stock of milk : ";
		cin >> currentMilk;

		std::string sql = std::string("INSERT INTO LIST(NAME,QUANTITY) VALUES ('milk', " + std::to_string(currentMilk) + ");");

		SQL(db, sql.c_str());
	}

	List list(currentMilk);
	return list;
}