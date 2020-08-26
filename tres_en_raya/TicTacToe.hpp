//
//  TicTacToe.hpp
//  tres_en_raya
//
//  Created by Jordi Bernabeu on 29/07/2020.
//  Copyright © 2020 Jordi Bernabeu. All rights reserved.
//
#pragma once
#include <vector>
#include <string>
#include "Player.hpp"
#include "Renderer.hpp"
#include "Board.hpp"

class TicTacToe {
public:
    enum class Result {
        WIN_PLAYER_1,
        WIN_PLAYER_2,
        DRAW
    };
    TicTacToe(Player& player1, Player& player2, Board& board);
    bool isRunning() const {return isGameRunning;};
    void setCurrentPlayer(const Player* player) {currentPlayer = player;};
    const Player* getCurrentPlayer() const {return currentPlayer;};
    void setNextPlayer();
    TicTacToe::Result getResult() const {return result;};
    void endTurn();
    bool isGameFinished();
    void runTurn();

private:
    Board& board;
    Player& player1;
    Player& player2;
    const Player* currentPlayer;
    bool isGameRunning = true;
    TicTacToe::Result result;
    bool isMoveValid(int move) const;
    Renderer render = Renderer();
};
