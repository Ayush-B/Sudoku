//=======================================================================
// Project: Implement the State of a square in a Sudoku
// File: state.cpp
// Author:  Ayush Bhusal & Nabin Bamma
// ======================================================================
#include "state.hpp"
#include "game.hpp"

//------------------------------------------------------------------
State::State(const char ch ) : value(ch) {
    // Check if non-zero digit
    if (isdigit(ch) & (ch!='0')) {
        poss = 0;
        fixed = true;
    }
    else if (ch=='-') {
        // 0x3fe: Binary 0000 0011 1111 1110 (all digits (1-9) are possible)
        // 0x23e: (9---54321)
        // 0x0f2: (--7654--1)
        poss = 0x3fe;
        fixed = false;
    }
    // Catch invalid input
    else InvalidInputError("Input should be either '-' or a non-zero digit");
}
//------------------------------------------------------------------
void State::
remove_poss(int bit) {
    if (bit < 1 || bit > 9) {
        throw InvalidInputError("Invalid bit value " + to_string(bit) + ". Must be between 1 and 9.\n");
    }

    // Use a bitmask to turn off the possibility of 'bit'
    unsigned short mask = 1 << bit;  // Create a mask with the bit set
    poss &= ~mask;  // Clear the bit in the possibilities
}
//------------------------------------------------------------------
void State::
rev_poss(const string& pos) {
    unsigned short newPoss = 0;  // To store the new possibilities as a bitmask
    for (char c : pos) {
        if (c >= '1' && c <= '9') {  // Only process valid digit characters
            int bit = c - '0';  // Convert the character to an integer (1-based)
            newPoss |= (1 << bit);  // Set the corresponding bit (1-based index)
        }
    }

    poss = newPoss;  // Update the poss field with the new bitmask

}


//------------------------------------------------------------------
void State::
mark(const char ch) {
    if (fixed) throw InvalidInputError("Cannot mark a fixed value.\n");

    if (poss == 0) throw InvalidInputError("Cannot mark without any possibility.\n");
    // Check if the input is a valid digit (1-9)
    if (ch == '-') value = ch;
    else if (isdigit(ch) && ch != '0') {
        value = ch;
        poss = 0;
    }

    // Reject invalid inputs, including '0'
    else throw InvalidInputError("Invalid input. Only digits 1-9 are allowed.\n");
}

//------------------------------------------------------------------
string State::getPoss() const {
    string pos1;
    for (int m=9; m>0; m--) {
        if (poss >> m & 1) {
            pos1 += to_string(m);
        }
        else {
            pos1 += "-";
        }
    }
    return pos1; // Return the string of possible values
}

//------------------------------------------------------------------
char State::getValue() const {
    if (isdigit(value)) {
        return value;
    }
    else {
        if (value == '-') {
            return '-';
        }
        cout<<"Error in val return"<<endl;
        return '-';
    }
}

//------------------------------------------------------------------
ostream& State::
print( ostream& out) const {
    // Print the value and fixed flag
    out << "Value: " << value;
    out << " | Fixed: " << fixed;

    // Print possibilities
    out<<" | Possibilities: ";
    for (int m=9; m>0; m--) {
        if (poss >> m & 1) out<< m;
        else out <<"-";
    }
    out<<"\n";
    return out;
}

