//
//  HumanPlayer.cpp
//  tres_en_raya
//
//  Created by Jordi Bernabeu on 25/08/2020.
//  Copyright © 2020 Jordi Bernabeu. All rights reserved.
//
#include <CHumanPlayer.hpp>

#include <CRenderer.hpp>

#include <iostream>

CHumanPlayer::CHumanPlayer(const EBoardValue id, const char icon, const std::string& name)
	: CPlayer(id, icon, name)
{
}

bool CHumanPlayer::PlayTurn(CBoard& board) const
{
    int move;
    std::cin >> move;
    if (board.DoMove(move-1, m_id))
	{
        return true;
    }
	else
	{
        CRenderer render = CRenderer();
        render.ShowMessage("Movimiento no válido!");
    }
    return false;
}
