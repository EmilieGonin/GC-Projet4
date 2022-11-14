#pragma once
#include <string>

struct Item {
	std::string name;
	int quantity;
};

void initItem(Item items) {
	items.name = " ";
	items.quantity = 0;
}