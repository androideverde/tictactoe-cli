//
//  main.cpp
//  tres_en_raya
//
//  Created by Jordi Bernabeu on 29/07/2020.
//  Copyright © 2020 Jordi Bernabeu. All rights reserved.
//

#include "GameManager.hpp"

int main(int argc, const char * argv[]) {
    GameManager gameManager = GameManager();
    int status = gameManager.runGame();
    return status;
}
