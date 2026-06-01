#include "Menu.h"

using namespace cppadventure;

Menu::Menu(string h) 
	: header(h) {
	selections = "";
}

string Menu::getHeader() const {
	return header;
}

string Menu::getSelections() const {
	return selections;
}

void Menu::addSelection(string s, bool isLast) {
	string builder = "";
	builder += s;
	if (!isLast) {
		builder += "\n";
	}
	selections += builder;
}

void Menu::addSelections(string* sarr, int size) {
	for (int i = 0; i < size; i++) {
		if (i < (size - 1)) {
			addSelection(sarr[i], false);
		}
		else {
			addSelection(sarr[i], true);
		}
	}
}