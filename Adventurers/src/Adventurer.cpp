#include "Adventurer.h"
#include <iostream>

using namespace cppadventure;
using std::cout, std::endl;

Adventurer::Adventurer(Role r, WeaponType wt){

	cout << "Adventurer (Child) Default Constructor called" << endl;
	role = r;
	weaponType = wt;
}

Adventurer::Adventurer(string n, Role r, WeaponType wt, const vector<string>& inv) 
	: Player(n, inv) {
	cout << "Adventurer (Child) Parameterized Constructor called" << endl;
	role = r;
	weaponType = wt;
}

// Copy Constructor
Adventurer::Adventurer(const Adventurer& adventurer) :
	role(adventurer.getRole()), weaponType(adventurer.getWeaponType()), Player(adventurer.getName(), adventurer.getInventory()) {
}

//==================================
// Destructor

Adventurer::~Adventurer() {
	cout << "Adventurer (Child) Destructor called" << endl;
}

Role Adventurer::getRole() const {
	return role;
}

WeaponType Adventurer::getWeaponType() const {
	return weaponType;
}

//==================================
//	Display

void Adventurer::print() const {
	cout << "Name: " << getName() << endl
		<< "Role: " << roleToString(getRole()) << endl
		<< "Weapon Type: " << weaponTypeToString(getWeaponType()) << endl;
}

//==================================
// Static methods

// Returns a string based on the given WeaponType
string Adventurer::weaponTypeToString(WeaponType wt) {
	string wtString = "";
	switch (wt)
	{
		case cppadventure::WeaponType::MELEE:
			wtString = "Melee";
			break;
		case cppadventure::WeaponType::RANGED:
			wtString = "Ranged";
			break;
		case cppadventure::WeaponType::CATALYST:
			wtString = "Catalyst";
			break;
		default:
			wtString = "Invalid WeaponType";
			break;
	}
	return wtString;
}

// returns a string based on a given Role
string Adventurer::roleToString(Role r) {
	string rString = "";
	switch (r)
	{
		case cppadventure::Role::DPS:
			rString = "DPS";
			break;
		case cppadventure::Role::TANK:
			rString = "Tank";
 			break;
		case cppadventure::Role::HEALER:
			rString = "Healer";
			break;
		default:
			rString = "Invalid Role";
			break;
	}
	return rString;
}