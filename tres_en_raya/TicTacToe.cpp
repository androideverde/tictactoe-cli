//
//  TicTacToe.cpp
//  tres_en_raya
//
//  Created by Jordi Bernabeu on 29/07/2020.
//  Copyright © 2020 Jordi Bernabeu. All rights reserved.
//

#include <iostream>
#include <string>
#include "TicTacToe.hpp"

TicTacToe::TicTacToe(std::string player0, std::string player1) {
    size_t size = 9;
    std::vector<std::string> board(size);
    for (int i=1; i<10; i++) {
        board[i-1] = std::to_string(i);
    }
    TicTacToe::boardState = board;
    TicTacToe::PLAYER_0 = player0;
    TicTacToe::PLAYER_1 = player1;
}

bool TicTacToe::isRunning() {
    return TicTacToe::isGameRunning;
}

void TicTacToe::drawSampleBoard() {
    std::cout << "   |   |   " << std::endl;
    std::cout << " 1 | 2 | 3 " << std::endl;
    std::cout << "___|___|___" << std::endl;
    std::cout << "   |   |   " << std::endl;
    std::cout << " 4 | 5 | 6 " << std::endl;
    std::cout << "___|___|___" << std::endl;
    std::cout << "   |   |   " << std::endl;
    std::cout << " 7 | 8 | 9 " << std::endl;
    std::cout << "   |   |   " << std::endl;
}

void TicTacToe::drawBoard() {
    std::cout << "   |   |   " << std::endl;
    std::cout << " " << TicTacToe::boardState[0] << " | " << TicTacToe::boardState[1] << " | " << TicTacToe::boardState[2] << " " << std::endl;
    std::cout << "___|___|___" << std::endl;
    std::cout << "   |   |   " << std::endl;
    std::cout << " " << TicTacToe::boardState[3] << " | " << TicTacToe::boardState[4] << " | " << TicTacToe::boardState[5] << " " << std::endl;
    std::cout << "___|___|___" << std::endl;
    std::cout << "   |   |   " << std::endl;
    std::cout << " " << TicTacToe::boardState[6] << " | " << TicTacToe::boardState[7] << " | " << TicTacToe::boardState[8] << " " << std::endl;
    std::cout << "   |   |   " << std::endl;
}

void TicTacToe::setCurrentPlayer(int player) {
    TicTacToe::currentPlayer = player;
}

int TicTacToe::getCurrentPlayer() {
    return TicTacToe::currentPlayer;
}

void TicTacToe::setNextPlayer() {
    TicTacToe::currentPlayer = (TicTacToe::currentPlayer + 1) % 2;
}

bool TicTacToe::playTurnForPlayer(int player) {
    std::string playerName;
    if (player == 0) {
        playerName = TicTacToe::PLAYER_0;
    } else {
        playerName = TicTacToe::PLAYER_1;
    }
    std::cout << "Te toca, jugador " << playerName << std::endl;
    int move;
    std::cin >> move;
    if (TicTacToe::isMoveValid(move)) {
        if (TicTacToe::isMovePossible(move)) {
            TicTacToe::boardState[move-1] = playerName;
            return true;
        } else {
            std::cout << "Movimiento no válido!" << std::endl;
        }
    }
    return false;
}

bool TicTacToe::isMoveValid(int move) {
    return true;
}

bool TicTacToe::isMovePossible(int move) {
    if (TicTacToe::boardState[move-1] == std::to_string(move)) {
        return true;
    }
    return false;
}

void TicTacToe::endTurn() {
    if (TicTacToe::isGameFinished()) {
        TicTacToe::isGameRunning = false;
    } else {
        TicTacToe::setNextPlayer();
    }
}

bool TicTacToe::isGameFinished() {
    if (TicTacToe::isBoardFull()) {
        TicTacToe::endState = 2;
        return true;
    } else if (TicTacToe::isMatchForPlayer(TicTacToe::PLAYER_0)) {
        TicTacToe::endState = 0;
        return true;
    } else if (TicTacToe::isMatchForPlayer(TicTacToe::PLAYER_1)) {
        TicTacToe::endState = 1;
        return true;
    } else {
        return false;
    }
}

bool TicTacToe::isBoardFull() {
    int count = 0;
    for (std::string item : TicTacToe::boardState) {
        if (item == TicTacToe::PLAYER_0 || item == TicTacToe::PLAYER_1) {
            count++;
        }
    }
    if (count == 9) {
        return true;
    } else {
        return false;
    }
}

bool TicTacToe::isMatchForPlayer(std::string playerName) {
    std::vector<std::string> possibleMatches;
    int match = 0;
    // check rows
    possibleMatches.push_back(TicTacToe::boardState[0] + TicTacToe::boardState[1] + TicTacToe::boardState[2]);
    possibleMatches.push_back(TicTacToe::boardState[3] + TicTacToe::boardState[4] + TicTacToe::boardState[5]);
    possibleMatches.push_back(TicTacToe::boardState[6] + TicTacToe::boardState[7] + TicTacToe::boardState[8]);
    // check columns
    possibleMatches.push_back(TicTacToe::boardState[0] + TicTacToe::boardState[3] + TicTacToe::boardState[6]);
    possibleMatches.push_back(TicTacToe::boardState[1] + TicTacToe::boardState[4] + TicTacToe::boardState[7]);
    possibleMatches.push_back(TicTacToe::boardState[2] + TicTacToe::boardState[5] + TicTacToe::boardState[8]);
    // check diagonals
    possibleMatches.push_back(TicTacToe::boardState[0] + TicTacToe::boardState[4] + TicTacToe::boardState[8]);
    possibleMatches.push_back(TicTacToe::boardState[2] + TicTacToe::boardState[4] + TicTacToe::boardState[6]);
    
    for (std::string possibleMatch : possibleMatches) {
        match = possibleMatch.compare(playerName + playerName + playerName);
        if (match == 0) {
            return true;
        }
    }
    return false;
}

int TicTacToe::getEndState() {
    return TicTacToe::endState;
}
