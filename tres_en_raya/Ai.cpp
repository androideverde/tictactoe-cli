//
//  Ai.cpp
//  tres_en_raya
//
//  Created by Jordi Bernabeu on 22/08/2020.
//  Copyright © 2020 Jordi Bernabeu. All rights reserved.
//

#include "Ai.hpp"
#include <sstream>
#include "RandomGenerator.hpp"

int Ai::makeTurn(const Board& board) {
    // if available, play 5
    if (board.isAvailableSlot(4)) {
        return 4;
    }
    // if not, check if @ is about to win and play to win
    // if not, check if X is about to win and play to stop him
    // if not, play anywhere
    return playRandomAvailableSlot(board);
}

int Ai::playRandomAvailableSlot(const Board& board) {
    return RandomGenerator::getRandomSlotFromList(board.listAvailableSlots());
}
