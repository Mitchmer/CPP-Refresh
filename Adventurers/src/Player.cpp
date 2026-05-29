#include "Player.h"

using namespace cppadventure;

//=================================
// Constructors

Player::Player() {
   name = "testname";
   inventory = nullptr;
}

Player::Player(string name, string* inventory) {
    Player::name = name;
    Player::inventory = inventory;
}

