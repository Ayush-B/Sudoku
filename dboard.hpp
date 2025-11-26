//=======================================================================
// Project: Implement the Game of a square in a Sudoku
// File: dboard.hpp
// Author:  Ayush Bhusal & Nabin Bamma (November 2024)
// ======================================================================
#pragma once

#include "board.hpp"
#include "tradBoard.hpp"

class DiagBoard : public TradBoard {
public:
    DiagBoard(char type, std::ifstream& file)
       : TradBoard(type, file) {  // Call base constructor
        mkDiag();                // Create diagonal clusters
    }

private:
    void mkDiag();  // Method to create diagonal clusters
};
