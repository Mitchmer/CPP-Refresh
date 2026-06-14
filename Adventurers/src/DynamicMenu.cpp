#include "DynamicMenu.h"

//===================================
// UNUSED

using namespace cppadventure;

DynamicMenu::DynamicMenu(const vector<string>* svPtr, string h, string p) 
	: Menu(h, p) {
	selections = new vector<string>();

	if (svPtr != nullptr) {
		if (!svPtr->empty()) {
			for (string s : *svPtr) {
				selections->push_back(s);
			}
		}
	}
}

vector<string> DynamicMenu::getSelections() const {
	return *selections;
}

// s is a new selection to add
// end : if the selection is the last selection or not
void DynamicMenu::addSelection(string s) {
	selections->push_back(s);
}

void DynamicMenu::addSelections(const vector<string>* sv) {
	for (string s : *sv) {
		selections->push_back(s);
	}
}

bool DynamicMenu::removeSelection(size_t index) {
	if ((index < selections->size()) && !selections->empty()) {
		selections->erase(selections->begin() + index);
		return true;
	}
	else {
		return false;
	}
}

void DynamicMenu::displayMenu() const {}