//=======================================================================
// Project: Implement the State of a square in a Sudoku
// File: board.cpp
// Author:  Ayush Bhusal & Nabin Bamma
// ======================================================================
#include "board.hpp"

//------------------------------------------------------------------
Board::Board(const char type, ifstream& puzfile): puzfile(puzfile) {
    cerr << "Board constructor called." << endl;

    if (type == 't' or type == 'd') {
        cout<<"Board type is 't' or 'd'."<<endl;
        cout<<type<<endl;
        n = 9;//9*9 grid board
    }
    if (type == 's') {
        cout<<type<<endl;
        n = 6; //6*6 g rid board
    }

    // Dynamically allocate an array of n*n Squares
    try {
        bd = new Square[n * n];
    } catch (const std::bad_alloc&) {
        fatal("Memory allocation failed. Aborting.");
    }

    // Read Sudoku puzzle from input
    try {
        getPuzzle();   // Read puzzle from file
        // cout << "Board created." << endl;
        // cout << n << endl;
        Board::makeClusters(); // Create row, column, and box clusters
        cout<<"Clusters created."<<endl;
    } catch (const StreamError& e) {
        e.print();
    }

    cerr << "Board is constructed." << endl;
}

//------------------------------------------------------------------
void Board::
getPuzzle(){
    string line;
    char extraCh;

    //Skip the first line
    getline(puzfile, line);

    // Loop rows (1..n)
    for (short m = 1; m <= n; m++) {
        // Read each line from puzfile and store in line var
        getline(puzfile, line);

        cout<<line<<endl;

        // Loop characters in the line
        for (short k = 1; k <= n; k++) {
            char input = line[k - 1];
            // Check if ch is '-' or a digit
            if (input == '-' or isdigit(input)) {
                this->sub(m,k) = Square(input,m, k);
            }
            else fatal("Error: Invalid Input character in the file.");
        }

        // At end of a row, check if the next character is a newline
        if (line.length() != n) {
            fatal("Error: Incorrect row length in file. Expected " +
                to_string(n) + " characters, got " +to_string(line.length()));
        }
    }
    // Verify EOF after reading the file
    if (puzfile.get(extraCh)) fatal("Error: Not EOF after end.");
}

//------------------------------------------------------------------
void Board::
makeClusters() {
    for (short j = 0; j < n; ++j) {
        cout<<"Clusters being made"<<endl;
        createRow(j);      // Create 9 row clusters
        createColumn(j);   // Create 9 column clusters
    }
}

//------------------------------------------------------------------
void Board::
createRow(short j) {
    Square *rowSquares[n]; // Array to hold pointers to squares
    for (short k = 0; k < n; ++k) {
        rowSquares[k] = &sub(j + 1, k + 1); // Fill the array with pointers to squares in the row
    }
    clusters.push_back(new Cluster(ClusterType::ROW, rowSquares, n)); // Create and store the Cluster
    cout<<"Push cluster"<<endl;
}

//------------------------------------------------------------------
void Board::
createColumn(short k) {
    Square *columnSquares[n]; // Array to hold pointers to squares
    for (short j = 0; j < n; ++j) {
        columnSquares[j] = &sub(j + 1, k + 1); // Fill the array with pointers to squares in the column
    }
    clusters.push_back(new Cluster(ClusterType::COLUMN, columnSquares, n)); // Create and store the Cluster
}

//------------------------------------------------------------------
void Board::
move(Frame* frame2) {
    // Save the current state to the undo stack
    unStack.push(frame2);

    // Clear the redo stack as new moves invalidate redo history
    reStack.zap();
}

//------------------------------------------------------------------
void Board::
restoreState(const Frame &frame1, bool redoB) const {
    //frame1.print(cout);
    for (int p = 0; p < n*n; ++p) {
        if (!bd[p].isFixed()) {
            string prevPos = frame1.getPossAt(p);
            if (bd[p].getPoss() != prevPos){
                if (!redoB) bd[p].rev_poss(prevPos);
                bd[p].mark(frame1.getStateAt(p),redoB);
            }
        }
    }
}

//------------------------------------------------------------------
ostream& Board::
print(ostream &out) const {
    out << "\nClusters on the Board:" << endl;
    // Iterate through clusters in the pattern Row1, Column1, Row2, Column2, ..., Box1, Box2...
    for (int q = 0; q < clusters.size(); ++q) {
        if (q < 2 * n) {
            // Alternating between rows and columns
            if (q % 2 == 0) {
                out << "Row " << (q/ 2 + 1) << endl;
            } else {
                out << "Column " << (q / 2 + 1) << endl;
            }
        } else {
            if (q < 3 * n) {
                // Print boxes after rows and columns
                out << "Box " << (q - 2 * n + 1) << endl;
            }
            else {
                out << "Diagonal " << (q - 3 * n + 1) << endl;
            }
        }
        clusters[q]->print(out);  // Print cluster details
    }
    return out; // Return the output stream
}