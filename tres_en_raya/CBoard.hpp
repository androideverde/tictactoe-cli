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
class CPlayer;

enum class EBoardValue
{
    EMPTY,
    PLAYER1,
    PLAYER2
};

class CBoard
{
public:
    CBoard();
    bool DoMove(int position, EBoardValue playerId);
    bool IsAvailableSlot(int position) const;
    bool IsMatchForPlayer(EBoardValue playerId) const;
    bool IsAlmostMatchForPlayer(const CPlayer& player) const;
    bool IsBoardFull() const;
    void DrawBoard(const CPlayer& player1, const CPlayer& player2) const;
    std::vector<int> ListAvailableSlots() const;
    std::vector<int> ListAlmostMatchSlotsForPlayer(const CPlayer& player) const;
private:
    std::vector<EBoardValue> m_boardState;
};
