//=======================================================================
// Project: Implement the Game of a square in a Sudoku
// File: sixyBoard.hpp
// Author:  Ayush Bhusal & Nabin Bamma (December 2024)
// ======================================================================
#pragma once

#include "board.hpp"

class SixyBoard : public Board {
protected:
    void cVBox(short cStart,short rStart);       // Create a single vertical box cluster
    void cHBox(short rStart,short cStart);       // Create a single horizontal box cluster
    void mkVBoxes();                     // Iterates and creates all VBoxes
    void mkHBoxes();                     // Iterates and creates all HBoxes

public:
    // Constructor explicitly calls the base Board constructor and initializes traditional Sudoku
    SixyBoard(char type, std::ifstream& file)
        : Board(type, file) {
        mkVBoxes(); // Create vertical box clusters
        mkHBoxes(); // Create horizontal box clusters
    }
};