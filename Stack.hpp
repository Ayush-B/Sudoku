//=======================================================================
// Project: Implement the Game of a square in a Sudoku
// File: stack.hpp
// Author:  Ayush Bhusal & Nabin Bamma (December 2024)
// ======================================================================
#pragma once

#include "Frame.hpp"
#include "tools.hpp"

class Stack : std::vector<Frame*> {
public:
    void push(Frame* frame1) {
        this->push_back(new Frame(*frame1));
    }

    void pop() {
        if (this->empty()) {
            throw GameLogicError("Cannot pop from an empty stack.");
        }
        std::cout << "Popping frame: " << this->back() << std::endl;
        delete this->back();
        //this->top()->print(cout);
        this->pop_back();
    }

    Frame* top() const {
        if (this->empty()) {
            throw GameLogicError("Stack is empty.");
        }
        cout<<this->back()<<endl;
        return this->back();
    }

    int size() const {
        int count = std::vector<Frame*>::size();
        //std::cout << "Stack size: " << count << std::endl;
        return count;
    }

    void zap() {
        std::cout << "Zapping stack..." << std::endl;
        while (!this->empty()) {
            std::cout << "Deleting frame: " << this->back() << std::endl;
            delete this->back();
            this->pop_back();
        }
    }

    ~Stack() {
        zap();
    }
};
