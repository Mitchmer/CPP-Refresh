#pragma once
#include "Menu.h"

namespace cppadventure {
	class DynamicMenu : public Menu {
	private:
		vector<string>* selections;

	public:
		// vector of selection strings and a prompt string
		DynamicMenu(string h = "", string p = "", const vector<string>* svPtr = new vector<string>());

		vector<string> getSelections() const override;
		void addSelection(string s) override;
		void addSelections(const vector<string>* sv) override;
		bool removeSelection(size_t index) override;

		void displayMenu() const;

	};
}