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
#include "Renderer.hpp"
#include "Board.hpp"

class TicTacToe {
public:
    enum class Result {
        WIN_PLAYER_0,
        WIN_PLAYER_1,
        DRAW
    };
    TicTacToe(const Player& player0, const Player& player1, Board& board);
    bool isRunning() const {return isGameRunning;};
    void setCurrentPlayer(const Player& player) {currentPlayer = player;};
    Player getCurrentPlayer() const {return currentPlayer;};
    void setNextPlayer();
    bool playTurnForPlayer(const Player& player);
    TicTacToe::Result getResult() const {return result;};
    void endTurn();
    bool isGameFinished();

private:
    Board& board;
    Player PLAYER_0;
    Player PLAYER_1;
    Player currentPlayer = PLAYER_0;
    bool isGameRunning = true;
    TicTacToe::Result result;
    bool isMoveValid(const int move) const;
    Renderer render = Renderer();
};
