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
#include <thread>

int CAi::MakeTurn(const CBoard& board, const EBoardValue playerId)
{
	assert(playerId != EBoardValue::EMPTY);
	std::this_thread::sleep_for(std::chrono::seconds(1));
    // if available, play 5
    if (board.IsAvailableSlot(4))
	{
        return 4;
    }
    // if not, check if @ is about to win and play to win
	std::map<EBoardValue, std::set<int>> almostMatches = board.MapAlmostMatchSlots();
	if (almostMatches[playerId].size() > 0) {
		auto iterator = almostMatches[playerId].begin();
		return *iterator;
	}
	EBoardValue theOtherPlayerId = playerId == EBoardValue::PLAYER2 ? EBoardValue::PLAYER1 : EBoardValue::PLAYER2;
    // if not, check if X is about to win and play to stop him
	if (almostMatches[theOtherPlayerId].size() > 0) {
		auto iterator = almostMatches[theOtherPlayerId].begin();
		return *iterator;
	}
    // if not, play anywhere
    return PlayRandomAvailableSlot(board);
}

int CAi::MakeEasyTurn(const CBoard& board)
{
	std::this_thread::sleep_for(std::chrono::milliseconds(500));
    return PlayRandomAvailableSlot(board);
}

int CAi::PlayRandomAvailableSlot(const CBoard& board)
{
    return CRandomGenerator::GetRandomValueFromList(board.ListAvailableSlots());
}
