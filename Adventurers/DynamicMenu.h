#pragma once
#include <string>
#include <vector>
#include "Menu.h"

using std::vector;

namespace cppadventure {
	class DynamicMenu : public Menu {
	private:
		vector<string> selections;

	public:
		DynamicMenu();
		DynamicMenu(vector<string> s);

		vector<string> getSelections() const;

		// s is a new selection to add
		// end : if the selection is the last selection or not
		void addSelection(string s, bool isLast);
		void addSelections(const vector<string> &sv);

		void removeSelection(int index);

		string getPrompt() const;
		void displayMenu() const;
	};
}