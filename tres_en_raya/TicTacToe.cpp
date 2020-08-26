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

TicTacToe::TicTacToe(Player& player1, Player& player2, Board& board) : player1(player1), player2(player2), board(board), currentPlayer(&player1) {
}

void TicTacToe::setNextPlayer() {
    if (currentPlayer == &player1) {
        currentPlayer = &player2;
    } else {
        currentPlayer = &player1;
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
    if (board.isMatchForPlayer(player1.getId())) {
        result = Result::WIN_PLAYER_1;
        return true;
    } else if (board.isMatchForPlayer(player2.getId())) {
        result = Result::WIN_PLAYER_2;
        return true;
    } else if (board.isBoardFull()) {
            result = Result::DRAW;
            return true;
    } else {
        return false;
    }
}

void TicTacToe::runTurn() {
    board.drawBoard(player1, player2);
    if (currentPlayer->playTurn(board)) {
        endTurn();
    }
}
