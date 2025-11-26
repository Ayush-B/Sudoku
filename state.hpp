//=======================================================================
// Project: Implement the State of a square in a Sudoku
// File: state.h
// Author:  Ayush Bhusal & Nabin Bamma (September 2024)
// ======================================================================
#pragma once
#include "tools.hpp"
#include "cluster.hpp"
#include "sudoku_error.hpp"

class State {
    protected:   //---------------------------------------------------------
        unsigned short poss;    //2 bytes for digits (1-9)
        char value;                      //1 byte for '-' or a digit
        bool fixed = false;                      //1 byte for boolean

    public:   //---------------------------------------------------------
        State() =default;
        State( char ch );   // Construct State with a char parameter
        ~State() =default;

        void mark( char ch );
        void remove_poss(int bit);
        void rev_poss(const string &pos);
        ostream& print( ostream& out ) const;   // Print all data in the State

        char getValue() const;
        string getPoss() const;
        bool isFixed() const{ return fixed; };
};
inline ostream& operator << ( ostream& out, const State& s ) {
    return s.print(out);    // Connect State::print() to the << operator.
}

