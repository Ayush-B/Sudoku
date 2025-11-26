//=======================================================================
// Project: Implement the Game of a square in a Sudoku
// File: sudoku_error.hpp
// Author:  Ayush Bhusal & Nabin Bamma (September 2024)
// ======================================================================
#pragma once

#include "tools.hpp"

class SudokuError {
public:
    virtual ~SudokuError() = default;
    virtual void print() const {
        cerr << "An error occurred in the Sudoku game.\n";
        pr();
    }
    void pr() const{
        cerr << "Please check your input or the game state and try again.\n";
    }
};

// =====================================================
// Derived Exception Class for Stream Errors
// -----------------------------------------------------
// Handles issues related to file I/O such as missing files, EOF, or read errors.
class StreamError : public SudokuError {
public:
    std::string filename;

    StreamError(const std::string& file) : filename(file) {}
    virtual ~StreamError() = default;

    // Provides specific error message for file-related issues
    virtual void print() const {
        cerr << "\nStream error: Failed to open or read from the file: " << filename << "\n";
        pr();
    }
};

// =====================================================
// Derived Exception Class for Game Logic Errors. file: sudoku_error.hpp
// --------------------------------------------------- Game-related issues.
class GameLogicError : public SudokuError {
private:
    std::string details;
public:
    GameLogicError(const std::string& msg) : details(msg) {}
    virtual ~GameLogicError() = default;
    virtual void print() const {
        cerr << "Game logic error: " << details << "\n";
        pr();
    }
};

// =====================================================
// Derived Exception Class for Invalid Input Errors. file: sudoku_error.hpp
// --------------------------------------------------- Invalid input value.
class InvalidInputError : public GameLogicError {
private:
    std::string details;
public:
    InvalidInputError(const std::string& msg) : GameLogicError(msg), details(msg) {
    }
    virtual ~InvalidInputError() = default;
    void print() const {
        cerr << "Invalid Input Error: " << details;
        pr();
    }
};
