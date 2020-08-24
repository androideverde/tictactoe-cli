//
//  GameManager.cpp
//  tres_en_raya
//
//  Created by Jordi Bernabeu on 24/08/2020.
//  Copyright © 2020 Jordi Bernabeu. All rights reserved.
//

#include "GameManager.hpp"

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
            std::cout << "Gana el jugador " << player0.getName() << "!" << std::endl;
            break;
        case TicTacToe::Result::WIN_PLAYER_1:
            std::cout << "Gana el jugador " << player1.getName() << "!" << std::endl;
            break;
        case TicTacToe::Result::DRAW:
            std::cout << "Ha sido empate!" << std::endl;
            break;
        default:
            std::cout << "Unknown game state!" << std::endl;
            assert(false);
            break;
    }
    return 0;

}

void GameManager::showIntro(std::string name0, std::string name1) const {
    std::cout << "Juguemos al 3 en raya!" << std::endl;
    std::cout << "2 Jugadores: \"" << name0 << "\" y \"" << name1 << "\"" << std::endl;
}

void GameManager::showInstructions(TicTacToe game) const {
    game.drawSampleBoard();
    std::cout << "Para tirar, escribe el número de la casilla donde quieres tirar." << std::endl;
}

Player GameManager::selectStartingPlayer(Player player0, Player player1) const {
    std::cout << "Empiezas tú, " << player0.getName() << "!" << std::endl;
    return player0;
}
