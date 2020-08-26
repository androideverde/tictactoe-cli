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

TicTacToe::TicTacToe(Player& player0, Player& player1, Board& board) : player0(player0), player1(player1), board(board), currentPlayer(&player0) {
}

void TicTacToe::setNextPlayer() {
    if (currentPlayer == &player0) {
        currentPlayer = &player1;
    } else {
        currentPlayer = &player0;
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
    if (board.isMatchForPlayer(player0)) {
        result = Result::WIN_PLAYER_0;
        return true;
    } else if (board.isMatchForPlayer(player1)) {
        result = Result::WIN_PLAYER_1;
        return true;
    } else if (board.isBoardFull(player0, player1)) {
            result = Result::DRAW;
            return true;
    } else {
        return false;
    }
}

void TicTacToe::runTurn() {
    board.drawBoard();
    if (currentPlayer->playTurn(board)) {
        endTurn();
    }
}
