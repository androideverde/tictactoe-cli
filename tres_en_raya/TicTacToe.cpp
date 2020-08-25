//
//  TicTacToe.cpp
//  tres_en_raya
//
//  Created by Jordi Bernabeu on 29/07/2020.
//  Copyright © 2020 Jordi Bernabeu. All rights reserved.
//

#include <iostream>
#include "TicTacToe.hpp"
#include "Ai.hpp"

TicTacToe::TicTacToe(const Player& player0, const Player& player1, Board& board) : PLAYER_0(player0), PLAYER_1(player1), board(board) {

}

void TicTacToe::setNextPlayer() {
    if (currentPlayer.getIcon() == PLAYER_0.getIcon()) {
        currentPlayer = PLAYER_1;
    } else {
        currentPlayer = PLAYER_0;
    }
}

bool TicTacToe::playTurnForPlayer(const Player& player) {
    render.showMessage("Te toca, " + player.getName());
    if (player.isAi()) {
        int aiMove = Ai::makeTurn(board);
        render.showMessage(player.getName() + " tira en: " + std::to_string(aiMove+1));
        if (board.doMove(aiMove, player.getIcon())) {
            return true;
        } else {
            render.showMessage("No move done!");
            return false;
        }
    } else {
        int move;
        std::cin >> move;
        if (isMoveValid(move-1)) {
            if (board.doMove(move-1, player.getIcon())) {
                return true;
            } else {
                render.showMessage("Movimiento no válido!");
            }
        }
        return false;
    }
}

bool TicTacToe::isMoveValid(int move) const {
    return true;
}

void TicTacToe::endTurn() {
    if (isGameFinished()) {
        isGameRunning = false;
    } else {
        setNextPlayer();
    }
}

bool TicTacToe::isGameFinished() {
    if (board.isMatchForPlayer(PLAYER_0)) {
        result = Result::WIN_PLAYER_0;
        return true;
    } else if (board.isMatchForPlayer(PLAYER_1)) {
        result = Result::WIN_PLAYER_1;
        return true;
    } else if (board.isBoardFull(PLAYER_0, PLAYER_1)) {
            result = Result::DRAW;
            return true;
    } else {
        return false;
    }
}
