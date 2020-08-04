//
//  TicTacToe.hpp
//  tres_en_raya
//
//  Created by Jordi Bernabeu on 29/07/2020.
//  Copyright © 2020 Jordi Bernabeu. All rights reserved.
//

#include <vector>

class TicTacToe {
public:
    enum class Result {
        WIN_PLAYER_0,
        WIN_PLAYER_1,
        DRAW
    };
    TicTacToe(std::string player0, std::string player1);
    bool isRunning() const {return isGameRunning;};
    void drawBoard() const;
    void drawSampleBoard() const;
    void setCurrentPlayer(int player) {currentPlayer = player;};
    int getCurrentPlayer() const {return currentPlayer;};
    void setNextPlayer();
    bool playTurnForPlayer(int player);
    TicTacToe::Result getResult() const {return result;};
    void endTurn();
    bool isGameFinished();

private:
    std::vector<std::string> boardState;
    std::string PLAYER_0;
    std::string PLAYER_1;
    int currentPlayer;
    bool isGameRunning = true;
    TicTacToe::Result result;
    bool isMoveValid(int move) const;
    bool isMovePossible(int move) const;
    bool isMatchForPlayer(std::string playerName) const;
    bool isBoardFull() const;
};
