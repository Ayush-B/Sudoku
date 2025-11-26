//=======================================================================
// Project: Implement the State of a square in a Sudoku
// File: state.h
// Author:  Ayush Bhusal & Nabin Bamma (September 2024)
// ======================================================================
#pragma once
#include "tools.hpp"
#include "state.hpp"

class Cluster;

//-------------------------------------------------------------------------
class Square : public State {
private:   //---------------------------------------------------------
    short row=0;           //short integer row of Square
    short col=0;           // short integers columns of Square
    vector<Cluster*> clusters; // Vector to store clusters

public:   //---------------------------------------------------------
    Square() =default;
    Square( char ch, short r, short c ) : State(ch), row(r), col(c) {
        cerr << "Square[" << row << "," << col << "] created.";
    }
    ~Square() {
        cerr << "Deleting Square[" << row << "," << col << "]\n";
    };

    void mark( char ch, bool shp = true);
    void addCluster(Cluster* cluster) {clusters.push_back(cluster);} // Add the cluster to the vector
    void turnOff(int n);
    void shoop(int bit);

    ostream& print( ostream& out ) const {
        //out << "Square [" << row << "," << col << "] | ";
        return State::print(out);
    }
};

inline ostream& operator << ( ostream& out, const Square& q ) {
    return q.print(out);
}