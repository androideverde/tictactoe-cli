//
//  GameManager.cpp
//  tres_en_raya
//
//  Created by Jordi Bernabeu on 24/08/2020.
//  Copyright © 2020 Jordi Bernabeu. All rights reserved.
//

#include "GameManager.hpp"
#include "Renderer.hpp"
#include "Board.hpp"

int GameManager::runGame() {
    Player player0 = Player('x', "Jugador x", false);
    Player player1 = Player('@', "Bot @", true);
    // intro
    showIntro(player0.getName(), player1.getName());
    showInstructions();
    // start the game loop
    Board board = Board();
    TicTacToe game = TicTacToe(player0, player1, board);
    game.setCurrentPlayer(selectStartingPlayer(player0, player1));
    // wait until game loop finishes
    Player currentPlayer;
    while (game.isRunning()) {
        board.drawBoard();
        currentPlayer = game.getCurrentPlayer();
        if (game.playTurnForPlayer(currentPlayer)) {
            game.endTurn();
        }
    }
    // evaluate winner
    board.drawBoard();
    switch (game.getResult()) {
        case TicTacToe::Result::WIN_PLAYER_0:
            render.showMessage("Gana el jugador " + player0.getName() + "!");
            break;
        case TicTacToe::Result::WIN_PLAYER_1:
            render.showMessage("Gana el jugador " + player1.getName() + "!");
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

void GameManager::showIntro(std::string name0, std::string name1) const {
    render.showMessage("Juguemos al 3 en raya!");
    render.showMessage("2 Jugadores: \"" + name0 + "\" y \"" + name1 + "\"");
}

void GameManager::showInstructions() const {
    render.drawSampleBoard();
    render.showMessage("Para tirar, escribe el número de la casilla donde quieres tirar.");
}

Player GameManager::selectStartingPlayer(const Player& player0, const Player& player1) const {
    render.showMessage("Empiezas tú, " + player0.getName() + "!");
    return player0;
}
