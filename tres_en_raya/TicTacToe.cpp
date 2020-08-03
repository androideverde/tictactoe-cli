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

TicTacToe::TicTacToe(std::string player0, std::string player1) : PLAYER_0(player0), PLAYER_1(player1) {
    size_t size = 9;
    std::vector<std::string> board(size);
    for (int i=1; i<10; i++) {
        board[i-1] = std::to_string(i);
    }
    boardState = board;
}

bool TicTacToe::isRunning() {
    return isGameRunning;
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
    std::cout << " " << boardState[0] << " | " << boardState[1] << " | " << boardState[2] << " " << std::endl;
    std::cout << "___|___|___" << std::endl;
    std::cout << "   |   |   " << std::endl;
    std::cout << " " << boardState[3] << " | " << boardState[4] << " | " << boardState[5] << " " << std::endl;
    std::cout << "___|___|___" << std::endl;
    std::cout << "   |   |   " << std::endl;
    std::cout << " " << boardState[6] << " | " << boardState[7] << " | " << boardState[8] << " " << std::endl;
    std::cout << "   |   |   " << std::endl;
}

void TicTacToe::setCurrentPlayer(int player) {
    currentPlayer = player;
}

int TicTacToe::getCurrentPlayer() {
    return currentPlayer;
}

void TicTacToe::setNextPlayer() {
    currentPlayer = (currentPlayer + 1) % 2;
}

bool TicTacToe::playTurnForPlayer(int player) {
    std::string playerName;
    if (player == 0) {
        playerName = PLAYER_0;
    } else {
        playerName = PLAYER_1;
    }
    std::cout << "Te toca, jugador " << playerName << std::endl;
    int move;
    std::cin >> move;
    if (isMoveValid(move)) {
        if (isMovePossible(move)) {
            boardState[move-1] = playerName;
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
    if (boardState[move-1] == std::to_string(move)) {
        return true;
    }
    return false;
}

void TicTacToe::endTurn() {
    if (isGameFinished()) {
        isGameRunning = false;
    } else {
        setNextPlayer();
    }
}

bool TicTacToe::isGameFinished() {
    if (isBoardFull()) {
        endState = 2;
        return true;
    } else if (isMatchForPlayer(PLAYER_0)) {
        endState = 0;
        return true;
    } else if (isMatchForPlayer(PLAYER_1)) {
        endState = 1;
        return true;
    } else {
        return false;
    }
}

bool TicTacToe::isBoardFull() {
    int count = 0;
    for (std::string item : boardState) {
        if (item == PLAYER_0 || item == PLAYER_1) {
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
    possibleMatches.push_back(boardState[0] + boardState[1] + boardState[2]);
    possibleMatches.push_back(boardState[3] + boardState[4] + boardState[5]);
    possibleMatches.push_back(boardState[6] + boardState[7] + boardState[8]);
    // check columns
    possibleMatches.push_back(boardState[0] + boardState[3] + boardState[6]);
    possibleMatches.push_back(boardState[1] + boardState[4] + boardState[7]);
    possibleMatches.push_back(boardState[2] + boardState[5] + boardState[8]);
    // check diagonals
    possibleMatches.push_back(boardState[0] + boardState[4] + boardState[8]);
    possibleMatches.push_back(boardState[2] + boardState[4] + boardState[6]);
    
    for (std::string possibleMatch : possibleMatches) {
        match = possibleMatch.compare(playerName + playerName + playerName);
        if (match == 0) {
            return true;
        }
    }
    return false;
}

int TicTacToe::getEndState() {
    return endState;
}
