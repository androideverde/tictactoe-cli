//
//  RandomGenerator.hpp
//  tres_en_raya
//
//  Created by Jordi Bernabeu on 22/08/2020.
//  Copyright © 2020 Jordi Bernabeu. All rights reserved.
//
#pragma once

#include <vector>
#include <set>

class CRandomGenerator
{
public:
    static int GetRandomSlot();
    static int GetRandomValueFromList(const std::vector<int> availableSlots);
	static int GetRandomValueFromList(const std::set<int> availableSlots);
};
