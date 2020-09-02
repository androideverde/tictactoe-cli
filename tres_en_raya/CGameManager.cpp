//
//  GameManager.cpp
//  tres_en_raya
//
//  Created by Jordi Bernabeu on 24/08/2020.
//  Copyright © 2020 Jordi Bernabeu. All rights reserved.
//
#include <CGameManager.hpp>

#include <CTicTacToe.hpp>
#include <CBoard.hpp>
#include <CHumanPlayer.hpp>
#include <CAiPlayer.hpp>
#include <CPlayer.hpp>
#include <CAi.hpp>

int CGameManager::RunGame()
{
	CAiPlayer player1(EBoardValue::PLAYER1, 'X', "Mr X", [](CBoard& board, EBoardValue){return CAi::MakeEasyTurn(board);});
    CAiPlayer player2(EBoardValue::PLAYER2, 'O', "Bot @", CAi::MakeTurn);
    // intro
    ShowIntro(player1.GetName(), player2.GetName());
    ShowInstructions();
    // start the game loop
    CBoard board;
    CTicTacToe game(player1, player2, board);
    game.SetCurrentPlayer(SelectStartingPlayer(player1, player2));
    // wait until game loop finishes
    while (game.IsRunning())
	{
        game.RunTurn();
    }
    // evaluate winner
    board.DrawBoard(player1, player2);
    switch (game.GetResult())
	{
        case CTicTacToe::EResult::WIN_PLAYER_1:
            m_render.ShowMessage("Gana el jugador " + player1.GetName() + "!");
            break;
        case CTicTacToe::EResult::WIN_PLAYER_2:
            m_render.ShowMessage("Gana el jugador " + player2.GetName() + "!");
            break;
        case CTicTacToe::EResult::DRAW:
            m_render.ShowMessage("Ha sido empate!");
            break;
        default:
            m_render.ShowMessage("Unknown game state!");
            assert(false);
            break;
    }
    return 0;

}

void CGameManager::ShowIntro(const std::string& name1, const std::string& name2) const
{
    m_render.ShowMessage("Juguemos al 3 en raya!");
    m_render.ShowMessage("2 Jugadores: \"" + name1 + "\" y \"" + name2 + "\"");
}

void CGameManager::ShowInstructions() const
{
    m_render.DrawSampleBoard();
    m_render.ShowMessage("Para tirar, escribe el número de la casilla donde quieres tirar.");
}

const CPlayer* CGameManager::SelectStartingPlayer(CPlayer& player1, CPlayer& player2) const
{
    m_render.ShowMessage("Empiezas tú, " + player1.GetName() + "!");
    return &player1;
}
