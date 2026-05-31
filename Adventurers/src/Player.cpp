#include "Player.h"
#include <string>
#include <iostream>

using namespace cppadventure;
using std::string;
using std::cout, std::endl;

//=================================
// Constructors

Player::Player()
	: name("testname"), inventory(nullptr), inventorySize(0) {
	cout << "Player (Parent) Default Constructor called" << std::endl;
}

Player::Player(string name, const string* inventory, int size) {
	cout << "Player (Parent) Parameterized Constructor called" << std::endl;
	setName(name);
	setInventory(inventory, size);
}

// copy constructor
Player::Player(Player& player) 
	: name(player.getName()), inventorySize(player.inventorySize), inventory(player.getInventory()) {}

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

string* Player::getInventory() const { // const string* to ensure object's inventory not changed, const at end to ensure no modifications in method
	string* invCopy = new string[inventorySize];
	for (int i = 0; i < inventorySize; i++) {
		invCopy[i] = inventory[i];
	}
	return invCopy; // returns a deep copy of the inventory
}

void Player::printInventory() const {
	const string* inv = getInventory();
		cout << "Inventory: [";

		if (inv != nullptr) {
			for (int i = 0; i < inventorySize; i++) {
				cout << inv[i];
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

	if (inventory != nullptr) {
		delete[] inventory;
	}
}
