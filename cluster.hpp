//=======================================================================
// Project: Implement the State of a square in a Sudoku
// File: cluster.hpp
// Author: Ayush Bhusal & Nabin Bamma (October 2024)
//=======================================================================
#pragma once
#include "tools.hpp"

class Square;

//-----------------------------------------------------------------------
enum class ClusterType { ROW, COLUMN, BOX, DIAG, HBOX, VBOX };

//-----------------------------------------------------------------------
class Cluster {
    private:  //---------------------------------------------------------
        ClusterType type;    // Type of the clusters (row, column, box)
        Square** squares;    // Array of pointers to squares (dynamic size)
        short n{};             // Size of the cluster (e.g., 9 for 9x9 Sudoku)

    public:   //---------------------------------------------------------
        Cluster(ClusterType type, Square* sqArray[], short n);
        ~Cluster() ;

        void shoop(int bit);
        ostream& print(ostream& out) const;

        static const char* toString(ClusterType type);
};

//-----------------------------------------------------------------------
inline ostream& operator << (ostream& out, const Cluster& cl) {
    return cl.print(out);
}
