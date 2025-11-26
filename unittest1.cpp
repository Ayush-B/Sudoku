//=======================================================================
// Project: Test the State of a square in a Sudoku
// File: unittestv1.cpp
// Author:  Ayush Bhusal & Nabin Bamma
// ======================================================================
#include "unittest1.hpp"

//-----------------------------------------------------------------------
void testState() {
    ostringstream oss;

    // Prior Information
    // cout<< "Note: This is screenshot to show what happens when program runs default."<<endl;
    cout<< "Note 2: Possibility is 0x3fe\n"<<endl;

    // Test 1: Constructor with '-' value
    cout << "Test 1: Testing Constructor with '-' value" << endl;
    const State nonFixedState('-');
    oss.str("");
    nonFixedState.print(oss);
    const string nonFixedExp =
        "Value: -"
        " | Fixed: 0"
        " | Possibilities: 987654321\n";

    // Print actual output
    cout << "Actual Output:\n" << oss.str() ;
    // Print Expected output
    cout << "Expected Output:\n" << nonFixedExp;
    assert(oss.str() == nonFixedExp);

    cout<<"Test 1 completed.\n\n";
    //-----------------------------------------------------------------------

    // Test 2: Constructor with fixed value '5'
    cout << "Test 2: Testing Constructor with fixed value '5'" << endl;
    const State fixedState('5');
    oss.str("");
    fixedState.print(oss);
    const string fixedExp =
        "Value: 5"
        " | Fixed: 1"
        " | Possibilities: ---------\n";

    // Print actual output
    cout << "Actual Output:\n" << oss.str();
    // Print Expected output
    cout << "Expected Output:\n" << fixedExp;
    assert(oss.str() == fixedExp);

    cout<<"Test 2 completed.\n\n";
    //-----------------------------------------------------------------------

    // Test 3: Constructor with fixed value '0'; Should be caught
    // cout << "Test 3: Testing State with fixed value of '0'" << endl;
    // const State StateZero('0');
    // oss.str("");
    // StateZero.print(oss);
    // const string ExpZero =
    //     "-------------------\n"
    //     " State Information \n"
    //     "-------------------\n"
    //     "Value: 5\n"
    //     "Fixed: 1\n"
    //     "Possibilities: ---------\n"
    //     "-------------------\n";
    //
    // // Print actual output
    // cout << "Actual Output:\n" << oss.str();
    // assert(oss.str() == ExpZero);
    //
    // cout<<"Test 3 completed.\n\n";
    //-----------------------------------------------------------------------

    // Test 4: Testing mark on non-fixed state
    cout << "Test 4: Testing mark on non-fixed state by trying to mark 3" << endl;
    State mutableState('-');
    mutableState.mark('3');
    oss.str("");
    mutableState.print(oss);
    const string markedExp =
        "Value: 3"
        " | Fixed: 0"
        " | Possibilities: ---------\n";

    // Print actual output
    cout << "Actual Output:\n" << oss.str();
    // Print Expected output
    cout << "Expected Output:\n" << markedExp;
    assert(oss.str() == markedExp);

    cout<<"Test 4 completed.\n\n";
    //-----------------------------------------------------------------------

    // Test 5: mark() function on fixed state (should not change)
    State immutableState('5');
    cout << "Test 5: Testing mark on fixed state by trying to mark 8" << endl;
    immutableState.mark('8');  // Should not change since already has value
    oss.str("");
    immutableState.print(oss);

    // Print actual output
    cout << "Actual Output:\n" << oss.str();
    // Print Expected output
    cout << "Expected Output:\n" << fixedExp;
    assert(oss.str() == fixedExp); // Should remain unchanged

    cout<<"Test 5 completed.\n\n";
    //-----------------------------------------------------------------------

    cout << "All P1 tests passed!" << endl;
}

void testSquare(Square& sq) {
    ostringstream oss;

    // Test 1: Constructor with digit '4'
    cout << "Test 1: Constructor with digit '4'\n";
    Square sq1('4', 1, 2);
    oss.str("");
    oss << sq1;
    const string exp1 =
        "Square [1,2]"
        " | Value: 4"
        " | Fixed: 1"
        " | Possibilities: ---------\n";
    cout << "Actual Output:\n" << oss.str();
    cout << "Expected Output:\n" << exp1;
    assert(oss.str() == exp1);

    cout<<"Test 1 completed.\n\n";
    //-----------------------------------------------------------------------

    // Test 2: Constructor with dash '-'
    cout << "Test 2: Constructor with dash '-'\n";
    Square sq2('-', 3, 4);
    oss.str("");
    oss << sq2;
    const string exp2 =
        "Square [3,4]"
        " | Value: -"
        " | Fixed: 0"
        " | Possibilities: 987654321\n";
    cout << "Actual Output:\n" << oss.str();
    cout << "Expected Output:\n" << exp2;
    assert(oss.str() == exp2);

    cout<<"Test 2 completed.\n\n";
    //-----------------------------------------------------------------------

    // Test 3: Marking square with digit '3' with Constructor of value "-"
    cout << "Test 3: Marking square with digit '3'\n";
    sq.mark('3');
    oss.str("");
    oss << sq;
    const string exp3 =
        "Square [5,6]"
        " | Value: 3"
        " | Fixed: 0"
        " | Possibilities: ---------\n";

    // Actual Output
    cout << "Actual Output:\n" << oss.str();
    // Expected output
    cout << "Expected Output:\n" << exp3;
    assert(oss.str() == exp3);

    cout<<"Test 3 completed.\n\n";
    //-----------------------------------------------------------------------

    // Test 4: Marking square already marked
    cout << "Test 4: Marking square already marked\n";
    sq.mark('5');
    oss.str("");
    oss << sq;

    // Actual output
    cout << "Actual Output:\n" << oss.str();
    // Expected Output: Should remain unchanged as it is already marked
    cout << "Expected Output:\n" << exp3;
    assert(oss.str() == exp3);

    cout<<"Test 4 completed. Should remain unchanged as it is already marked\n\n";
    //-----------------------------------------------------------------------

    // Test 5: Marking square with illegal input '0'
    cout << "Test 5: Marking square with illegal input '0'\n";
    sq2.mark('0');
    oss.str("");
    oss << sq2;

    // Actual output
    cout << "Actual Output:\n" << oss.str();
    // Expected Output: Should remain unchanged since '0' is an invalid input
    cout << "Expected Output:\n" << exp2;
    assert(oss.str() == exp2);

    cout<<"Test 4 completed. Should remain unchanged from test 3 since '0' is an invalid input\n\n";
    //-----------------------------------------------------------------------

    cout << "All P2 tests passed!\n";
}

//-----------------------------------------------------------------------
// Testcase for Board class
void testBoard() {
    // Use a reference to simplify access to the OutputFile instance
    OutputFile& oFile = OutputFile::instance();

    oFile.write("Board Test 1: Creating board with puz1");
    oFile.write("This should create a board of 9 x 9 grid");

    std::ifstream inFile("../puz1.txt");  // Open the test input file

    // Check if the file opened successfully
    if (!inFile.good()) {
        oFile.logError("Error opening puzzle file: puz1.txt");
        return; // Exit the test if the file cannot be opened
    }

    // Read the game type from the first line of the file
    char gType;
    inFile >> gType; // Assuming the first character indicates the game type

    Board board1(gType, inFile); // Create Board object with the read game type
    oFile.write("Board initialized successfully.");

    // Printing the Board using its print() method
    oFile.stream() << "Board details:\n";
    board1.print(oFile.stream()); // Print to the output file

    inFile.close();

    //-----------------------------------------------------------------------
    oFile.write("Board Test 1.1: Testing with board type s");
    oFile.write("This should create a board of 6 x 6 grid");

    std::ifstream inFile4("../puz4.txt");  // Open the test input file

    // Check if the file opened successfully
    if (!inFile4.good()) {
        oFile.logError("Error opening puzzle file: puz4.txt");
        return; // Exit the test if the file cannot be opened
    }

    inFile4 >> gType; // Assuming the first character indicates the game type

    Board board4('s', inFile4); // Create Board object with the read game type
    oFile.write("Board initialized successfully.");

    // Printing the Board using its print() method
    oFile.stream() << "Board details:\n";
    board4.print(oFile.stream()); // Print to the output file

    inFile4.close();
    //-----------------------------------------------------------------------

    // Test case to check for EOF after reading n² squares
    oFile.write("Board Test 2: Checking for EOF in puz2.txt (with extra rows)");

    std::ifstream inFile3("../puz2.txt");  // Open the test input file with more than 9 rows

    if (!inFile3.good()) {
        oFile.logError("Error opening puzzle file: puz2.txt");
        return; // Exit the test if the file cannot be opened
    }

    inFile3 >> gType; // Assuming the first character indicates the game type

    Board board3(gType, inFile3); // Create Board object with the read game type
    oFile.write("Board initialized successfully.");

    // Printing the Board using its print() method
    oFile.stream() << "Board details:\n";
    board3.print(oFile.stream()); // Print to the output file

    inFile3.close();
}

//-----------------------------------------------------------------------
// Test case for checking the functionality of the Cluster class
void testCluster() {
    // Get a reference to the OutputFile instance for logging results
    OutputFile& oFile = OutputFile::instance();

    oFile.write("Cluster Test: Checking the functionality of the shoop method in the Cluster class.");

    // Attempt to create a 9x9 Sudoku board from an input file
    ifstream inFile("../puz1.txt");

    // Check if the input file opened successfully
    if (!inFile.good()) {
        oFile.logError("Error: Unable to open the puzzle file: puz1.txt. Please check the file path.");
        return;
    }

    char gType;
    inFile >> gType; // Read the type of board from the file
    Board board1(gType, inFile); // Initialize the board with the specified type
    oFile.write("Board initialized successfully: The Sudoku board is now ready for testing.");

    // Display the initial state of the board
    oFile.stream() << "Initial Board State:\n";
    board1.print(oFile.stream()); // Print the board layout before any modifications

    //-----------------------------------------------------------------------
    // --- Test 1: Marking a square in Row 3 ---
    oFile.write("\n--- Test 1: Mark square at (3, 2) with '5' in Row 3 ---");
    Square& square1 = board1.sub(3, 2); // Get the square located at Row 3, Column 2
    square1.mark('5'); // Mark the square with the value '5'

    // Display the updated board state after marking
    oFile.stream() << "After marking square (3, 2) with '5', the updated board state is:\n";
    board1.print(oFile.stream());

    oFile.write("Expected Outcome: The digit '5' should not be possible in any other squares in Row 3.");

    //-----------------------------------------------------------------------
    // --- Test 2: Marking a square in Column 6 ---
    oFile.write("\n--- Test 2: Mark square at (1, 6) with '7' in Column 6 ---");
    Square& square2 = board1.sub(1, 6); // Get the square located at Row 1, Column 6
    square2.mark('7'); // Mark the square with the value '7'

    // Display the updated board state after marking
    oFile.stream() << "After marking square (1, 6) with '7', the updated board state is:\n";
    board1.print(oFile.stream());

    oFile.write("Expected Outcome: The digit '7' should not be possible in any other squares in Column 6.");

    //-----------------------------------------------------------------------
    // --- Test 3: Marking a square in the Center Box ---
    oFile.write("\n--- Test 3: Mark square at (4, 4) with '2' in the Center Box ---");
    Square& square3 = board1.sub(4, 4); // Get the square located at Row 4, Column 4
    square3.mark('2'); // Mark the square with the value '2'

    // Display the updated board state after marking
    oFile.stream() << "After marking square (4, 4) with '2', the updated board state is:\n";
    board1.print(oFile.stream());

    oFile.write("Expected Outcome: The digit '2' should not be possible in any other squares in the center 3x3 box.");

    //-----------------------------------------------------------------------
    // --- Test 4: Check for Board and Square ---
    // --- Print details of all clusters on the board (27 clusters) ---
    oFile.write("\n--- Test 4: Check for Board and Square. ---");
    oFile.write("\n--- Printing the states of all Clusters on the Board ---");
    oFile.stream() << "Overview of Clusters on the Board:\n";
    board1.print(oFile.stream()); // Print details of all clusters to verify their current state

    oFile.write("Cluster tests completed successfully: All tests were executed without errors.");
}


