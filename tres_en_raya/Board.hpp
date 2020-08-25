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
#include "Player.hpp"

class Board {
public:
    Board();
    void reset();
    bool doMove(const int position, const Player& player);
    bool isAvailableSlot(const int position) const;
    bool isMatchForPlayer(const Player& player) const;
    bool isAlmostMatchForPlayer(const Player& player) const;
    bool isBoardFull(const Player& player0, const Player& player1) const;
    void drawBoard() const;
    std::vector<int> listAvailableSlots() const;
    std::vector<int> listAlmostMatchSlotsForPlayer(const Player& player) const;
private:
    std::vector<std::string> boardState;
    bool isMovePossible(const int move) const;
    int convertToInt(const char icon) const;
};
