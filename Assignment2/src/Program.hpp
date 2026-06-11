//
// Created by nazarii on 6/9/26.
//
#pragma once
#include "Program.h"

#include <iostream>
#include <print>
#include <sstream>

template<typename T>
Program<T>::Program() {
    this->helpPrompt_ = "Please enter one of following commands:\n"
    "ADD <value>\n"
    "DELETE <index>\n"
    "COUNT\n"
    "SHOW\n"
    "CLEAR\n"
    "EXIT\n";
}

template<typename T>
Program<T>::~Program() {}

template<typename T>
std::string Program<T>::getInput() {
    std::print("> ");

    std::string input;
    std::getline(std::cin, input);
    return input;
}

template<typename T>
std::optional<Command<T>> Program<T>::parseCommand(const std::string &input) {
    std::istringstream ss(input);

    std::string operation;
    ss >> operation;

    if (operation == "ADD") {
        T value;
        if (!(ss >> value)) {
            throw std::invalid_argument("Invalid input");
        }

        std::string extra;
        if (ss >> extra) {
            throw std::invalid_argument("Invalid input");
        }

        return AddCommand<T>{value};
    }

    if (operation == "DELETE") {
        std::string extra;
        if (ss >> extra) {
            throw std::invalid_argument("Invalid input");
        }

        return PopCommand{};
    }

    if (operation == "SHOW") {

        std::string extra;
        if (ss >> extra) {
            throw std::invalid_argument("Invalid input");
        }

        return ShowCommand{};
    }


    if (operation == "CLEAR") {
        std::string extra;
        if (ss >> extra) {
            throw std::invalid_argument("Invalid input");
        }
        return ClearCommand{};
    }

    if (operation == "COUNT") {
        std::string extra;
        if (ss >> extra) {
            throw std::invalid_argument("Invalid input");
        }
        return CountCommand{};
    }

    if (operation == "HELP") {
        std::string extra;
        if (ss >> extra) {
            throw std::invalid_argument("Invalid input");
        }
        return HelpCommand{};
    }

    if (operation == "EXIT") {
        return ExitCommand{};
    }


    return std::nullopt;
}

template<typename T>
void Program<T>::printQueue() {

    std::cout << std::endl << "[";
    //TODO: Switch to iterator
    for (int i = 0; i < queue_.size(); i++) {
        std::cout << queue_.get(i);

        if (i < queue_.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;
}


template<typename T>
bool Program<T>::handle(Command<T> &cmd) {
    if (auto command = std::get_if<AddCommand<T>>(&cmd)) {
        queue_.add(command->element);
        printQueue();
        return true;
    }

    if (auto command = std::get_if<PopCommand>(&cmd)) {
        queue_.pop();
        printQueue();
        return true;
    }

    if (auto command = std::get_if<ClearCommand>(&cmd)) {
        queue_.clear();
        printQueue();
        return true;
    }

    if (auto command = std::get_if<ShowCommand>(&cmd)) {
        printQueue();
        return true;
    }

    if (auto command = std::get_if<ExitCommand>(&cmd)) {
        std::print("Bye Bye!");
        exit(0);
    }

    if (auto command = std::get_if<HelpCommand>(&cmd)) {
        help();
        return true;
    }

    if (auto command = std::get_if<CountCommand>(&cmd)) {
        std::cout << std::endl;
        std::cout << "Count: " << queue_.size() << std::endl;
        return true;
    }

    return false;
}

template<typename T>
void Program<T>::help() {
    std::cout << std::endl << helpPrompt_ << std::endl;
}

template<typename T>
void Program<T>::run() {

    help(); // initial

    while (true) {
        std::string input = getInput();
        std::optional<Command<T>> command;
        try {
             command = parseCommand(input);
        }
        catch (std::invalid_argument &e) {
            std::println("Invalid argument");
            continue;//skip iteration
        }
        catch (std::exception &e) {
            std::println("Exception: {}", e.what());
            continue;
        }

        if (!command.has_value()) {
            std::println("Invalid input");
            continue;
        }

        try {
            handle(command.value());
        }
        catch (std::out_of_range &e) {
            std::println("Out of range");
        }
        catch (std::exception &e) {
            std::println("Exception: {}", e.what());
        }

    }
}