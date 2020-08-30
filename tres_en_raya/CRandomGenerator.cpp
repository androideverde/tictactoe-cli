//
//  RandomGenerator.cpp
//  tres_en_raya
//
//  Created by Jordi Bernabeu on 22/08/2020.
//  Copyright © 2020 Jordi Bernabeu. All rights reserved.
//
#include <CRandomGenerator.hpp>

#include <random>

int CRandomGenerator::GetRandomSlot()
{
    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(0, 8);
    return distribution(generator);
}

int CRandomGenerator::GetRandomValueFromList(const std::vector<int> availableSlots)
{
    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(0, static_cast<int>(availableSlots.size()) - 1);
    int randomPick = distribution(generator);
    return availableSlots[randomPick];
}

int CRandomGenerator::GetRandomValueFromList(const std::set<int> availableSlots)
{
	std::vector<int> list(availableSlots.begin(), availableSlots.end());
	return GetRandomValueFromList(list);
}
