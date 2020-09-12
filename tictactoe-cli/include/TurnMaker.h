//
//  Ai.hpp
//  tres_en_raya
//
//  Created by Jordi Bernabeu on 22/08/2020.
//  Copyright © 2020 Jordi Bernabeu. All rights reserved.
//
#pragma once

#include <CBoard.h>

#include <string>
#include <vector>

namespace TurnMaker
{
	int MakeTurnAiRegular(const CBoard& board, EBoardValue playerId);
	int MakeTurnAiEasy(const CBoard& board);
	int MakeTurnHuman();
};
