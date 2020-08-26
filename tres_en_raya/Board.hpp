//
//  Board.hpp
//  tres_en_raya
//
//  Created by Jordi Bernabeu on 24/08/2020.
//  Copyright © 2020 Jordi Bernabeu. All rights reserved.
//
#pragma once
#include <vector>
#include <string>
//#include "Player.hpp"
class Player;

class Board {
public:
    Board();
    bool doMove(int position, int playerId);
    bool isAvailableSlot(int position) const;
    bool isMatchForPlayer(int playerId) const;
    bool isAlmostMatchForPlayer(const Player& player) const;
    bool isBoardFull() const;
    void drawBoard(const Player& player0, const Player& player1) const;
    std::vector<int> listAvailableSlots() const;
    std::vector<int> listAlmostMatchSlotsForPlayer(const Player& player) const;
private:
    std::vector<int> boardState;
};
