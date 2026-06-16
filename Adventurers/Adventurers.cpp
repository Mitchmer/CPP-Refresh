// Adventurers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Player.h"
#include "Adventurer.h"
#include "DynamicNumberedMenu.h"

using namespace cppadventure;
using std::cout, std::endl;

// Test declaration

void testAdventurers();
void testMenus();

DynamicNumberedMenu buildMainMenu();
void displayMainMenu(DynamicNumberedMenu& menu);

DynamicNumberedMenu buildCreateAdventurerMenu();
void displayCreateAdventurerMenu(DynamicNumberedMenu& menu);

int main()
{
    //testAdventurers();
    DynamicNumberedMenu mainMenu = buildMainMenu();
    //mainMenu.pauseConsole();
    displayMainMenu(mainMenu);
}

void displayMainMenu(DynamicNumberedMenu& mainMenu) {
    while (mainMenu.getIsActive()) {
        mainMenu.displayMenu();
        while (!mainMenu.pauseForSelectionAndValidate()) {
            cout << mainMenu.getInvalidSelecitonMessage() << endl;
            cout << mainMenu.getPrompt();
        }
        switch (mainMenu.getInputSelection()) {
        case 1: {
            // create new adventurer
            DynamicNumberedMenu createAdventurerMenu = buildCreateAdventurerMenu();
            displayCreateAdventurerMenu(createAdventurerMenu);
            break;
        }
        case 2: {
            // list all adventurers
            cout << "List all adventurers STUB" << endl;
            Menu::pauseConsole();
            break;
        }
        case 3:
            mainMenu.setIsActive(false);
            break;
        default:
            cout << mainMenu.getInvalidSelecitonMessage() << endl;
        }
    }
}

DynamicNumberedMenu buildMainMenu() {
    DynamicNumberedMenu mainMenu{
    "================ Come Join Us on an Adventure! ================",
    "Enter a selection: ",
    new vector<string>{},
    -1,
    "Invalid selection. Please choose a valid selection.",
    true
    };
    mainMenu.addSelection("1. Create a new Adventurer");
    mainMenu.addSelection("2. List all Adventurers");
    mainMenu.addSelection("3. Exit");
    return mainMenu;
}


DynamicNumberedMenu buildCreateAdventurerMenu() {
    DynamicNumberedMenu createAdventurerMenu = DynamicNumberedMenu{
    "================ Create An Adventurer ================\nPlease select a ",
    "Enter a selection: "
    };
    createAdventurerMenu.setInvalidSelectionMessage("Invalid selection. Please choose a valid selection.");

    return createAdventurerMenu;
}

void displayCreateAdventurerMenu(DynamicNumberedMenu& createAdventurerMenu) {
    createAdventurerMenu.displayMenu();
    Menu::pauseConsole();
}


// Test definition
void testAdventurers() {
    string name = "Hercules";
    vector<string> inventory = vector<string>{ "apple", "stick", "letter" };
    string invtest[] = { "1", "2" };

    cout << "Testing static array range-based for loop" << endl;
    for (string t : invtest) {
        cout << t << endl;
    }
    cout << endl;

    cout << "Creating new Adventurer Objects" << endl;
    Adventurer* player1 = new Adventurer(name, Role::HEALER, WeaponType::CATALYST, inventory);
    Adventurer* player2 = new Adventurer();

    // testing whether or not the dynamic array is preserved
    inventory = player1->getInventory();

    cout << endl << "Testing dynamic array for loop" << endl;
    for (size_t i = 0; i < player1->getInventorySize(); i++) {
        cout << inventory.at(i) << endl;   // [] auto-dereferences the pointer here
    }
    cout << endl;

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
    string header{ "----------------\nWelcome to Guild #1!\n----------------" };
    string prompt{ "Enter selection (or q to exit): " };
    
    DynamicNumberedMenu mainMenu1{ DynamicNumberedMenu(header, prompt) };
    mainMenu1.addSelection("1. Create new Adventurer");
    mainMenu1.addSelection("2. List all Adventurers");
    mainMenu1.addSelection("3. Exit");

    cout << endl;
    mainMenu1.displayMenu();

    DynamicNumberedMenu mainMenu2 = DynamicNumberedMenu(
        "----------------\nWelcome to Guild #2!\n----------------",
        "Enter selection: "
    );

    int mainMenu2Size = 3;
    vector<string>* mainMenu2SelectionVector = new vector<string>{
        "1. Create new Adventurer",
        "2. List all Adventurers",
        "3. Exit"
    };
    mainMenu2.addSelections(mainMenu2SelectionVector);

    cout << endl;
    mainMenu2.displayMenu();
    
    while (!mainMenu2.pauseForSelectionAndValidate()) {
        cout << "Invalid input. Please try again.";
    }

    cout << "test" << endl;
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
