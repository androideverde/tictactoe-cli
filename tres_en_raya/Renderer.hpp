//
//  Renderer.hpp
//  tres_en_raya
//
//  Created by Jordi Bernabeu on 24/08/2020.
//  Copyright © 2020 Jordi Bernabeu. All rights reserved.
//
#pragma once
#include <string>
#include <vector>

class Renderer {
public:
    void showMessage(const std::string message) const;
    void drawSampleBoard() const;
    void drawBoard(const std::vector<std::string> board) const;
};
