#include "DynamicNumberedMenu.h"

using namespace cppadventure;

//============================
// Default Constructor

DynamicNumberedMenu::DynamicNumberedMenu(string h, string p, const vector<string>* svPtr, int i, string invalidSelMsg, bool isActive)
	: Menu(h, p, invalidSelMsg, isActive), input(i) {
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

bool DynamicNumberedMenu::rangeIncludesSelectionNumber(size_t selectionNumber) const {
	if (selectionNumber == 0) return false;
	else return (!selections->empty() && ((selectionNumber - 1) <= lastIndex));
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

void DynamicNumberedMenu::displayMenu() const {
	using std::cout, std::endl;

	clearConsole();
	cout << getHeader() << endl;
	for (string selection : getSelections()) {
		cout << selection << endl;
	}
	cout << getPrompt();
}

bool DynamicNumberedMenu::pauseForSelectionAndValidate(){
	using std::cin;

	cin >> input;
	if (cin.fail()) {
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return false;
	}
	return rangeIncludesSelectionNumber(input);
}

int DynamicNumberedMenu::getInputSelection() const {
	return input;
}

DynamicNumberedMenu::~DynamicNumberedMenu() {
	delete selections;
}