//
//  Board.cpp
//  tres_en_raya
//
//  Created by Jordi Bernabeu on 24/08/2020.
//  Copyright © 2020 Jordi Bernabeu. All rights reserved.
//
#include <CBoard.hpp>

#include <CRenderer.hpp>
#include <CPlayer.hpp>

#include <sstream>

namespace CBoardInternal {
const std::vector<std::vector<int>> MATCHES =
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
const std::vector<std::vector<int>> ALMOST_MATCHES =
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
}

CBoard::CBoard()
{
    for (int i = 0; i < 9; i++)
	{
        m_boardState.push_back(EBoardValue::EMPTY);
    }
}

bool CBoard::DoMove(int position, EBoardValue playerId)
{
    if (IsAvailableSlot(position))
	{
        m_boardState[position] = playerId;
        return true;
    }
    return false;
}

bool CBoard::IsMatchForPlayer(EBoardValue playerId) const
{
    for (const std::vector<int>& match : CBoardInternal::MATCHES)
	{
        if (m_boardState[match[0]] == playerId
			&& m_boardState[match[1]] == playerId
			&& m_boardState[match[2]] == playerId)
		{
            return true;
        }
    }
    return false;
}

std::map<EBoardValue, std::set<int>> CBoard::MapAlmostMatchSlots() const
{
	std::map<EBoardValue, std::set<int>> result;
	for (EBoardValue player : {EBoardValue::PLAYER1, EBoardValue::PLAYER2}) {
		std::set<int> slotsForMatch;
		for (const std::vector<int>& match : CBoardInternal::ALMOST_MATCHES)
		{
			if (m_boardState[match[0]] == player
				&& m_boardState[match[1]] == player
				&& m_boardState[match[2]] == EBoardValue::EMPTY)
			{
				slotsForMatch.insert(match[2]);
			}
		}
		result[player] = slotsForMatch;
	}
    return result;
}

bool CBoard::IsBoardFull() const
{
    int count = 0;
    for (EBoardValue value : m_boardState)
	{
        if (value != EBoardValue::EMPTY)
		{
            count++;
        }
    }
    if (count == 9)
	{
        return true;
    }
	else
	{
        return false;
    }
}

void CBoard::DrawBoard(const CPlayer& player1, const CPlayer& player2) const
{
    CRenderer render = CRenderer();
    std::vector<std::string> board;
    std::string newValue;
    std::map<EBoardValue, std::string> valueToString =
	{
        {EBoardValue::EMPTY, " "},
        {player1.GetId(), std::string(1, player1.GetIcon())},
        {player2.GetId(), std::string(1, player2.GetIcon())}
    };
    for (EBoardValue value : m_boardState)
	{
        board.push_back(valueToString[value]);
    }
    render.DrawBoard(board);
}

bool CBoard::IsAvailableSlot(int position) const
{
    if (m_boardState[position] == EBoardValue::EMPTY)
	{
        return true;
    }
    return false;
}

std::vector<int> CBoard::ListAvailableSlots() const
{
    std::vector<int> available;
    int index = 0;
    for (EBoardValue value : m_boardState)
	{
        if (value == EBoardValue::EMPTY)
		{
            available.push_back(index);
        }
        index++;
    }
    return available;
}
