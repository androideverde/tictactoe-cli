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

class CTurnMaker
{
public:
    static int MakeTurnAiRegular(const CBoard& board, EBoardValue playerId);
	static int MakeTurnAiEasy(const CBoard& board);
	static int MakeTurnHuman();
private:
    static int PlayRandomAvailableSlot(const CBoard& board);
};
