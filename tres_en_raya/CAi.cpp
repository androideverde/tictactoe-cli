//
//  Ai.cpp
//  tres_en_raya
//
//  Created by Jordi Bernabeu on 22/08/2020.
//  Copyright © 2020 Jordi Bernabeu. All rights reserved.
//
#include <CAi.hpp>

#include <CRandomGenerator.hpp>

#include <sstream>

int CAi::MakeTurn(const CBoard& board)
{
    // if available, play 5
    if (board.IsAvailableSlot(4))
	{
        return 4;
    }
    // if not, check if @ is about to win and play to win
	std::map<EBoardValue, std::set<int>> almostMatches = board.MapAlmostMatchSlots();
	if (almostMatches[EBoardValue::PLAYER2].size() > 0) {
		auto iterator = almostMatches[EBoardValue::PLAYER2].begin();
		return *iterator;
	}
    // if not, check if X is about to win and play to stop him
	if (almostMatches[EBoardValue::PLAYER1].size() > 0) {
		auto iterator = almostMatches[EBoardValue::PLAYER1].begin();
		return *iterator;
	}
    // if not, play anywhere
    return PlayRandomAvailableSlot(board);
}

int CAi::PlayRandomAvailableSlot(const CBoard& board)
{
    return CRandomGenerator::GetRandomValueFromList(board.ListAvailableSlots());
}
