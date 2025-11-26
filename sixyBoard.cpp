//=======================================================================
// Project: Implement the State of a square in a Sudoku
// File: cluster.cpp
// Author: Ayush Bhusal & Nabin Bamma (October 2024)
//=======================================================================
#include "sixyBoard.hpp"

//-----------------------------------------------------------------------
// Method to iterate and create all vertical boxes (VBoxes)
void SixyBoard::mkVBoxes() {
    for (short cStart = 0; cStart < n; cStart += 2) {
        cVBox(cStart, 0); // Create vertical box cluster for each segment
        cVBox(cStart, 3);
    }
}

//-----------------------------------------------------------------------
// Method to create a single VBox cluster
void SixyBoard::cVBox(short cStart, short rStart) {
    Square* vboxSq[n]; // Array to hold pointers to squares
    short index = 0;

    for (short row = rStart; row < rStart+3; ++row) {
        for (short col = cStart; col < cStart + 2; ++col) {
            vboxSq[index++] = &sub(row + 1, col + 1); // Fill with pointers
            //cout<<"cVBox"<<row<<col<<endl;
        }
    }

    clusters.push_back(new Cluster(ClusterType::VBOX, vboxSq, n)); // Store the cluster
}

//-----------------------------------------------------------------------
// Method to iterate and create all horizontal boxes (HBoxes)
void SixyBoard::mkHBoxes() {
    for (short rStart = 0; rStart < n; rStart += 2) {
        cHBox(rStart, 0); // Create horizontal box cluster for each segment
        cHBox(rStart, 3); // Create horizontal box cluster for each segment
    }
}

//-----------------------------------------------------------------------
// Method to create a single HBox cluster
void SixyBoard::cHBox(short rStart, short cStart) {
    Square* hboxSq[n]; // Array to hold pointers to squares
    short index = 0;

    for (short row = rStart; row < rStart + 2; ++row) {
        for (short col = cStart; col < cStart + 3; ++col) {
            hboxSq[index++] = &sub(row + 1, col + 1); // Fill with pointers
            //cout<<"cHBox"<<row<<col<<endl;
        }
    }
    clusters.push_back(new Cluster(ClusterType::HBOX, hboxSq,n)); // Store the cluster
}
