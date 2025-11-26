//=======================================================================
// Project: Implement the State of a square in a Sudoku
// File: cluster.cpp
// Author: Ayush Bhusal & Nabin Bamma (October 2024)
//=======================================================================
#include "cluster.hpp"
#include "square.hpp"

//-----------------------------------------------------------------------
Cluster::Cluster(ClusterType type, Square* sqArray[], short n)
    :type(type), n(n)
{
    squares = new Square*[n];
    for (int k = 0; k < n; ++k) {
        squares[k] = sqArray[k];
        squares[k]->addCluster(this); // Register this cluster in each square
    }
    // Debug output
    cout << "Cluster [" << toString(type) << "] created with squares: ";
    for (short c = 0; c < n; ++c) {
        squares[c]->print(cout);
    }
    cout << endl;
}

//-----------------------------------------------------------------------
Cluster::~Cluster() {
    delete[] squares;
    cerr << "Deleting Cluster [" << toString(type) << "]\n";
}

//-----------------------------------------------------------------------
void Cluster::
shoop(int bit) {
    // Validate that bit is within the valid range (1-9)
    if (bit < 1 || bit > 9) {
        throw InvalidInputError ("Error: Invalid value " + to_string(bit) +". Must be between '1' and '9'.\n");
    }

    // Iterate over each of the n Square pointers in the cluster
    for (int m = 0; m < n; ++m) {
        squares[m]->turnOff(bit);
    }
}

//-----------------------------------------------------------------------
ostream& Cluster::
print(ostream& out) const {
    //out << "Cluster [" << toString(type) << "]\n";
    for (int m = 0; m < n; ++m) {
        if (squares[m]) {  // Ensure the square is not null
            squares[m]->print(out);  // Call the print method of Square
        }
    }
    return out << "\n\n";
}

//-----------------------------------------------------------------------
const char* Cluster::
toString(const ClusterType type) {
    switch (type) {
        case ClusterType::ROW: return "Row";
        case ClusterType::COLUMN: return "Column";
        case ClusterType::BOX: return "Box";
        case ClusterType::HBOX: return "HBox";
        case ClusterType::VBOX: return "VBox";
        default: return "Unknown";
    }
}
