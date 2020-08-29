//
//  TicTacToe.hpp
//  tres_en_raya
//
//  Created by Jordi Bernabeu on 29/07/2020.
//  Copyright © 2020 Jordi Bernabeu. All rights reserved.
//
#pragma once

#include <CPlayer.hpp>
#include <CRenderer.hpp>
#include <CBoard.hpp>

#include <vector>
#include <string>

class CTicTacToe
{
public:
    enum class EResult
	{
        WIN_PLAYER_1,
        WIN_PLAYER_2,
        DRAW
    };
    CTicTacToe(CPlayer& player1, CPlayer& player2, CBoard& board);
	
    bool IsRunning() const { return m_isGameRunning; }
    void SetCurrentPlayer(const CPlayer* player) { m_currentPlayer = player; }
    const CPlayer* GetCurrentPlayer() const { return m_currentPlayer; }
    void SetNextPlayer();
    CTicTacToe::EResult GetResult() const { return m_result; }
    void EndTurn();
    bool IsGameFinished();
    void RunTurn();

private:
    CBoard& m_board;
    CPlayer& m_player1;
    CPlayer& m_player2;
    const CPlayer* m_currentPlayer;
    bool m_isGameRunning = true;
    CTicTacToe::EResult m_result;
    bool IsMoveValid(int move) const;
    CRenderer m_render = CRenderer();
};
