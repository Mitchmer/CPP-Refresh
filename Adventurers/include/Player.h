#pragma once
import std;
using std::string, std::vector;

namespace cppadventure {

    class Player {
        public:
            Player();
            Player(string name, const vector<string>& inventory);
            Player(const Player& player);

            // name methods
            void setName(string name);
            string getName() const; // const to ensure no modifications in method

            // inventory methods
            void setInventory(const vector<string>& inventory); // const string* to ensure the original inventory is not changed 
            const vector<string>& getInventory() const; // const at end to ensure no modifications in method
            void printInventory() const;
            size_t getInventorySize() const;

            // display
            virtual void print() const = 0; // marks Player as an abstract class

            // destructor
            virtual ~Player();

        private:
            string name;
            vector<string> inventory;
            size_t inventorySize;

    };
}