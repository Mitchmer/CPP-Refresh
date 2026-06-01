#pragma once
#include <string>

using std::string;

namespace cppadventure {
	class Menu {
	private:
		string header;

	public:
		Menu(string b = "default header");

		string getHeader() const;

		virtual string getPrompt() const = 0;
		virtual void displayMenu() const = 0;
	};
}