//
//  main.cpp
//  tres_en_raya
//
//  Created by Jordi Bernabeu on 29/07/2020.
//  Copyright © 2020 Jordi Bernabeu. All rights reserved.
//

#include <iostream>
#include "TicTacToe.hpp"

const std::string PLAYER_0 = "x";
const std::string PLAYER_1 = "o";

void showIntro() {
    std::cout << "Juguemos al 3 en raya!" << std::endl;
    std::cout << "2 Jugadores: \"" << PLAYER_0 << "\" y \"" << PLAYER_1 << "\"" << std::endl;
}

void showInstructions(TicTacToe game) {
    game.drawSampleBoard();
    std::cout << "Para tirar, escribe el número de la casilla donde quieres tirar." << std::endl;
}

int selectStartingPlayer() {
    std::cout << "Empieza el jugador " << PLAYER_0 << "!" << std::endl;
    return 0;
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
        int player = game.getCurrentPlayer();
        if (game.playTurnForPlayer(player)) {
            game.endTurn();
        }
    }
    // evaluate winner
    game.drawBoard();
    switch (game.getResult()) {
        case TicTacToe::Result::WIN_PLAYER_0:
            std::cout << "Gana el jugador " << PLAYER_0 << "!" << std::endl;
            break;
        case TicTacToe::Result::WIN_PLAYER_1:
            std::cout << "Gana el jugador " << PLAYER_1 << "!" << std::endl;
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
