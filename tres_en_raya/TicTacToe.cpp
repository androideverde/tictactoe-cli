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

TicTacToe::TicTacToe(Player* player0, Player* player1) : PLAYER_0(player0), PLAYER_1(player1) {
    size_t size = 9;
    std::vector<std::string> board(size);
    for (int i=1; i<10; i++) {
        board[i-1] = std::to_string(i);
    }
    boardState = board;
}

void TicTacToe::drawSampleBoard() const {
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

void TicTacToe::drawBoard() const {
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

void TicTacToe::setNextPlayer() {
    if (currentPlayer->getIcon() == PLAYER_0->getIcon()) {
        currentPlayer = PLAYER_1;
    } else {
        currentPlayer = PLAYER_0;
    }
}

bool TicTacToe::playTurnForPlayer(Player* player) {
    std::cout << "Te toca, " << player->getName() << std::endl;
    if (player->isAi()) {
        int aiMove = Ai::makeTurn(boardState);
        std::cout << player->getName() << " tira en: " << std::to_string(aiMove) << std::endl;
        boardState[aiMove-1] = player->getIcon();
        return true;
    } else {
        int move;
        std::cin >> move;
        if (isMoveValid(move)) {
            if (isMovePossible(move)) {
                boardState[move-1] = player->getIcon();
                return true;
            } else {
                std::cout << "Movimiento no válido!" << std::endl;
            }
        }
        return false;
    }
}

bool TicTacToe::isMoveValid(int move) const {
    return true;
}

bool TicTacToe::isMovePossible(int move) const {
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
    if (isMatchForPlayer(PLAYER_0)) {
        result = Result::WIN_PLAYER_0;
        return true;
    } else if (isMatchForPlayer(PLAYER_1)) {
        result = Result::WIN_PLAYER_1;
        return true;
    } else if (isBoardFull()) {
            result = Result::DRAW;
            return true;
    } else {
        return false;
    }
}

bool TicTacToe::isBoardFull() const {
    int count = 0;
    for (std::string item : boardState) {
        if (item[0] == PLAYER_0->getIcon() || item[0] == PLAYER_1->getIcon()) {
            count++;
        }
    }
    if (count == 9) {
        return true;
    } else {
        return false;
    }
}

bool TicTacToe::isMatchForPlayer(Player* player) const {
    std::string playerIcon;
    playerIcon = player->getIcon();
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
        match = possibleMatch.compare(playerIcon + playerIcon + playerIcon);
        if (match == 0) {
            return true;
        }
    }
    return false;
}
