//=======================================================================
// Project: Implement the Game of a square in a Sudoku
// File: board.hpp
// Author:  Ayush Bhusal & Nabin Bamma (September 2024)
// ======================================================================
#pragma once

#include <stack>

#include "square.hpp"
#include "tools.hpp"
#include "state.hpp"
#include "sudoku_error.hpp"
#include "CanView.hpp"
#include "Frame.hpp"
#include "Stack.hpp"

// Enumeration for cluster types
enum class ClusterT { ROW, COLUMN, BOX, DIAG };

//-----------------------------------------------------------------
class Board: public CanView{
    private:
        ifstream& puzfile;
        Square* bd;
        //short int rem = n * n;

        void getPuzzle();
        void createRow(short j); // Create row clusters
        void createColumn(short k); // Create column clusters

    protected:
    virtual void makeClusters(); // Function to create all clusters
    vector<Cluster*> clusters; // Vector to store clusters
    short n = 9;


    public:
        Stack unStack;
        Stack reStack;

        Board(char type, ifstream& puzfile);
        ~Board() {
            delete[] bd;   //Free bd
            cerr << "Board destroyed.\n";
        };

        // Subscript function to return ref to square
        Square& sub(int r, int c) const{ return bd[n*(r-1)+(c-1)]; };

        // Print board
        ostream& print( ostream& out ) const;

        char getMarkChar(int r, int c) const override {
            return sub(r, c).getValue() + '0';
        };

        string getPossibilityString(int r, int c) const override {
            return sub(r, c).getPoss();
        };

        void restoreState(const Frame &frame1, bool redoB=false) const;
        void move(Frame* frame2);
};

inline ostream& operator << ( ostream& out, Board& b ) {
    return b.print(out);
}