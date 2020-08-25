//
//  Board.cpp
//  tres_en_raya
//
//  Created by Jordi Bernabeu on 24/08/2020.
//  Copyright © 2020 Jordi Bernabeu. All rights reserved.
//

#include "Board.hpp"
#include "Renderer.hpp"
#include <sstream>

Board::Board() {
    size_t size = 9;
    std::vector<std::string> board(size);
    for (int i = 0; i < 9; i++) {
        board[i] = std::to_string(i+1);
    }
    boardState = board;
}

void Board::reset() {
    for (int i = 0; i < 9; i++) {
        boardState[i] = std::to_string(i+1);
    }
}

bool Board::doMove(const int position, const char icon) {
    if (isMovePossible(position)) {
        boardState[position] = icon;
        return true;
    }
    return false;
}

bool Board::isMovePossible(const int position) const {
    if (boardState[position] == std::to_string(position+1)) {
        return true;
    }
    return false;
}

bool Board::isMatchForPlayer(const Player& player) const {
    std::string playerIcon;
    playerIcon = player.getIcon();
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

bool Board::isBoardFull(const Player& player0, const Player& player1) const {
    int count = 0;
    for (std::string item : boardState) {
        if (item[0] == player0.getIcon() || item[0] == player1.getIcon()) {
            count++;
        }
    }
    if (count == 9) {
        return true;
    } else {
        return false;
    }
}

void Board::drawBoard() const {
    Renderer render = Renderer();
    render.drawBoard(boardState);
}

bool Board::isAvailableSlot(const int position) const {
    if (boardState[position] == std::to_string(position+1)) {
        return true;
    }
    return false;
}

std::vector<int> Board::listAvailableSlots() const {
    std::vector<int> available;
    int index = 0;
    for (std::string item : boardState) {
        int value = convertToInt(item[0]);
        if (value == index+1) {
            available.push_back(index);
        }
        index++;
    }
    return available;
}

int Board::convertToInt(const char icon) const {
    std::stringstream str;
    str << icon;
    int out;
    str >> out;
    return out;
}
