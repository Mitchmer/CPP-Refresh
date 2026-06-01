#include "DynamicMenu.h"

using namespace cppadventure;

DynamicMenu::DynamicMenu() {

}

DynamicMenu::DynamicMenu(vector<string> s) {

}

vector<string> DynamicMenu::getSelections() const {
	return selections;
}

// s is a new selection to add
// end : if the selection is the last selection or not
void DynamicMenu::addSelection(string s, bool isLast) {

}

void DynamicMenu::addSelections(const vector<string> &sv) {
	for (string s : sv) {
		selections.push_back(s);
	}
}

void DynamicMenu::removeSelection(int index) {

}

string getPrompt() const;
void displayMenu() const;