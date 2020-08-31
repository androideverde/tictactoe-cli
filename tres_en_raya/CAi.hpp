//
//  Ai.hpp
//  tres_en_raya
//
//  Created by Jordi Bernabeu on 22/08/2020.
//  Copyright © 2020 Jordi Bernabeu. All rights reserved.
//
#pragma once

#include <CBoard.hpp>

#include <string>
#include <vector>

class CAi
{
public:
    static int MakeTurn(const CBoard& board, const EBoardValue playerId);
private:
    static int PlayRandomAvailableSlot(const CBoard& board);
};
