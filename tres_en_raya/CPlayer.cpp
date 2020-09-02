//
//  Player.cpp
//  tres_en_raya
//
//  Created by Jordi Bernabeu on 22/08/2020.
//  Copyright © 2020 Jordi Bernabeu. All rights reserved.
//

#include <CPlayer.hpp>

#include <CRenderer.hpp>
#include <CTurnMaker.hpp>

namespace CPlayerInternal {
	std::map<EPlayerType, std::function<int (CBoard&, EBoardValue)>> PlayerTurnFunctions = {
		{EPlayerType::HUMAN, [](CBoard&, EBoardValue){ return CTurnMaker::MakeTurnHuman(); }},
		{EPlayerType::AI_EASY, [](CBoard& board, EBoardValue){ return CTurnMaker::MakeTurnAiEasy(board); }},
		{EPlayerType::AI_REGULAR, CTurnMaker::MakeTurnAiRegular}
	};
}

CPlayer::CPlayer(EBoardValue id, char icon, const std::string& name, EPlayerType playerType)
	: m_id(id)
	, m_icon(icon)
	, m_name(name)
	, m_playerType(playerType)
{
}

bool CPlayer::PlayTurn(CBoard& board) const
{
	int move = CPlayerInternal::PlayerTurnFunctions[m_playerType](board, m_id);
    CRenderer render = CRenderer();
    render.ShowMessage(m_name + " tira en: " + std::to_string(move+1));
    if (board.DoMove(move, m_id))
	{
        return true;
    }
	else
	{
        render.ShowMessage("Movimiento no válido!");
        return false;
    }
}

std::string CPlayer::SetName(const std::string& displayName)
{
    m_name = displayName;
    return m_name;
}
