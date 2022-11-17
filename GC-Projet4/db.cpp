#include <iostream>
#include <string>
#include "db.h"
#include <vector>

using namespace std;

int callback(void* data, int argc, char** argv, char** azColName) {
	int i;
	std::vector<Element>* p_data = static_cast<std::vector<Element>*>(data);

	for (i = 0; i < argc; i++) {
		Element element;
		element.name = std::string(azColName[i]);
		element.data = std::string(argv[i]);
		p_data->push_back(element);

		if (std::string(azColName[i]) != "ID") {
			if (std::string(azColName[i]) == "QUANTITY") {
				cout << " (x" << argv[i] << ")";
			}
			else {
				cout << "- " << argv[i];
			}
			//printf("%s\n", argv[i]);
		}
	}

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

std::vector<Element> dataSQL(sqlite3* db, const char* sql) {
	std::vector<Element> data;
	char* error = 0;
	int rc = sqlite3_exec(db, sql, callback, &data, &error);

	return data;
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
		"CREATE TABLE IF NOT EXISTS BOTTLE(ID INTEGER PRIMARY KEY NOT NULL, QUANTITY INT, TIMER INT, HOUR INT, INTERVAL INT, REGURGITATED BOOLEAN);" \
		"CREATE TABLE IF NOT EXISTS ITEMS(ID INTEGER PRIMARY KEY NOT NULL, NAME VARCHAR(100), QUANTITY INT);";

	SQL(db, sql);

	cout << "----------\n";

	return db;
}