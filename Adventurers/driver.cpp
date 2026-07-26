// Adventurers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

import std;
#include "Player.h"
#include "Adventurer.h"
#include "DynamicNumberedMenu.h"
#include "DynamicStringInputMenu.h"

using namespace cppadventure;
using std::cout, std::endl;

// Test declaration

void testAdventurers();
void testMenus();


constexpr size_t NAME_LENGTH = 20;
constexpr size_t ROLE_LENGTH = 12;
constexpr size_t WEAPONTYPE_LENGTH = 12;
constexpr size_t INVENTORY_LENGTH = 32;

DynamicNumberedMenu buildMainMenu();
void displayMainMenu(DynamicNumberedMenu& menu, vector<Adventurer>& adventurers);

Adventurer createAdventurerBranch();
DynamicNumberedMenu buildCreateAdventurerRoleMenu();
Role displayCreateAdventurerRoleMenu(DynamicNumberedMenu& menu);

DynamicNumberedMenu buildCreateAdventurerWeaponTypeMenu();
WeaponType displayCreateAdventurerWeaponTypeMenu(DynamicNumberedMenu& menu);

DynamicStringInputMenu buildCreateAdventurerNameMenu();
string displayCreateAdventurerNameMenu(DynamicStringInputMenu& menu);

void listAdventurersBranch(vector<Adventurer>& adventurers);


int main()
{
    vector<Adventurer> adventurers = vector<Adventurer>();
    //testAdventurers();
    DynamicNumberedMenu mainMenu = buildMainMenu();
    //mainMenu.pauseConsole();
    displayMainMenu(mainMenu, adventurers);
}


void displayMainMenu(DynamicNumberedMenu& mainMenu, vector<Adventurer>& adventurers) {
    while (mainMenu.getIsActive()) {
        mainMenu.displayMenu();
        while (!mainMenu.pauseForSelectionAndValidate()) {
            cout << mainMenu.getInvalidSelecitonMessage() << endl;
            cout << mainMenu.getPrompt();
        }
        switch (mainMenu.getInputSelection()) {
        case 1: {
            // create new adventurer
            Adventurer adventurer{ createAdventurerBranch() };
            if (!adventurer.getName().empty())
                adventurers.push_back(adventurer);
            break;
        }
        case 2: {
            // list all adventurers
            listAdventurersBranch(adventurers);
            break;
        }
        case 3: {
            mainMenu.setIsActive(false);
            break;
        }
        default:
            cout << mainMenu.getInvalidSelecitonMessage() << endl;
        }
    }
}


void listAdventurersBranch(vector<Adventurer>& adventurers) {
    using std::ios, std::string_view;

    Menu::clearConsole();
    cout << "|Name                |Role        |Weapon      |" << endl;
    cout << "|--------------------|------------|------------|" << endl;

    ios state(nullptr);
    state.copyfmt(cout);

    for (Adventurer& adventurer : adventurers) {
        cout.copyfmt(state);

        string name{ adventurer.getName() };
        string role{ Adventurer::roleToString(adventurer.getRole()) };
        string weaponType{ Adventurer::weaponTypeToString(adventurer.getWeaponType()) };

        if (!(name.size() < (NAME_LENGTH - 3))) {
            name = name.substr(0, (NAME_LENGTH - 3));
            name = name + "...";
        }
        if (!(role.size() < (ROLE_LENGTH - 3))) {
            role = role.substr(0, (ROLE_LENGTH - 3));
            role = role + "...";
        }
        if (!(weaponType.size() < (WEAPONTYPE_LENGTH - 3))) {
            weaponType = weaponType.substr(0, (WEAPONTYPE_LENGTH - 3));
            weaponType = weaponType + "...";
        }

        cout << "|"
            << std::setw(NAME_LENGTH)
            << std::setfill(' ')
            << std::left
            << name;
        cout << "|"
            << std::setw(ROLE_LENGTH)
            << std::setfill(' ')
            << std::left
            << role;
        cout << "|"
            << std::setw(WEAPONTYPE_LENGTH)
            << std::setfill(' ')
            << std::left
            << weaponType;

        cout.copyfmt(state);
        cout << "|" << endl;
    }
    cout << "Press any key to continue. . .";
    Menu::pauseConsole();
}


Adventurer createAdventurerBranch() {
    Adventurer adventurer{};
    Role role{ Role::NONE };
    WeaponType weaponType{ WeaponType::NONE };
    string name = "";

    bool complete{ false };

    DynamicNumberedMenu createAdventurerRoleMenu{ buildCreateAdventurerRoleMenu() };
    while (createAdventurerRoleMenu.getIsActive()) {
        role = displayCreateAdventurerRoleMenu(createAdventurerRoleMenu);
        if (role != Role::NONE) {
            DynamicNumberedMenu createAdventurerWeaponTypeMenu{ buildCreateAdventurerWeaponTypeMenu() };
            while (createAdventurerWeaponTypeMenu.getIsActive()) {
                weaponType = displayCreateAdventurerWeaponTypeMenu(createAdventurerWeaponTypeMenu);
                if (weaponType != WeaponType::NONE) {
                    DynamicStringInputMenu createAdventurerNameMenu{ buildCreateAdventurerNameMenu() };
                    while (createAdventurerNameMenu.getIsActive()) {
                        name = displayCreateAdventurerNameMenu(createAdventurerNameMenu);
                        if (!name.empty()) {
                            complete = true;
                            createAdventurerRoleMenu.setIsActive(false);
                            createAdventurerWeaponTypeMenu.setIsActive(false);
                        }
                        createAdventurerNameMenu.setIsActive(false);
                    }
                }
                else {
                    createAdventurerWeaponTypeMenu.setIsActive(false);
                }
            }
        }
        else {
            createAdventurerRoleMenu.setIsActive(false);
        }
        if (complete) {
            adventurer = Adventurer(name, role, weaponType);
        }
    }
    return adventurer;
}


Role displayCreateAdventurerRoleMenu(DynamicNumberedMenu& createAdventurerRoleMenu) {
    createAdventurerRoleMenu.setIsActive(true);
    Role role{ Role::NONE };

    createAdventurerRoleMenu.displayMenu();
    while (!createAdventurerRoleMenu.pauseForSelectionAndValidate()) {
        cout << createAdventurerRoleMenu.getInvalidSelecitonMessage() << endl;
        cout << createAdventurerRoleMenu.getPrompt();
    }
    switch (createAdventurerRoleMenu.getInputSelection()) {
    case 1: {
        // DPS
        role = Role::DPS;
        break;
    }
    case 2: {
        // Tank
        role = Role::TANK;
        break;
    }
    case 3:
        // Healer
        role = Role::HEALER;
        break;
    case 4:
        // back to main menu
        role = Role::NONE;
        break;
    default:
        cout << createAdventurerRoleMenu.getInvalidSelecitonMessage() << endl;
        createAdventurerRoleMenu.pauseConsole();
    }

    return role;
}


WeaponType displayCreateAdventurerWeaponTypeMenu(DynamicNumberedMenu& createAdventurerWeaponTypeMenu) {
    createAdventurerWeaponTypeMenu.setIsActive(true);
    WeaponType weaponType{ WeaponType::NONE };

        createAdventurerWeaponTypeMenu.displayMenu();
        while (!createAdventurerWeaponTypeMenu.pauseForSelectionAndValidate()) {
            cout << createAdventurerWeaponTypeMenu.getInvalidSelecitonMessage() << endl;
            cout << createAdventurerWeaponTypeMenu.getPrompt();
        }
        switch (createAdventurerWeaponTypeMenu.getInputSelection()) {
        case 1: {
            // Melee
            weaponType = WeaponType::MELEE;
            break;
        }
        case 2: {
            // Ranged
            weaponType = WeaponType::RANGED;
            break;
        }
        case 3:
            // Catalyst
            weaponType = WeaponType::CATALYST;
            break;
        case 4:
            // back to main menu
            weaponType = WeaponType::NONE;
            break;
        default:
            cout << createAdventurerWeaponTypeMenu.getInvalidSelecitonMessage() << endl;
            createAdventurerWeaponTypeMenu.pauseConsole();
        }

    return weaponType;
}


string displayCreateAdventurerNameMenu(DynamicStringInputMenu& createAdventurerNameMenu) {
    createAdventurerNameMenu.setIsActive(true);
    string weaponType{ "" };
    string input{ "" };

    createAdventurerNameMenu.displayMenu();
    while (true) {
        createAdventurerNameMenu.pauseForSelection();
        input = createAdventurerNameMenu.getInput();

        if (input.empty()) {
            cout << createAdventurerNameMenu.getInvalidSelecitonMessage() << endl;
            cout << createAdventurerNameMenu.getPrompt() << endl;
        }
        else {
            break;
        }
    }

    return input;
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


DynamicNumberedMenu buildCreateAdventurerRoleMenu() {

    DynamicNumberedMenu createAdventurerRoleMenu = DynamicNumberedMenu{
    "================ Create An Adventurer ================\nWhich role would you like for your character?",
    "Enter a selection: "
    };
    createAdventurerRoleMenu.setInvalidSelectionMessage("Invalid selection. Please choose a valid selection.");

    createAdventurerRoleMenu.addSelection("1. DPS");
    createAdventurerRoleMenu.addSelection("2. Tank");
    createAdventurerRoleMenu.addSelection("3. Healer");
    createAdventurerRoleMenu.addSelection("4. Back to Main Menu");

    return createAdventurerRoleMenu;
}


DynamicNumberedMenu buildCreateAdventurerWeaponTypeMenu() {

    DynamicNumberedMenu createAdventurerWeaponTypeMenu = DynamicNumberedMenu{
    "================ Create An Adventurer ================\nWhich weapon type will your character use?",
    "Enter a selection: "
    };
    createAdventurerWeaponTypeMenu.setInvalidSelectionMessage("Invalid selection. Please choose a valid selection.");

    createAdventurerWeaponTypeMenu.addSelection("1. Melee");
    createAdventurerWeaponTypeMenu.addSelection("2. Ranged");
    createAdventurerWeaponTypeMenu.addSelection("3. Catalyst");
    createAdventurerWeaponTypeMenu.addSelection("4. Back to Main Menu");

    return createAdventurerWeaponTypeMenu;
}


DynamicStringInputMenu buildCreateAdventurerNameMenu() {

    DynamicStringInputMenu createAdventurerNameMenu = DynamicStringInputMenu{
    "================ Create An Adventurer ================",
    "Enter a name: "
    };
    createAdventurerNameMenu.setInvalidSelectionMessage("Invalid name. Please enter at least one character.");

    return createAdventurerNameMenu;
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
