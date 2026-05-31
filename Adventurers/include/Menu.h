#pragma once

#include <string>
#include <iostream>

using std::string, std::cout, std::cin, std::endl;

namespace cppadventure {
	class Menu {
	private:
		string header;
		string selections;
		string prompt;

	public:
		Menu(string b = "default header  ", string s = "default prompt");

		string getHeader() const;
		string getSelections() const;
		string getPrompt() const;

		// s is a new selection to add
		// end : if the selection is the last selection or not
		void addSelection(string s, bool isLast);
		void addSelections(string s[], int size);

		void displayMenu() const;

	};
}