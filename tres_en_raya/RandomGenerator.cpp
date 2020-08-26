//
//  RandomGenerator.cpp
//  tres_en_raya
//
//  Created by Jordi Bernabeu on 22/08/2020.
//  Copyright © 2020 Jordi Bernabeu. All rights reserved.
//

#include "RandomGenerator.hpp"
#include <random>

int RandomGenerator::getRandomSlot() {
    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(0, 8);
    return distribution(generator);
}

int RandomGenerator::getRandomSlotFromList(const std::vector<int> availableSlots) {
    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(0, static_cast<int>(availableSlots.size()) - 1);
    int randomPick = distribution(generator);
    return availableSlots[randomPick];
}
