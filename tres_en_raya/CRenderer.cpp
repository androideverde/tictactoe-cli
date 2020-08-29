//
//  Renderer.cpp
//  tres_en_raya
//
//  Created by Jordi Bernabeu on 24/08/2020.
//  Copyright © 2020 Jordi Bernabeu. All rights reserved.
//
#include <CRenderer.hpp>

#include <iostream>

void CRenderer::ShowMessage(const std::string message) const
{
    std::cout << message << std::endl;
}

void CRenderer::DrawSampleBoard() const
{
    std::cout << "   |   |   " << std::endl;
    std::cout << " 1 | 2 | 3 " << std::endl;
    std::cout << "___|___|___" << std::endl;
    std::cout << "   |   |   " << std::endl;
    std::cout << " 4 | 5 | 6 " << std::endl;
    std::cout << "___|___|___" << std::endl;
    std::cout << "   |   |   " << std::endl;
    std::cout << " 7 | 8 | 9 " << std::endl;
    std::cout << "   |   |   " << std::endl;
}

void CRenderer::DrawBoard(const std::vector<std::string> board) const
{
    std::cout << "   |   |   " << std::endl;
    std::cout << " " << board[0] << " | " << board[1] << " | " << board[2] << " " << std::endl;
    std::cout << "___|___|___" << std::endl;
    std::cout << "   |   |   " << std::endl;
    std::cout << " " << board[3] << " | " << board[4] << " | " << board[5] << " " << std::endl;
    std::cout << "___|___|___" << std::endl;
    std::cout << "   |   |   " << std::endl;
    std::cout << " " << board[6] << " | " << board[7] << " | " << board[8] << " " << std::endl;
    std::cout << "   |   |   " << std::endl;
}
