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

using AiFunction = std::function<int (CBoard&, EBoardValue)>;

class CAiPlayer : public CPlayer {
public:
    CAiPlayer(EBoardValue id, char icon, const std::string& name, AiFunction aiTurnFunction);
    bool PlayTurn(CBoard& board) const override;
private:
	const AiFunction m_aiTurnFunction;
};
