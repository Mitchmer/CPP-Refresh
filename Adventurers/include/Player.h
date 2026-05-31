#pragma once
#include <string>
using std::string;

namespace cppadventure {

    class Player {
        public:
            Player();
            Player(string name, const string* inventory, int size);
            Player(Player& player);

            // name methods
            void setName(string name);
            string getName() const; // const to ensure no modifications in method

            // inventory methods
            void setInventory(const string* inventory, int size); // const string* to ensure the original inventory is not changed 
            string* getInventory() const; // const at end to ensure no modifications in method
            void printInventory() const;

            // display
            virtual void print() const = 0; // marks Player as an abstract class

            // destructor
            virtual ~Player();

        private:
            string name;
            string* inventory;
            int inventorySize;

    };
}