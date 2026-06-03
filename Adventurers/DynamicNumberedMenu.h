#pragma once
#include "DynamicMenu.h"

namespace cppadventure {
	class DynamicNumberedMenu : public Menu {
	private:
		vector<string>* selections;
		size_t lastIndex;
		bool isEmpty = true;

	public:
		DynamicNumberedMenu(const vector<string>* svPtr = new vector<string>(), string h = "", string p = "");

		bool rangeIncludes(size_t i) const;

		vector<string> getSelections() const override;
		void addSelection(string s) override;
		void addSelections(const vector<string>* sv) override;
		bool removeSelection(size_t index) override;

	};
}