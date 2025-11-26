//=======================================================================
// Project: Implement the State of a square in a Sudoku
// File: dboard.cpp
// Author: Ayush Bhusal & Nabin Bamma (November 2024)
//=======================================================================
#include "dboard.hpp"

void DiagBoard::mkDiag() {
    Square* diag1[n]; // Major diagonal
    Square* diag2[n]; // Minor diagonal

    for (short k = 0; k < n; ++k) {
        diag1[k] = &sub(k + 1, k + 1);         // Major diagonal
        diag2[k] = &sub(k + 1, n - k);         // Minor diagonal
    }

    clusters.push_back(new Cluster(ClusterType::DIAG, diag1,n));  // Add major diagonal cluster
    clusters.push_back(new Cluster(ClusterType::DIAG, diag2,n));  // Add minor diagonal cluster
}

