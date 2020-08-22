//
//  RandomGenerator.hpp
//  tres_en_raya
//
//  Created by Jordi Bernabeu on 22/08/2020.
//  Copyright © 2020 Jordi Bernabeu. All rights reserved.
//
#include <vector>
#include <string>

class RandomGenerator {
public:
    static int getRandomSlot();
    static int getRandomSlotFromList(std::vector<int> availableSlots);
};
