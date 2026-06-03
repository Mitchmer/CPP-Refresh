#include "Menu.h"

using namespace cppadventure;

Menu::Menu(string h, string p) 
	: header(h), prompt(p) {}

string Menu::getHeader() const {
	return header;
}

void Menu::setPrompt(string s) {
	prompt = s;
}

string Menu::getPrompt() const {
	return prompt;
}