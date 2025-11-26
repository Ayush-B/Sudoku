//=======================================================================
// Project: Implement the State of a square in a Sudoku
// File: outputfile.hpp
// Author:  Ayush Bhusal & Nabin Bamma (September 2024)
// ======================================================================
#pragma once
#include "tools.hpp"
//-----------------------------------------------------------------
class OutputFile {
private:
    std::ofstream out;
    std::streambuf* cerrBuf;  // Store original cerr buffer

    OutputFile() {
        out.open("../output.txt");
        // Redirect cerr to write to output.txt file as well
        cerrBuf = std::cerr.rdbuf();  // Save cerr buffer
        std::cerr.rdbuf(out.rdbuf());  // Redirect cerr to the file
    }
    ~OutputFile() {
        std::cerr.rdbuf(cerrBuf);  // Restore original cerr buffer
        out.close();
    }

public:
    static OutputFile& instance() {
        static OutputFile instance;
        return instance;
    }

    ostream& stream() {
        return out;
    }

    void write(const string& str) {
        out << str << endl;
    }

    void logError(const string& message) {
        out << "Error: " << message << endl;
        cerr << "Error: " << message << endl;  // Output to console
    }
};