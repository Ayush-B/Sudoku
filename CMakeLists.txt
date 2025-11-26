cmake_minimum_required(VERSION 3.29)
project(Sudoku)

set(CMAKE_CXX_STANDARD 20)

add_executable(Sudoku main.cpp
        state.cpp
        state.hpp
        tools.cpp
        tools.hpp
        unittest1.cpp
        unittest1.hpp
        game.cpp
        game.hpp
        board.hpp
        board.cpp
        outputfile.hpp
        cluster.hpp
        cluster.cpp
        square.hpp
        square.cpp
        sudoku_error.hpp
        dboard.hpp
        dboard.cpp
        CanView.hpp
        Canvas.hpp
        Canvas.cpp
        MixedChar.hpp
        MixedChar.cpp
        Viewer.hpp
        Viewer.cpp
        GridChar.hpp
        GridChar.cpp
        Frame.hpp
        Stack.hpp
        tradBoard.cpp
        tradBoard.hpp
        sixyBoard.cpp
        sixyBoard.hpp
        Frame.cpp
)
