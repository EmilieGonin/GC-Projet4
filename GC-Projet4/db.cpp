#include <iostream>
#include "db.h"

using namespace std;

void SQL(sqlite3* db, const char* sql) {
	char* error = 0;
	int rc = sqlite3_exec(db, sql, NULL, NULL, &error);

	if (rc) {
		cerr << "SQL error: %s\n";
	}
	else {
		cout << "SQL done !\n";
	}
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

	sql = "CREATE TABLE IF NOT EXISTS BABY(name varchar (100));" \
		"CREATE TABLE IF NOT EXISTS BOTTLE(quantity INT);" \
		"CREATE TABLE IF NOT EXISTS ITEMS(quantity INT);";

	SQL(db, sql);

	cout << "----------\n";

	return db;
}