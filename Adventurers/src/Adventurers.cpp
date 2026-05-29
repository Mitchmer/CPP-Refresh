// Adventurers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Player.h"

using namespace cppadventure;

int main()
{
    string name = "Hercules";
    const int invsize = 3;
    string* inventory = new string[]{"apple", "stick", "letter"};

    Player* player1 = new Player(name, inventory, 3);
    delete[] inventory; // could remove if inventory was created without the 'new' keyword

    const string* playerInventory = (*player1).getInventory();

    for (int i = 0; i < invsize; i++) {
        std::cout << playerInventory[i] << std::endl;   // [] auto-dereferences the pointer here
    }

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
