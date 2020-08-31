//
//  AiPlayer.cpp
//  tres_en_raya
//
//  Created by Jordi Bernabeu on 25/08/2020.
//  Copyright © 2020 Jordi Bernabeu. All rights reserved.
//
#include <CAiPlayer.hpp>

#include <CAi.hpp>
#include <CRenderer.hpp>

CAiPlayer::CAiPlayer(const EBoardValue id, const char icon, const std::string& name, const bool easy)
	: CPlayer(id, icon, name), easy(easy)
{
}

bool CAiPlayer::PlayTurn(CBoard& board) const
{
    int aiMove = easy ? CAi::MakeEasyTurn(board) : CAi::MakeTurn(board, m_id);
    CRenderer render = CRenderer();
    render.ShowMessage(m_name + " tira en: " + std::to_string(aiMove+1));
    if (board.DoMove(aiMove, m_id))
	{
        return true;
    }
	else
	{
        render.ShowMessage("No move done!");
        return false;
    }
}
