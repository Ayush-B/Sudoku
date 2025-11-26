//=======================================================================
// Project: Implement the Game of a square in a Sudoku
// File: game.h
// Author:  Ayush Bhusal & Nabin Bamma (September 2024)
// ======================================================================
#pragma once
#include "tools.hpp"
#include "board.hpp"
#include "sudoku_error.hpp"
#include "Viewer.hpp"
#include "Stack.hpp"

//-----------------------------------------------------------------
class Game {
    private:  //---------------------------------------------------------
        const string menuItem[7] = { "M: Mark",  "U: Undo",
                                "R: Redo",  "T: TurnOff", "S: Save Game",
                                "D: Restore Game",  "Q: Quit and Discard Game"};

        char gtype{};      // game type- traditional(t), diagonal(d) or Sixy(s)
        short gsize{};     // game size
        ifstream& inFile;

        Board* board1;
        Viewer* fancyView;

    public:
        Game(char type, ifstream& file);
        ~Game();

        void run();  // Run method for displaying the menu and ask user input
        void undo();
        void redo();
};
