//
//  Player.cpp
//  tres_en_raya
//
//  Created by Jordi Bernabeu on 22/08/2020.
//  Copyright © 2020 Jordi Bernabeu. All rights reserved.
//

#include <CPlayer.hpp>

CPlayer::CPlayer(const EBoardValue id, const char icon, const std::string& name)
	: m_id(id)
	, m_icon(icon)
	, m_name(name)
{
}

std::string CPlayer::SetName(const std::string& displayName)
{
    m_name = displayName;
    return m_name;
}
