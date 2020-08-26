//
//  HumanPlayer.hpp
//  tres_en_raya
//
//  Created by Jordi Bernabeu on 25/08/2020.
//  Copyright © 2020 Jordi Bernabeu. All rights reserved.
//
#pragma once
#include "Player.hpp"
#include "Board.hpp"

class HumanPlayer : public Player {
public:
    HumanPlayer(const char icon, const std::string& name) : Player(icon, name) {};
    bool playTurn(Board& board) const override;
};
