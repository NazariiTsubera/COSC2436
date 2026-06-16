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

std::string Program::getInput() {
    std::print("> ");

    std::string input;
    std::getline(std::cin, input);
    return input;
}

void Program::run() {


    while (true) {
        std::string input = getInput();

        try {
            int result = evaluate(input);
            std::cout << input << " = " << result << std::endl;
        } catch (const std::invalid_argument& e) {
            std::cout << e.what() << std::endl;
        } catch (const std::out_of_range& e) {
            std::cout << e.what() << std::endl;
        }


    }
}

inline int Program::evaluate(const std::string &input) {
    Stack<int> stack;

    for (char i : input) {

        if (i >= '0' && i <= '9') {
            int num = i - '0';
            stack.push(num);
        }
        else if (i == '+') {
            int a = stack.pop();
            int b = stack.pop();
            stack.push(b + a);
        }
        else if (i == '-') {
            int a = stack.pop();
            int b = stack.pop();
            stack.push(b - a);
        }
        else if (i == '*') {
            int a = stack.pop();
            int b = stack.pop();
            stack.push(b * a);
        }
        else if (i == '/') {
            int a = stack.pop();
            int b = stack.pop();
            stack.push(b / a);
        }
        else {
            throw std::invalid_argument(std::string("Invalid input ") + i);
        }
    }

    int output = stack.pop();

    if (stack.size() > 0) {
        throw std::invalid_argument(std::string("Invalid input: To many numbers"));
    }

    return output;
}
