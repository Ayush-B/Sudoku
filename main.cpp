//=======================================================================
// Project: Implement the State of a square in a Sudoku
// File: main.cpp
// Author:  Ayush Bhusal & Nabin Bamma
// ======================================================================
#include "tools.hpp"
#include "game.hpp"
#include "unittest1.hpp"
#include "sudoku_error.hpp"  // Include the exception classes

//-----------------------------------------------------------------------
int main(int argc, char* argv[]){
    banner();

    try {
        if (argc != 2) StreamError(string("Usage: ") + argv[0] + " file.\n");
        cout << "Checking file " << argv[1] << endl;

        // File handling with StreamError exception
        ifstream in(argv[1]);
        if (!in.good()) StreamError(string(argv[1]));

        // Creating a game instance and running the game
        Game game1(' ', in);
        game1.run();
        in.close();
    }
    catch (const StreamError& e) {
        e.print();  // Specific stream error handling
    }
    catch (const GameLogicError& e) {
        e.print();  // Specific game logic error handling
    }
    catch (...) {
        cerr << "An unknown error occurred. Aborting.\n";  // Catch-all handler
    }

    bye();
    return 0;
}
