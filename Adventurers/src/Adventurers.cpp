// Adventurers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Player.h"
#include "Adventurer.h"
#include "Menu.h"

using namespace cppadventure;
using std::cout, std::endl;

// Test declaration
void testAdventurers();
void testMenus();

int main()
{
    testAdventurers();
    testMenus();
}

// Test definition
void testAdventurers() {
    string name = "Hercules";
    const int invsize = 3;
    const string* inventory = new string[]{ "apple", "stick", "letter" };
    string invtest[] = { "1", "2" };

    cout << "Testing static array range-based for loop" << endl;
    for (string t : invtest) {
        cout << t << endl;
    }
    cout << endl;

    cout << "Creating new Adventurer Objects" << endl;
    Adventurer* player1 = new Adventurer(name, inventory, invsize, Role::HEALER, WeaponType::CATALYST);
    Adventurer* player2 = new Adventurer();
    delete[] inventory; // could remove if inventory was created without the 'new' keyword

    // testing whether or not the dynamic array is preserved
    inventory = (*player1).getInventory();

    cout << endl << "Testing dynamic array for loop" << endl;
    for (int i = 0; i < invsize; i++) {
        cout << inventory[i] << endl;   // [] auto-dereferences the pointer here
    }
    cout << endl;

    delete[] inventory;
    inventory = nullptr; // reset dangling pointer

    cout << "Testing Player print methods" << endl;
    cout << "Player 1:" << endl;
    player1->print();
    player1->printInventory();
    cout << endl << endl;

    cout << "Player 2:" << endl;
    player2->print();
    player2->printInventory();
    cout << endl;

    // fails if inventory above is a shallow copy
    delete player1;
    delete player2;
}

void testMenus() {
    Menu mainMenu = Menu(
        "----------------\nWelcome to the Guild!\n----------------",
        "Enter selection (or q to exit): "
    );
    mainMenu.addSelection("1. Create new Adventurer", false);
    mainMenu.addSelection("2. List all Adventurers", false);
    mainMenu.addSelection("3. Exit", true);

    cout << endl;
    mainMenu.displayMenu();

    Menu mainMenu2 = Menu(
        "----------------\nWelcome to the Guild!\n----------------",
        "Enter selection (or q to exit): "
    );

    int mainMenu2Size = 3;
    string mainMenu2SelectionArray[] = {
        "1. Create new Adventurer",
        "2. List all Adventurers",
        "3. Exit"
    };
    mainMenu2.addSelections(mainMenu2SelectionArray, mainMenu2Size);

    cout << endl;
    mainMenu2.displayMenu();
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
