#pragma once
#include <string>
using std::string;

namespace cppadventure {

    class Player {
    public:
        Player();
        Player(string name, string* inventory);

    private:
        string name;
        string* inventory;
        //~Person();

    };
}