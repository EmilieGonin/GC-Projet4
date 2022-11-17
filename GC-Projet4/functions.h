#pragma once
#include <iostream>
#include <string>
#include "db.h"
#include "Bottle.h"
#include "Baby.h"
#include "List.h"

using namespace std;

Baby createBaby(sqlite3* db);
Bottle createBottle(Baby* baby);
List createList(sqlite3* db);