#pragma once
#include "Menu.h"

namespace cppadventure {
	class DynamicMenu : public Menu {
	private:
		vector<string>* selections;

	public:
		// vector of selection strings and a prompt string
		DynamicMenu(const vector<string>* svPtr = new vector<string>(), string h = "", string p = "");

		vector<string> getSelections() const override;
		void addSelection(string s) override;
		void addSelections(const vector<string>* sv) override;
		bool removeSelection(size_t index) override;

	};
}