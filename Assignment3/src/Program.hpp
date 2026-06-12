//
// Created by nazarii on 6/9/26.
//
#pragma once
#include "Program.h"

#include <iostream>
#include <print>
#include <sstream>
#include <variant>


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

        auto result = checkInput(input);

        if (result.valid) {
            std::cout << "Correct input!" << std::endl;
            continue;
        }

        if (result.error.has_value()) {
            std::cout << result.error.value() << std::endl;
        }
        else {
            std::cout << "Wrong input! " << std::endl;
        }

    }
}

ValidationResult Program::checkInput(const std::string& input) {
    Stack<char> inputStack;


    for (size_t i = 0; i < input.length(); i++) {
        auto character = input.at(i);

        if (character == '(' || character == '{' || character == '[') {
            inputStack.push(character);
        }

        else if (character == ')' || character == '}' || character == ']') {
            try {
                char lastPushed = inputStack.pop();

                if ((character == ')' && lastPushed != '(') ||
                    (character == ']' && lastPushed != '[') ||
                    (character == '}' && lastPushed != '{')) {
                    std::string error = std::string("Expected closing bracket for ") + lastPushed + ", but got " + character;
                    return {
                        false,
                        error
                    };
                }
            }
            catch (std::out_of_range& e) {
                std::string error = std::string("Too many ") + character;

                return {
                    false,
                    error
                };
            }
        }
    }

    if (inputStack.size() == 0) {
        return {
            true
        };
    }

    std::string error = std::string("Unmatched ") + inputStack.pop();

    return {
    false,
        error
    };
}
