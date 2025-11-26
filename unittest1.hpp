//=======================================================================
// Project: Test the State of a square in a Sudoku
// File: unittestv1.cpp
// Author:  Ayush Bhusal & Nabin Bamma
// ======================================================================
#pragma once
#include "state.hpp"
#include "tools.hpp"
#include "cassert"
#include "outputfile.hpp"
#include "square.hpp"
#include "board.hpp"
#include "outputfile.hpp"

void testState();
void testSquare(Square& sq);
void testBoard();
void testCluster();