//
//  Player.cpp
//  tres_en_raya
//
//  Created by Jordi Bernabeu on 22/08/2020.
//  Copyright © 2020 Jordi Bernabeu. All rights reserved.
//

#include "Player.hpp"

Player::Player(char icon, std::string name, bool ai) : icon(icon), name(name), ai(ai) {
    
}

Player::Player() {
    
}

std::string Player::setName(std::string displayName) {
    name = displayName;
    return name;
}
