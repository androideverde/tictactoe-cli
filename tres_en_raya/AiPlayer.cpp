//
//  AiPlayer.cpp
//  tres_en_raya
//
//  Created by Jordi Bernabeu on 25/08/2020.
//  Copyright © 2020 Jordi Bernabeu. All rights reserved.
//

#include "AiPlayer.hpp"
#include "Ai.hpp"
#include "Renderer.hpp"

bool AiPlayer::playTurn(Board board) const {
    int aiMove = Ai::makeTurn(board);
    Renderer render = Renderer();
    render.showMessage(name + " tira en: " + std::to_string(aiMove+1));
    if (board.doMove(aiMove, icon)) {
        return true;
    } else {
        render.showMessage("No move done!");
        return false;
    }
}
