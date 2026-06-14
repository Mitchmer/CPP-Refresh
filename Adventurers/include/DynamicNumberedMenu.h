#pragma once
#include "Menu.h"

namespace cppadventure {
	class DynamicNumberedMenu : public Menu {

	public:
		DynamicNumberedMenu(string h = "", string p = "", const vector<string>* svPtr = new vector<string>(), int i = -1, string invalidSelMsg = "", bool isActive = true);

		bool rangeIncludesSelectionNumber(size_t n) const;

		//================================================================
		//	Selection 
		vector<string> getSelections() const override;
		void addSelection(string s) override;
		void addSelections(const vector<string>* sv) override;

		bool removeSelection(size_t index) override;

		void displayMenu() const;

		// Input
		bool pauseForSelectionAndValidate();
		int getInputSelection() const;

		~DynamicNumberedMenu();

	private:
		vector<string>* selections;
		size_t lastIndex;
		bool isEmpty = true;
		int input;



	};
}