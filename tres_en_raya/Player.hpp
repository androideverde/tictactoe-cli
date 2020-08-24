//
//  Player.hpp
//  tres_en_raya
//
//  Created by Jordi Bernabeu on 22/08/2020.
//  Copyright © 2020 Jordi Bernabeu. All rights reserved.
//
#pragma once
#include <string>

class Player {
public:
    Player()=default;
    Player(char icon, std::string name, bool ai);
    char getIcon() const {return icon;};
    bool isAi() const {return ai;};
    std::string getName() const {return name;};
    std::string setName(std::string name);
private:
    char icon;
    std::string name = "player_name";
    bool ai = false;
};
