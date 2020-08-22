//
//  Ai.hpp
//  tres_en_raya
//
//  Created by Jordi Bernabeu on 22/08/2020.
//  Copyright © 2020 Jordi Bernabeu. All rights reserved.
//
#include <string>
#include <vector>

class Ai {
public:
    static int makeTurn(std::vector<std::string> boardState);
private:
    static int convertToInt(char icon);
    static std::vector<int> listAvailableSlots(std::vector<std::string> boardState);
    static int playFirstAvailableSlot(std::vector<std::string> boardState);
    static int playRandomAvailableSlot(std::vector<std::string> boardState);
};
