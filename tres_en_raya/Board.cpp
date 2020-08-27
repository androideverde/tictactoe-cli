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
#include "Player.hpp"
#include <map>

Board::Board() {
    for (int i = 0; i < 9; i++) {
        boardState.push_back(BoardValue::EMPTY);
    }
}

bool Board::doMove(int position, BoardValue playerId) {
    if (isAvailableSlot(position)) {
        boardState[position] = playerId;
        return true;
    }
    return false;
}

bool Board::isMatchForPlayer(BoardValue playerId) const {
    // check rows
    if (boardState[0] == playerId && boardState[1] == playerId && boardState[2] == playerId) {
        return true;
    }
    if (boardState[3] == playerId && boardState[4] == playerId && boardState[5] == playerId) {
        return true;
    }
    if (boardState[6] == playerId && boardState[7] == playerId && boardState[8] == playerId) {
        return true;
    }
    // check columns
    if (boardState[0] == playerId && boardState[3] == playerId && boardState[6] == playerId) {
        return true;
    }
    if (boardState[1] == playerId && boardState[4] == playerId && boardState[7] == playerId) {
        return true;
    }
    if (boardState[2] == playerId && boardState[5] == playerId && boardState[8] == playerId) {
        return true;
    }
    // check diagonals
    if (boardState[0] == playerId && boardState[4] == playerId && boardState[8] == playerId) {
        return true;
    }
    if (boardState[2] == playerId && boardState[4] == playerId && boardState[6] == playerId) {
        return true;
    }
    return false;
}

bool Board::isBoardFull() const {
    int count = 0;
    for (BoardValue value : boardState) {
        if (value != BoardValue::EMPTY) {
            count++;
        }
    }
    if (count == 9) {
        return true;
    } else {
        return false;
    }
}

void Board::drawBoard(const Player& player1, const Player& player2) const {
    Renderer render = Renderer();
    std::vector<std::string> board;
    std::string newValue;
    std::map<BoardValue, std::string> valueToString = {
        {BoardValue::EMPTY, " "},
        {player1.getId(), std::string(1, player1.getIcon())},
        {player2.getId(), std::string(1, player2.getIcon())}
    };
    for (BoardValue value : boardState) {
        board.push_back(valueToString[value]);
    }
    render.drawBoard(board);
}

bool Board::isAvailableSlot(int position) const {
    if (boardState[position] == BoardValue::EMPTY) {
        return true;
    }
    return false;
}

std::vector<int> Board::listAvailableSlots() const {
    std::vector<int> available;
    int index = 0;
    for (BoardValue value : boardState) {
        if (value == BoardValue::EMPTY) {
            available.push_back(index);
        }
        index++;
    }
    return available;
}
