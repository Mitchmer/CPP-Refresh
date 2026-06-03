#include "DynamicNumberedMenu.h"

using namespace cppadventure;

//============================
// Default Constructor

DynamicNumberedMenu::DynamicNumberedMenu(const vector<string>* svPtr, string h, string p)
	: Menu(h, p) {
	selections = new vector<string>();
	lastIndex = 0;

	if (svPtr != nullptr) {
		if (!svPtr->empty()) {
			for (string s : *svPtr) {
				selections->push_back(s);
			}
			lastIndex = selections->size() - 1;
		}
	}
}

//===========================
// Range Validation

bool DynamicNumberedMenu::rangeIncludes(size_t index) const {
	return (!selections->empty() && index <= lastIndex);
}

//==========================
// Overrides

vector<string> DynamicNumberedMenu::getSelections() const {
	return *selections;
}

void DynamicNumberedMenu::addSelection(string s) {
	selections->push_back(s);
	lastIndex = selections->size() - 1;
}

void DynamicNumberedMenu::addSelections(const vector<string>* sv) {
	for (string s : *sv) {
		selections->push_back(s);
	}
	lastIndex = selections->size() - 1;
}

bool DynamicNumberedMenu::removeSelection(size_t index) {
	size_t size = selections->size();
	if ((index < size) && size > 0) {
		selections->erase(selections->begin() + index);
		size--;
		if (size > 0) {
			lastIndex = size - 1;
		}
		else {
			lastIndex = 0;
		}
		return true;
	}
	else {
		return false;
	}
}
