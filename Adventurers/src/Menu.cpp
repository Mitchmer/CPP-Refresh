#include "Menu.h"

using namespace cppadventure;

Menu::Menu(string h, string p, string iSel, bool d) 
	: header(h), prompt(p), invalidSelectionMessage(iSel), isActive(d) {}

void Menu::clearConsole() {
	std::cout << "\x1b[2J\x1b[3J\x1b[H";
}
void Menu::pauseConsole() {
	using std::cin;
	
	string discard = "";
	getline(cin, discard);
	cin.clear();
}

string Menu::getHeader() const {
	return header;
}

void Menu::setPrompt(string s) {
	prompt = s;
}

string Menu::getPrompt() const {
	return prompt;
}

void Menu::setInvalidSelectionMessage(string s) {
	invalidSelectionMessage = s;
}

string Menu::getInvalidSelecitonMessage() const {
	return invalidSelectionMessage;
}

void Menu::setIsActive(bool active) {
	isActive = active;
}

bool Menu::getIsActive() const {
	return isActive;
}

Menu::~Menu() {}