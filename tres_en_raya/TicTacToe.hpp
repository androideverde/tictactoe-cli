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
    bool isRunning();
    void drawBoard();
    void drawSampleBoard();
    void setCurrentPlayer(int player);
    int getCurrentPlayer();
    void setNextPlayer();
    bool playTurnForPlayer(int player);
    TicTacToe::Result getResult();
    void endTurn();
    bool isGameFinished();

private:
    std::vector<std::string> boardState;
    std::string PLAYER_0;
    std::string PLAYER_1;
    int currentPlayer;
    bool isGameRunning = true;
    TicTacToe::Result result;
    bool isMoveValid(int move);
    bool isMovePossible(int move);
    bool isMatchForPlayer(std::string playerName);
    bool isBoardFull();
};
