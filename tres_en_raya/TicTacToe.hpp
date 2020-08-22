//
//  TicTacToe.hpp
//  tres_en_raya
//
//  Created by Jordi Bernabeu on 29/07/2020.
//  Copyright © 2020 Jordi Bernabeu. All rights reserved.
//

#include <vector>
#include <string>
#include "Player.hpp"

class TicTacToe {
public:
    enum class Result {
        WIN_PLAYER_0,
        WIN_PLAYER_1,
        DRAW
    };
    TicTacToe(Player* player0, Player* player1);
    bool isRunning() const {return isGameRunning;};
    void drawBoard() const;
    void drawSampleBoard() const;
    void setCurrentPlayer(Player* player) {currentPlayer = player;};
    Player* getCurrentPlayer() const {return currentPlayer;};
    void setNextPlayer();
    bool playTurnForPlayer(Player* player);
    TicTacToe::Result getResult() const {return result;};
    void endTurn();
    bool isGameFinished();

private:
    std::vector<std::string> boardState;
    Player* PLAYER_0;
    Player* PLAYER_1;
    Player* currentPlayer;
    bool isGameRunning = true;
    TicTacToe::Result result;
    bool isMoveValid(int move) const;
    bool isMovePossible(int move) const;
    bool isMatchForPlayer(Player* player) const;
    bool isBoardFull() const;
};
