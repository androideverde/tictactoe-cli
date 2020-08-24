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
    void showIntro(std::string name0, std::string name1) const;
    void showInstructions(TicTacToe game) const;
    Player selectStartingPlayer(Player player0, Player player1) const;
    Renderer render = Renderer();
};
