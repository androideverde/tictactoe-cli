//
//  GameManager.cpp
//  tres_en_raya
//
//  Created by Jordi Bernabeu on 24/08/2020.
//  Copyright © 2020 Jordi Bernabeu. All rights reserved.
//

#include "GameManager.hpp"
#include "Renderer.hpp"

int GameManager::runGame() {
    Player player0 = Player('x', "Jugador x", false);
    Player player1 = Player('@', "Bot @", true);
    // intro
    showIntro(player0.getName(), player1.getName());
    // start the game loop
    TicTacToe game = TicTacToe(player0, player1);
    showInstructions(game);
    game.setCurrentPlayer(selectStartingPlayer(player0, player1));
    // wait until game loop finishes
    Player currentPlayer;
    while (game.isRunning()) {
        game.drawBoard();
        currentPlayer = game.getCurrentPlayer();
        if (game.playTurnForPlayer(currentPlayer)) {
            game.endTurn();
        }
    }
    // evaluate winner
    game.drawBoard();
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

void GameManager::showInstructions(TicTacToe game) const {
    render.drawSampleBoard();
    render.showMessage("Para tirar, escribe el número de la casilla donde quieres tirar.");
}

Player GameManager::selectStartingPlayer(Player player0, Player player1) const {
    render.showMessage("Empiezas tú, " + player0.getName() + "!");
    return player0;
}
