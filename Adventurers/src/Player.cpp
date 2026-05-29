#include "Player.h"
#include <string>

using namespace cppadventure;
using std::string;

//=================================
// Constructors

Player::Player() {
   name = "testname";
   inventory = nullptr;
   inventorySize = 0;
}

Player::Player(string name, const string* inventory, int size) {
	setName(name);
	setInventory(inventory, size);
}

//=================================
// name methods

void Player::setName(string n) {
	name = n;
}

string Player::getName() const { // const to ensure no modifications in method
	return name;
} 

//=================================
// inventory methods

void Player::setInventory(const string* inv, int size) { // const string* to ensure the original inventory is not changed 
	
	// if there is already an inventory, delete it
	if (getInventory() != nullptr) {
		delete[] inventory;
	}
	inventory = new string[size]; // allocate new memory for inventory

	// copy each item to the new inventory
	for (int i = 0; i < size; i++) {
		inventory[i] = inv[i];
	}

	// update the new size;
	inventorySize = size;
}

const string* Player::getInventory() const { // const string* to ensure object's inventory not changed, const at end to ensure no modifications in method
	return inventory;
}

