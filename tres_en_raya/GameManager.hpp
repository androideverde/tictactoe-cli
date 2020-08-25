//
//  GameManager.hpp
//  tres_en_raya
//
//  Created by Jordi Bernabeu on 24/08/2020.
//  Copyright © 2020 Jordi Bernabeu. All rights reserved.
//

#include "TicTacToe.hpp"
#include "Player.hpp"
#include "Renderer.hpp"

class GameManager {
public:
    int runGame();
private:
    void showIntro(const std::string name0, const std::string name1) const;
    void showInstructions() const;
    Player selectStartingPlayer(const Player& player0, const Player& player1) const;
    Renderer render = Renderer();
};
