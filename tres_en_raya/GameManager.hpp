//
//  GameManager.hpp
//  tres_en_raya
//
//  Created by Jordi Bernabeu on 24/08/2020.
//  Copyright © 2020 Jordi Bernabeu. All rights reserved.
//
#pragma once
#include <string>
#include "Renderer.hpp"

class Player;

class GameManager {
public:
    int runGame();
private:
    void showIntro(const std::string& name1, const std::string& name2) const;
    void showInstructions() const;
    const Player* selectStartingPlayer(Player& player1, Player& player2) const;
    Renderer render = Renderer();
};
