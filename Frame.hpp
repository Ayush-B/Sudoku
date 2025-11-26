//=======================================================================
// Project: Implement the Game of a square in a Sudoku
// File: Frame.hpp
// Author: Ayush Bhusal & Nabin Bamma (December 2024)
// ======================================================================
#pragma once

#include "square.hpp"
#include "state.hpp"

class Frame {
private:
    int n;                // Dimension of the Sudoku board (e.g., 9 for 9x9).
    State* squareStates;  // Dynamically allocated array of states for n*n squares.

public:
    // Constructor: Copies the states from the board's square array.
    Frame(Square* squares, int size);

    // Accessor to get a specific state's value.
    char getStateAt(int index) const;

    // Accessor to get a specific state's poss.
    std::string getPossAt(int index) const;

    // Print the frame state.
    void print(std::ostream& out) const;
};
