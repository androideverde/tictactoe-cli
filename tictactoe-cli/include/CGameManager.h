//
//  GameManager.hpp
//  tres_en_raya
//
//  Created by Jordi Bernabeu on 24/08/2020.
//  Copyright © 2020 Jordi Bernabeu. All rights reserved.
//
#pragma once

#include <CRenderer.h>

#include <string>

class CPlayer;

class CGameManager
{
public:
    int RunGame();
private:
    void ShowIntro(const std::string& name1, const std::string& name2) const;
    void ShowInstructions() const;
    const CPlayer* SelectStartingPlayer(CPlayer& player1, CPlayer& player2) const;
    CRenderer m_render = CRenderer();
};
