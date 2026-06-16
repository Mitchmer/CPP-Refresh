#pragma once

#include<string>
using std::string_view, std::string;

namespace cppadventure {
	class Item {
	public:
		Item(string_view name = NONAME);
		string getName() const;

	private:
		string name_;

		static constexpr string_view NONAME = "NONAME";
	};
}