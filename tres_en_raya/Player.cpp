//
//  Player.cpp
//  tres_en_raya
//
//  Created by Jordi Bernabeu on 22/08/2020.
//  Copyright © 2020 Jordi Bernabeu. All rights reserved.
//

#include "Player.hpp"

Player::Player(const char icon, const std::string& name) : icon(icon), name(name) {
    
}

std::string Player::setName(const std::string& displayName) {
    name = displayName;
    return name;
}
