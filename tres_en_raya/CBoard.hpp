//
//  Board.hpp
//  tres_en_raya
//
//  Created by Jordi Bernabeu on 24/08/2020.
//  Copyright © 2020 Jordi Bernabeu. All rights reserved.
//
#pragma once

#include <vector>
#include <set>
#include <map>

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
    bool IsBoardFull() const;
    void DrawBoard(const CPlayer& player1, const CPlayer& player2) const;
    std::vector<int> ListAvailableSlots() const;
	std::map<EBoardValue, std::set<int>> MapAlmostMatchSlots() const;
private:
    std::vector<EBoardValue> m_boardState;
    std::vector<std::vector<int>> m_matches =
	{
        // rows
        {0, 1, 2},
        {3, 4, 5},
        {6, 7, 8},
        // columns
        {0, 3, 6},
        {1, 4, 7},
        {2, 5, 8},
        // diagonals
        {0, 4, 8},
        {2, 4, 6}
    };
	std::vector<std::vector<int>> m_almostMatches =
	{
        // rows
		{0, 1, 2}, {0, 2, 1}, {1, 2, 0},
		{3, 4, 5}, {3, 5, 4}, {4, 5, 3},
		{6, 7, 8}, {6, 8, 7}, {7, 8, 6},
        // columns
		{0, 3, 6}, {0, 6, 3}, {3, 6, 0},
		{1, 4, 7}, {1, 7, 4}, {4, 7, 1},
		{2, 5, 8}, {2, 8, 5}, {5, 8, 2},
        // diagonals
		{0, 4, 8}, {0, 8, 4}, {4, 8, 0},
		{2, 4, 6}, {2, 6, 4}, {4, 6, 2}
    };
	std::set<int> m_slotsForMatch;
};
