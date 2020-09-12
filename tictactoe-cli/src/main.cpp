//
//  main.cpp
//  tres_en_raya
//
//  Created by Jordi Bernabeu on 29/07/2020.
//  Copyright © 2020 Jordi Bernabeu. All rights reserved.
//

#include <CGameManager.h>

int main(int argc, const char * argv[])
{
    CGameManager gameManager = CGameManager();
    int status = gameManager.RunGame();
    return status;
}
