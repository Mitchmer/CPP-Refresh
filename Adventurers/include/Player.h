#pragma once
#include <string>
using std::string;

namespace cppadventure {

    class Player {
    public:
        Player();
        Player(string name, const string* inventory, int size);

        // name methods
        void setName(string name);
        string getName() const; // const to ensure no modifications in method

        // inventory methods
        void setInventory(const string* inventory, int size); // const string* to ensure the original inventory is not changed 
        const string* getInventory() const; // const string* to ensure object's inventory not changed, const at end to ensure no modifications in method

    private:
        string name;
        string* inventory;
        int inventorySize;
        //~Person();

    };
}