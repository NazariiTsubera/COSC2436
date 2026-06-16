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

inline int Program::fibonacci(int levels, int depth){

    for (int i = 1; i <= depth; i++) std::cout << "  ";
    std::cout << " - ";
    std::cout << "Entering level " << depth << std::endl;

    if (levels == 1) {
        return 1;
    }

    if (levels == 0) {
        return 0;
    }

    return fibonacci(levels - 1, depth + 1) + fibonacci(levels - 2, depth + 1);
}
