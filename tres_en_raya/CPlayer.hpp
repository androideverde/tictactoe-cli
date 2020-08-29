//
//  Player.hpp
//  tres_en_raya
//
//  Created by Jordi Bernabeu on 22/08/2020.
//  Copyright © 2020 Jordi Bernabeu. All rights reserved.
//
#pragma once

#include <CBoard.hpp>

#include <string>

class CPlayer
{
public:
    CPlayer(const EBoardValue id, const char icon, const std::string& name);
    EBoardValue GetId() const { return m_id; }
    char GetIcon() const { return m_icon; }
    std::string GetName() const { return m_name; }
    std::string SetName(const std::string& name);
    virtual bool PlayTurn(CBoard& board) const = 0;
protected:
    EBoardValue m_id;
    char m_icon;
    std::string m_name = "player_name";
};
