#pragma once

#include "Player.h"
#include "WeaponType.h"
#include "Role.h"

namespace cppadventure {
	class Adventurer : public Player {
		public:

			//=================================
			// Constructors

			Adventurer(Role r = Role::DPS, WeaponType wt = WeaponType::MELEE); // default parameters also takes care of default constructor
			Adventurer(string name, Role role, WeaponType weaponType, const vector<string>& inventory = vector<string>{});
			Adventurer(const Adventurer&);

			//==================================
			// Getters

			Role getRole() const;
			WeaponType getWeaponType() const;

			//==================================
			// Display

			void print() const;

			//==================================
			// Static methods

			static string roleToString(Role r);
			static string weaponTypeToString(WeaponType wt);

			//==================================
			// Destructor

			~Adventurer();

		private:

			//==================================
			// Member attributes

			Role role;
			WeaponType weaponType;
	};
}