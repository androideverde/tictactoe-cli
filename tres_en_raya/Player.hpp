//
//  Player.hpp
//  tres_en_raya
//
//  Created by Jordi Bernabeu on 22/08/2020.
//  Copyright © 2020 Jordi Bernabeu. All rights reserved.
//
#pragma once
#include <string>
#include "Board.hpp"

class Player {
public:
    Player(const int id, const char icon, const std::string& name);
    int getId() const {return id;};
    char getIcon() const {return icon;};
    std::string getName() const {return name;};
    std::string setName(const std::string& name);
    virtual bool playTurn(Board& board) const = 0;
protected:
    int id;
    char icon;
    std::string name = "player_name";
};
