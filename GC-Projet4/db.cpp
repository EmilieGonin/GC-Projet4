#include <iostream>
#include <string>
#include "db.h"

using namespace std;

static int callback(void* data, int argc, char** argv, char** azColName) {
	int i;

	for (i = 0; i < argc; i++) {
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
		cerr << "--> SQL error: %s\n";
	}
	else {
		cout << sql << "\n--> SQL done !\n";
	}
}

void dataSQL(sqlite3* db, const char* sql) {
	char* error = 0;
	int rc = sqlite3_exec(db, sql, callback, NULL, &error);
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

	sql = "CREATE TABLE IF NOT EXISTS BABY(ID INTEGER PRIMARY KEY NOT NULL, MIN_QUANTITY INT, TAKE INT, BOTTLE_QUANTITY INT, NAME VARCHAR(100));" \
		"CREATE TABLE IF NOT EXISTS BOTTLE(ID INTEGER PRIMARY KEY NOT NULL, QUANTITY INT, TIMER INT, HOUR INT, INTERVAL INT, REGURGITATED BOOLEAN);" \
		"CREATE TABLE IF NOT EXISTS ITEMS(ID INTEGER PRIMARY KEY NOT NULL, NAME VARCHAR(100), QUANTITY INT);";

	SQL(db, sql);

	cout << "----------\n";

	return db;
}