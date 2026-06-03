#pragma once
#include <string>
#include <vector>

using std::string, std::vector;

namespace cppadventure {
	class Menu {
	private:
		string header;
		string prompt;

	public:
		Menu(string h = "default header", string p = "");

		string getHeader() const;

		void setPrompt(string s);
		string getPrompt() const;

		virtual vector<string> getSelections() const = 0;

		// s is a new selection to add
		virtual void addSelection(string s) = 0;
		virtual void addSelections(const vector<string>* sv) = 0;

		virtual bool removeSelection(size_t index) = 0;

		virtual void displayMenu() const = 0;

		virtual ~Menu();
	};
}