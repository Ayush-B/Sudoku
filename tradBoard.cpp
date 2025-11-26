//=======================================================================
// Project: Implement the State of a square in a Sudoku
// File: cluster.cpp
// Author: Ayush Bhusal & Nabin Bamma (October 2024)
//=======================================================================
#include "tradBoard.hpp"

// Method to iterate and create all 3x3 boxes
void TradBoard::makeBoxes() {
    for (short row = 0; row < n; row += 3) {    // Iterate over rows in steps of 3
        for (short col = 0; col < n; col += 3) { // Iterate over columns in steps of 3
            createBox(row, col);                // Create a box cluster
        }
    }
}

// Method to create a single 3x3 box cluster
void TradBoard::createBox(short j, short k) {
    Square* boxSquares[n]; // Array to hold pointers to squares
    short index = 0;

    // Fill the array with pointers to squares in the 3x3 box
    for (short row = j; row < j + 3; ++row) {
        for (short col = k; col < k + 3; ++col) {
            boxSquares[index++] = &sub(row + 1, col + 1); // Convert to 1-based indexing
        }
    }

    clusters.push_back(new Cluster(ClusterType::BOX, boxSquares,n)); // Create and store the Cluster
}

