#include "Player.h"
#include <string>
#include <iostream>

using namespace cppadventure;
using std::string;
using std::cout, std::endl;

//=================================
// Constructors

Player::Player()
	: name("testname"), inventory(vector<string>{}), inventorySize(0) {}

Player::Player(string n, const vector<string>& inv) 
	: name(n), inventory(inv), inventorySize(inv.size()) {}

// copy constructor
Player::Player(const Player& player) 
	: name(player.getName()), inventorySize(player.getInventorySize()), inventory(player.getInventory()) {}

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

void Player::setInventory(const vector<string>& newInventory) { // const string* to ensure the original inventory is not changed 
	
	// if there is already an inventory, delete it
	if (getInventory().size() > 0) {
		inventory.clear();
		inventorySize = 0;
	}

	// copy each item to the new inventory
	for (string item : newInventory) {
		inventory.push_back(item);
	}

	inventorySize = newInventory.size();
}

const vector<string>& Player::getInventory() const {
	return inventory;
}

size_t Player::getInventorySize() const {
	return inventorySize;
}

void Player::printInventory() const {
	vector<string> inv = getInventory();
		cout << "Inventory: [";

		if (inv.size() > 0) {
			for (size_t i = 0; i < inventorySize; i++) {
				cout << inv.at(i);
				if (i < (inventorySize - 1)) {
					cout << ", ";
				}
			}
		}
		else {
			cout << "Empty";
		}
	
		cout << "]" << std::endl;
}

//===================================
// Destructor

Player::~Player() {
	cout << "Player (Parent) Destructor called" << endl;
}
