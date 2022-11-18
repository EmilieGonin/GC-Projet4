#include <iostream>
#include <string>
#include "db.h"
#include <vector>

using namespace std;

int callback(void* datas, int argc, char** argv, char** azColName) {
	int i;
	//On crée une variable qui va copier void* datas dans un autre type
	vector<vector<Element>>* p_datas = static_cast<vector<vector<Element>>*>(datas);
	vector<Element> data;

	for (i = 0; i < argc; i++) {
		//On stocke chaque champs des données dans la structure
		Element element;
		element.name = string(azColName[i]);
		element.data = string(argv[i]);
		//On envoie la structure dans un vecteur
		data.push_back(element);
	}

	//On renvoie ce vecteur dans un vecteur de vecteur
	p_datas->push_back(data);

	printf("\n");
	return 0;
}

void SQL(sqlite3* db, const char* sql) {
	char* error = 0;
	int rc = sqlite3_exec(db, sql, NULL, NULL, &error);

	if (rc) {
		cerr << sql << "\n--> SQL error\n";
	}
	else {
		cout << sql << "\n--> SQL done !\n";
	}
}

std::vector<std::vector<Element>> dataSQL(sqlite3* db, const char* sql) {
	std::vector<std::vector<Element>> datas;
	char* error = 0;
	int rc = sqlite3_exec(db, sql, callback, &datas, &error);

	return datas;
}

sqlite3* createDatabase() {
	sqlite3* db;
	char* error = 0;
	const char* sql;
	int rc = sqlite3_open("projet4.db", &db);

	if (rc) {
		cerr << "Can't open database: %s\n";
	}
	else {
		fprintf(stderr, "Opened database successfully\n");
	}

	cout << "Creating tables...\n";

	sql = "CREATE TABLE IF NOT EXISTS BABIES(ID INTEGER PRIMARY KEY NOT NULL, MIN_QUANTITY INT, TAKE INT, BOTTLE_QUANTITY INT, NAME VARCHAR(100));" \
		"CREATE TABLE IF NOT EXISTS BOTTLES(ID INTEGER PRIMARY KEY NOT NULL, QUANTITY INT, HOUR INT, MINUTES INT, INTERVAL INT, REGURGITATED INT);" \
		"CREATE TABLE IF NOT EXISTS LIST(ID INTEGER PRIMARY KEY NOT NULL, NAME VARCHAR(100), QUANTITY INT);";

	SQL(db, sql);

	cout << "----------\n";

	return db;
}