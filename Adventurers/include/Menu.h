#pragma once
import std;

using std::string, std::vector;

namespace cppadventure {
	class Menu {
	public:

		Menu(string h = "default header", string p = "", string iSel = "", bool d = true);

		static void clearConsole();
		static void pauseConsole();

		string getHeader() const;

		void setPrompt(string s);
		string getPrompt() const;

		void setInvalidSelectionMessage(string s);
		string getInvalidSelecitonMessage() const;

		void setIsActive(bool d);
		bool getIsActive() const;

		virtual vector<string> getSelections() const = 0;

		// s is a new selection to add
		virtual void addSelection(string s) = 0;
		virtual void addSelections(const vector<string>* sv) = 0;
		virtual bool removeSelection(size_t index) = 0;

		virtual void displayMenu() const = 0;

		virtual ~Menu();

	private:
		string header;
		string prompt;
		string invalidSelectionMessage;
		bool isActive;
		Menu* child = nullptr;
	};
}