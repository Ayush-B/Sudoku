//=======================================================================
// Project: Implement the Game of a square in a Sudoku
// File: Frame.cpp
// Author: Ayush Bhusal & Nabin Bamma (December 2024)
// ======================================================================

#include "Frame.hpp"

// Constructor: Copies the states from the board's square array.
Frame::Frame(Square* squares, int size)
    : n(size), squareStates(new State[size * size]) {
    for (int k = 0; k < n * n; ++k) {
        squareStates[k] = *static_cast<State*>(&squares[k]); // Copy state from each square.
    }
}


// Accessor to get a specific state's value.
char Frame::getStateAt(int index) const {
    if (index < 0 || index >= n * n) {
        throw std::out_of_range("Index out of range for Frame.");
    }
    return squareStates[index].getValue();
}

// Accessor to get a specific state's poss.
std::string Frame::getPossAt(int index) const {
    if (index < 0 || index >= n * n) {
        throw std::out_of_range("Index out of range for Frame.");
    }
    return squareStates[index].getPoss();
}

// Print the frame state.
void Frame::print(std::ostream& out) const {
    out << "Frame State:" << std::endl;
    for (int k = 0; k < n * n; ++k) {
        squareStates[k].print(out) << " ";
        if ((k + 1) % n == 0) {
            out << std::endl; // Newline for each row.
        }
    }
}
