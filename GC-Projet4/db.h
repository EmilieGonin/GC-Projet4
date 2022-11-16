#pragma once
#include "../sqlite/sqlite3.h"

void SQL(sqlite3* db, const char* sql);
sqlite3* createDatabase();