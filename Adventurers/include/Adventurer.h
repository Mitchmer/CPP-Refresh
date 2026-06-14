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
			Adventurer(string name, const vector<string>& inv, Role role, WeaponType weaponType);

			//==================================
			// Getters

			Role getRole() const;
			WeaponType getWeaponType() const;

			//==================================
			// Display

			void print() const;

			//==================================
			// Destructor

			~Adventurer();

		private:

			//==================================
			// Member attributes

			Role role;
			WeaponType weaponType;

			//==================================
			// Static methods

			static string roleToString(Role r);
			static string weaponTypeToString(WeaponType wt);
	};
}