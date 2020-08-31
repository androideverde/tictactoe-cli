//
//  AiPlayer.hpp
//  tres_en_raya
//
//  Created by Jordi Bernabeu on 25/08/2020.
//  Copyright © 2020 Jordi Bernabeu. All rights reserved.
//
#pragma once

#include <CPlayer.hpp>
#include <CBoard.hpp>

class CAiPlayer : public CPlayer {
public:
    CAiPlayer(const EBoardValue id, const char icon, const std::string& name, const bool easy);
    bool PlayTurn(CBoard& board) const override;
private:
	bool easy = false;
};
