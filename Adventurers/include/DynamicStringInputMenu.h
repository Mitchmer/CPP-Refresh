#pragma once
#include "Menu.h"

namespace cppadventure {
	class DynamicStringInputMenu : public Menu {

	public:
		// vector of selection strings and a prompt string
		DynamicStringInputMenu(string h = "", string p = "", const vector<string>* svPtr = new vector<string>(), string input = "", string invalidSelMsg = "", bool isActive = true);

		//================================================================
		//	Selection 
		vector<string> getSelections() const override;
		void addSelection(string s) override;
		void addSelections(const vector<string>* sv) override;

		bool removeSelection(size_t index) override;

		void displayMenu() const;

		// Input
		void pauseForSelection();
		string getInput() const;

		~DynamicStringInputMenu();

	private:
		vector<string>* selections;
		size_t lastIndex;
		bool isEmpty = true;
		string input;
	};
}