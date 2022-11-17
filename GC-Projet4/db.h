#pragma once
#include "../sqlite/sqlite3.h"
#include <vector>

struct Element {
	std::string name;
	std::string data;
};

int callback(void* data, int argc, char** argv, char** azColName);
void SQL(sqlite3* db, const char* sql);
std::vector<Element> dataSQL(sqlite3* db, const char* sql);
sqlite3* createDatabase();