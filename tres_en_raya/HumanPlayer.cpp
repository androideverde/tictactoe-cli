//
//  HumanPlayer.cpp
//  tres_en_raya
//
//  Created by Jordi Bernabeu on 25/08/2020.
//  Copyright © 2020 Jordi Bernabeu. All rights reserved.
//

#include "HumanPlayer.hpp"
#include <iostream>
#include "Renderer.hpp"

bool HumanPlayer::playTurn(Board& board) const {
    int move;
    std::cin >> move;
    if (board.doMove(move-1, icon)) {
        return true;
    } else {
        Renderer render = Renderer();
        render.showMessage("Movimiento no válido!");
    }
    return false;
}
