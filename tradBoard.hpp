//=======================================================================
// Project: Implement the Game of a square in a Sudoku
// File: tradBoard.hpp
// Author:  Ayush Bhusal & Nabin Bamma (December 2024)
// ======================================================================
#pragma once

#include "board.hpp"

class TradBoard : public Board {
protected:
    void createBox(short j, short k); // Create box clusters
    void makeBoxes();         // Iterates and creates all 3x3 boxes

public:
    // Constructor explicitly calls the base Board constructor and initializes traditional Sudoku
    TradBoard(char type, std::ifstream& file)
        : Board(type, file) {
        makeBoxes();
    }
};