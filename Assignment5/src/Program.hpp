//
// Created by nazarii on 6/9/26.
//
#pragma once
#include "Program.h"

#include <iostream>
#include <print>
#include <sstream>


Program::Program(){
    this->helpPrompt_ = "Please enter your expression: ";
}

Program::~Program() {}

int Program::getInput() {
    std::print("> ");

    int input;
    std::cin >> input;
    return input;
}

void Program::run() {


    while (true) {
        int input = getInput();

        try {
            fibonacci(input);
        } catch (const std::invalid_argument& e) {
            std::cout << e.what() << std::endl;
        }


    }
}

inline void print(int depth, const std::string& msg) {
    for (int i = 1; i <= depth; i++) std::cout << "  ";
    std::cout << " - ";
    std::cout << msg << std::endl;
}

inline int Program::fibonacci(int levels, int depth){

    print(depth, "Entering level " + std::to_string(levels));


    if (levels == 1) {
        return 1;
    }

    if (levels == 0) {
        return 0;
    }


    int number = fibonacci(levels - 1, depth + 1) + fibonacci(levels - 2, depth + 1);


    print(depth, "Exiting level " + std::to_string(levels));

    return number;
}
