//
//  Ai.hpp
//  tres_en_raya
//
//  Created by Jordi Bernabeu on 22/08/2020.
//  Copyright © 2020 Jordi Bernabeu. All rights reserved.
//
#pragma once
#include <string>
#include <vector>
#include "Board.hpp"

class Ai {
public:
    static int makeTurn(const Board& board);
private:
    static int playRandomAvailableSlot(const Board& board);
};
