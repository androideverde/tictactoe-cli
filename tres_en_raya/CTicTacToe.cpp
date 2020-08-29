//
//  TicTacToe.cpp
//  tres_en_raya
//
//  Created by Jordi Bernabeu on 29/07/2020.
//  Copyright © 2020 Jordi Bernabeu. All rights reserved.
//
#include <CTicTacToe.hpp>

#include <CAi.hpp>

#include <iostream>

CTicTacToe::CTicTacToe(CPlayer& player1, CPlayer& player2, CBoard& board)
	: m_player1(player1)
	, m_player2(player2)
	, m_board(board)
	, m_currentPlayer(&player1)
{
}

void CTicTacToe::SetNextPlayer()
{
    if (m_currentPlayer == &m_player1)
	{
        m_currentPlayer = &m_player2;
    } else {
        m_currentPlayer = &m_player1;
    }
}

bool CTicTacToe::IsMoveValid(int move) const
{
    return true;
}

void CTicTacToe::EndTurn()
{
    if (IsGameFinished())
	{
        m_isGameRunning = false;
    } else {
        SetNextPlayer();
    }
}

bool CTicTacToe::IsGameFinished()
{
    if (m_board.IsMatchForPlayer(m_player1.GetId()))
	{
        m_result = EResult::WIN_PLAYER_1;
        return true;
    }
	else if (m_board.IsMatchForPlayer(m_player2.GetId()))
	{
        m_result = EResult::WIN_PLAYER_2;
        return true;
    }
	else if (m_board.IsBoardFull())
	{
            m_result = EResult::DRAW;
            return true;
    }
	else
	{
        return false;
    }
}

void CTicTacToe::RunTurn()
{
    m_board.DrawBoard(m_player1, m_player2);
    if (m_currentPlayer->PlayTurn(m_board))
	{
        EndTurn();
    }
}
