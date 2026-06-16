#include "Item.h"

using namespace cppadventure;

Item::Item(string_view name) : name_(name) {}

string Item::getName() const {
	return name_;
}