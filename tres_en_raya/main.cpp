//
//  main.cpp
//  tres_en_raya
//
//  Created by Jordi Bernabeu on 29/07/2020.
//  Copyright © 2020 Jordi Bernabeu. All rights reserved.
//

#include <iostream>
#include "TicTacToe.hpp"
#include "Player.hpp"

Player* const PLAYER_0 = new Player('x', "Jugador x", false);
Player* const PLAYER_1 = new Player('@', "Bot @", true);

void showIntro() {
    std::cout << "Juguemos al 3 en raya!" << std::endl;
    std::cout << "2 Jugadores: \"" << PLAYER_0->getName() << "\" y \"" << PLAYER_1->getName() << "\"" << std::endl;
}

void showInstructions(TicTacToe game) {
    game.drawSampleBoard();
    std::cout << "Para tirar, escribe el número de la casilla donde quieres tirar." << std::endl;
}

Player* selectStartingPlayer() {
    std::cout << "Empiezas tú, " << PLAYER_0->getName() << "!" << std::endl;
    return PLAYER_0;
}

int main(int argc, const char * argv[]) {
    // intro
    showIntro();
    // start the game loop
    TicTacToe game = TicTacToe(PLAYER_0, PLAYER_1);
    showInstructions(game);
    game.setCurrentPlayer(selectStartingPlayer());
    // wait until game loop finishes
    while (game.isRunning()) {
        game.drawBoard();
        Player* const player = game.getCurrentPlayer();
        if (game.playTurnForPlayer(player)) {
            game.endTurn();
        }
    }
    // evaluate winner
    game.drawBoard();
    switch (game.getResult()) {
        case TicTacToe::Result::WIN_PLAYER_0:
            std::cout << "Gana el jugador " << PLAYER_0->getName() << "!" << std::endl;
            break;
        case TicTacToe::Result::WIN_PLAYER_1:
            std::cout << "Gana el jugador " << PLAYER_1->getName() << "!" << std::endl;
            break;
        case TicTacToe::Result::DRAW:
            std::cout << "Ha sido empate!" << std::endl;
            break;
        default:
            std::cout << "Unknown game state!" << std::endl;
            break;
    }
    return 0;
}
