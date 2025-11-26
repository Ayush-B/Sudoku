//=======================================================================
// Project: Implement the State of a square in a Sudoku
// File: game.cpp
// Author:  Ayush Bhusal & Nabin Bamma
// ======================================================================
#include "game.hpp"

#include <memory>

#include "sudoku_error.hpp"
#include "dboard.hpp"
#include "sixyBoard.hpp"

//------------------------------------------------------------------
Game::Game(const char type, std::ifstream& file) : gtype(type), inFile(file) {
    char ch;
    const std::string validT = "tdsTDS"; // valid game types
    short n = 9;

    // Read first character from file for game type
    file >> ch;

    // Check if the file was read successfully
    if (!file) throw StreamError("Failed to read from file.");

    // Loop until a valid game type is provided
    while (validT.find(ch) == std::string::npos) {
        cerr << "Error:Received game type - " << ch << endl;
        cerr << "Please enter a valid game type (T, D, S, t, d, s): \n";
        cin >> ch; // Get user input for game type
    }

    // Valid game type found, assign it to gtype
    gtype = ch;

    // Dynamically allocate the appropriate board type
    if (tolower(gtype) == 'd') {
        board1 = new DiagBoard(gtype, file); // Diagonal board with 29 clusters
    } else if (tolower(gtype) == 't') {
        board1 = new TradBoard(gtype, file); // Regular board with 27 clusters
    } else if (tolower(gtype) == 's') {
        n=6;
        board1 = new SixyBoard(gtype, file);
    }
    else {
        throw StreamError("Invalid game type.");
    }

    gsize = n;
    // Initialize the Viewer
    fancyView = new Viewer(n,n,*board1);
}

//------------------------------------------------------------------
Game::~Game() {
    delete board1;   // Cleanup for Board or DiagBoard
    delete fancyView; // Cleanup for Viewer
}

//------------------------------------------------------------------
void Game::
run() {
    char choice;

    cout<<"Initial Board"<<endl;
    //board1->print(cout);
    fancyView->show((cout));
    int n = gsize;

    while (true) {
        try {
            choice = menu_c("Sudoku Game Menu", 7, menuItem, "MURTSDQ");

            if (choice == 'M'){
                int c;
                int r;
                char val;
                char comma;

                cout << "Enter row, column, and value as indicated: '1,6,7' :";
                cin >> r >> comma >> c >> comma >> val;
                if (comma != ',') throw InvalidInputError("Input must commas.\n");
                if (r > n or c > n) {
                    cout<<r<<c<<val<< gsize<<endl;
                    string msg = "Input must 1 to " + to_string(gsize) + " with val between 1-9.\n";
                    throw InvalidInputError(msg);
                }

                Square* squareX = &board1->sub(r,c);
                squareX->mark(val); // Mark the square with the value '7'

                Frame frame2(&board1->sub(1, 1),n);
                //frame2.print(cout);
                board1->move(&frame2);
            }
        }
        catch (const InvalidInputError& e) {
            e.print();
            continue;
        }

        switch (choice) {
            case 'M': // Mark
                cout<<"Board after marking the value"<<endl;
                //board1->print(cout);
                fancyView->show((cout));
                break;

            case 'U': // Undo
                cout << "Undoing last action..." << endl;
                undo();
                fancyView->show((cout));
                break;

            case 'R': // Redo
                cout << "Redoing last action..." << endl;
                redo();
                fancyView->show((cout));
                break;

            case 'T': // Save game
                int c1;
                int r1;
                char pos1;
                char comma1;
                cout << "Turn off the possibility?" << endl;
                cout << "Enter: r,c,possibility" << endl;
                cout<< "Example: 1,1,5" << endl;

                cout << "Enter row, column, and value as indicated: '1,6,7' :";
                cin >> r1 >> comma1 >> c1 >> comma1 >> pos1;
                if (comma1 != ',') throw InvalidInputError("Input must commas.\n");
                if (r1 > n || c1 > n) {
                    string msg = "Input must 1 to " + to_string(gsize) + " with val between 1-9.\n";
                    throw InvalidInputError(msg);
                }

                board1->sub(r1, c1).turnOff(pos1-'0');
                fancyView->show((cout));
            break;

            case 'S': // Save game
                cout << "Saving the game..." << endl;
                break;

            case 'D': // Restore game
                cout << "Restoring the game..." << endl;
                break;

            case 'Q': // Quit
                cout << endl << "Quitting..." << endl;
                return;  // Exit the run loop

            default:
                cout << "Invalid choice." << endl;
                break;
        }
    }
}

//------------------------------------------------------------------
void Game::undo() {
    cout<<"Printing undo1 stack..."<<endl;
    if (board1->unStack.size() <= 1) {  // We need at least 2 frames in undo stack (current state + previous)
        cout << "Nothing to undo."<< endl;
        return;
    }

    // Move the current state to the redo stack
    Frame* tempFrame = board1->unStack.top(); // Store top frame in a temporary variable
    board1->reStack.push(tempFrame);        // Push the temporary frame onto redo stack
    board1->unStack.pop();

    // Restore the board state from the updated undo stack
    Frame* undoFrame = board1->unStack.top(); // Get a reference to the new top frame
    board1->restoreState(*undoFrame); // Pass the address of the undoFrame
}

//------------------------------------------------------------------
void Game::redo() {
    if (board1->reStack.size() == 0) {  // If the redo stack is empty, nothing to redo
        cout<<"Nothing to redo."<<endl;
        return;
    }

    // Move the top of the redo stack to undo stack
    Frame* tempFrame = board1->reStack.top(); // Store top frame in a temporary variable
    board1->unStack.push(tempFrame);         // Push the temporary frame onto undo stack
    board1->reStack.pop();

    // Restore the board state from the updated undo stack
    Frame *redoFrame = board1->unStack.top(); // Get a reference to the new top frame
    board1->restoreState(*redoFrame, true); // Pass the address of the redoFrame
}



