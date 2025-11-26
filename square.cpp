//=======================================================================
// Project: Implement the State of a square in a Sudoku
// File: cluster.cpp
// Author: Ayush Bhusal & Nabin Bamma (October 2024)
//=======================================================================
#include "square.hpp"
#include "cluster.hpp"

//-----------------------------------------------------------------------
void Square::
mark(const char ch , bool shp) {
    State::mark(ch);
    //cout << "Marking Square[" << row << "," << col << "] with value " << ch << ".\n";
    if (shp) shoop(ch - '0');
};

//-----------------------------------------------------------------------
void Square::
shoop(const int bit) {
    if (bit != -3) {
        cout << "Shooping Square[" << bit << "]\n";
        for (Cluster* c1 : clusters) {
            c1->shoop(bit); // Call shoop on each cluster
        };
    }
}

//-----------------------------------------------------------------------
void Square::
turnOff(int n) {
    // Call the remove_poss method of state1 to remove the possibility
    State::remove_poss(n);
    cout << "Removing possibility " << n << " from Square[" << row << "," << col << "].\n";
}
