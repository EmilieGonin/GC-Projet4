#pragma once
#include "../sqlite/sqlite3.h"

static int callback(void* data, int argc, char** argv, char** azColName);
void SQL(sqlite3* db, const char* sql);
void dataSQL(sqlite3* db, const char* sql);
sqlite3* createDatabase();