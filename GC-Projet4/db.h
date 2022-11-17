#pragma once
#include "../sqlite/sqlite3.h"
#include <vector>

using namespace std;

struct Element {
	string name;
	string data;
};

int callback(void* data, int argc, char** argv, char** azColName);
void SQL(sqlite3* db, const char* sql);
vector<vector<Element>> dataSQL(sqlite3* db, const char* sql);
sqlite3* createDatabase();