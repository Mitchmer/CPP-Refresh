#include "Menu.h"

using namespace cppadventure;

Menu::Menu(string h, string p) 
	: header(h), prompt(p) {
	selections = "";
}

string Menu::getHeader() const {
	return header;
}

string Menu::getSelections() const {
	return selections;
}

string Menu::getPrompt() const {
	return prompt;
}

void Menu::addSelection(string s, bool isLast) {
	string builder = "";
	builder += s;
	if (!isLast) {
		builder += "\n";
	}
	selections += builder;
}

void Menu::addSelections(string sarr[], int size) {
	for (int i = 0; i < size; i++) {
		if (i < (size - 1)) {
			addSelection(sarr[i], false);
		}
		else {
			addSelection(sarr[i], true);
		}
	}
}

void Menu::displayMenu() const {
	cout << getHeader() << endl;
	cout << getSelections() << endl;
	cout << getPrompt() << endl;
}