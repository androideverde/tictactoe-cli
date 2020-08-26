//
//  GameManager.cpp
//  tres_en_raya
//
//  Created by Jordi Bernabeu on 24/08/2020.
//  Copyright © 2020 Jordi Bernabeu. All rights reserved.
//

#include "GameManager.hpp"
#include "TicTacToe.hpp"
#include "Board.hpp"
#include "HumanPlayer.hpp"
#include "AiPlayer.hpp"
#include "Player.hpp"

int GameManager::runGame() {
    HumanPlayer player1(1, 'x', "Jugador x");
    AiPlayer player2(2, '@', "Bot @");
    // intro
    showIntro(player1.getName(), player2.getName());
    showInstructions();
    // start the game loop
    Board board;
    TicTacToe game(player1, player2, board);
    game.setCurrentPlayer(selectStartingPlayer(player1, player2));
    // wait until game loop finishes
    while (game.isRunning()) {
        game.runTurn();
    }
    // evaluate winner
    board.drawBoard(player1, player2);
    switch (game.getResult()) {
        case TicTacToe::Result::WIN_PLAYER_1:
            render.showMessage("Gana el jugador " + player1.getName() + "!");
            break;
        case TicTacToe::Result::WIN_PLAYER_2:
            render.showMessage("Gana el jugador " + player2.getName() + "!");
            break;
        case TicTacToe::Result::DRAW:
            render.showMessage("Ha sido empate!");
            break;
        default:
            render.showMessage("Unknown game state!");
            assert(false);
            break;
    }
    return 0;

}

void GameManager::showIntro(const std::string& name1, const std::string& name2) const {
    render.showMessage("Juguemos al 3 en raya!");
    render.showMessage("2 Jugadores: \"" + name1 + "\" y \"" + name2 + "\"");
}

void GameManager::showInstructions() const {
    render.drawSampleBoard();
    render.showMessage("Para tirar, escribe el número de la casilla donde quieres tirar.");
}

const Player* GameManager::selectStartingPlayer(Player& player1, Player& player2) const {
    render.showMessage("Empiezas tú, " + player1.getName() + "!");
    return &player1;
}
