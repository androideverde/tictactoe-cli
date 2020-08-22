//
//  Ai.cpp
//  tres_en_raya
//
//  Created by Jordi Bernabeu on 22/08/2020.
//  Copyright © 2020 Jordi Bernabeu. All rights reserved.
//

#include "Ai.hpp"
#include <sstream>
#include "RandomGenerator.hpp"

int Ai::makeTurn(std::vector<std::string> boardState) {
    // if available, play 5
    if (boardState[4] == "5") {
        return 5;
    }
    // if not, check if @ is about to win and play to win
    // if not, check if X is about to win and play to stop him
    // if not, play anywhere
    return playRandomAvailableSlot(boardState);
}

int Ai::playFirstAvailableSlot(std::vector<std::string> boardState) {
    return listAvailableSlots(boardState)[0];
}

int Ai::playRandomAvailableSlot(std::vector<std::string> boardState) {
    return RandomGenerator::getRandomSlotFromList(listAvailableSlots(boardState));
}

std::vector<int> Ai::listAvailableSlots(std::vector<std::string> boardState) {
    std::vector<int> available;
    int count = 1;
    for (std::string item : boardState) {
        int value = convertToInt(item[0]);
        if (value == count) {
            available.push_back(value);
        }
        count++;
    }
    return available;
}

int Ai::convertToInt(char icon) {
    std::stringstream str;
    str << icon;
    int out;
    str >> out;
    return out;
}
