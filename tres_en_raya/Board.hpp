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

enum class BoardValue {
    EMPTY,
    PLAYER1,
    PLAYER2
};

class Board {
public:
    Board();
    bool doMove(int position, BoardValue playerId);
    bool isAvailableSlot(int position) const;
    bool isMatchForPlayer(BoardValue playerId) const;
    bool isAlmostMatchForPlayer(const Player& player) const;
    bool isBoardFull() const;
    void drawBoard(const Player& player1, const Player& player2) const;
    std::vector<int> listAvailableSlots() const;
    std::vector<int> listAlmostMatchSlotsForPlayer(const Player& player) const;
private:
    std::vector<BoardValue> boardState;
};
