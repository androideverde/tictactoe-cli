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
    for (std::vector<int> match : m_matches)
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
		for (std::vector<int> match : m_almostMatches)
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
