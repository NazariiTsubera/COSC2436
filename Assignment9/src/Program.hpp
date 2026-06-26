//
// Created by nazarii on 6/25/26.
//

#pragma once

#include <iostream>
#include <print>
#include <sstream>
#include <stdexcept>
#include <variant>

inline Program::Program() {
    this->helpPrompt_ =
        "Please enter one of following commands:\n"
        "INSERT <value>\n"
        "INSERT_ALPHA <value>\n"
        "DELETE <value>\n"
        "COUNT\n"
        "CLEAR\n"
        "EXIT\n";
}

inline Program::~Program() {}

inline std::string Program::getInput() {
    std::print("> ");

    std::string input;
    std::getline(std::cin, input);

    return input;
}

inline std::optional<Command> Program::parseCommand(const std::string& input) {
    std::istringstream ss(input);

    std::string operation;
    ss >> operation;

    if (operation.empty()) {
        return std::nullopt;
    }

    if (operation == "INSERT") {
        std::string value;

        if (!(ss >> value)) {
            throw std::invalid_argument("INSERT requires a value");
        }

        std::string extra;
        if (ss >> extra) {
            throw std::invalid_argument("Too many arguments");
        }

        return InsertCommand{value};
    }

    if (operation == "INSERT_ALPHA") {
        std::string value;

        if (!(ss >> value)) {
            throw std::invalid_argument("INSERT_ALPHA requires a value");
        }

        std::string extra;
        if (ss >> extra) {
            throw std::invalid_argument("Too many arguments");
        }

        return InsertAlphaCommand{value};
    }

    if (operation == "DELETE") {
        std::string value;

        if (!(ss >> value)) {
            throw std::invalid_argument("DELETE requires a value");
        }

        std::string extra;
        if (ss >> extra) {
            throw std::invalid_argument("Too many arguments");
        }

        return DeleteCommand{value};
    }

    if (operation == "COUNT") {
        std::string extra;

        if (ss >> extra) {
            throw std::invalid_argument("COUNT takes no arguments");
        }

        return CountCommand{};
    }

    if (operation == "CLEAR") {
        std::string extra;

        if (ss >> extra) {
            throw std::invalid_argument("CLEAR takes no arguments");
        }

        return ClearCommand{};
    }

    if (operation == "EXIT") {
        std::string extra;

        if (ss >> extra) {
            throw std::invalid_argument("EXIT takes no arguments");
        }

        return ExitCommand{};
    }

    return std::nullopt;
}

inline bool Program::handle(Command& cmd) {
    if (auto command = std::get_if<InsertCommand>(&cmd)) {
        list.insertFront(command->value);
        list.print();
        return true;
    }

    if (auto command = std::get_if<InsertAlphaCommand>(&cmd)) {
        list.insertAlpha(command->value);
        list.print();
        return true;
    }

    if (auto command = std::get_if<DeleteCommand>(&cmd)) {
        list.remove(command->value);
        list.print();
        return true;
    }

    if (std::get_if<CountCommand>(&cmd)) {
        std::cout << "Count: " << list.count() << std::endl;
        return true;
    }

    if (std::get_if<ClearCommand>(&cmd)) {
        list.clear();
        list.print();
        return true;
    }

    if (std::get_if<ExitCommand>(&cmd)) {
        std::println("Bye Bye!");
        return false;
    }

    return true;
}

inline void Program::run() {
    std::cout << helpPrompt_;

    while (true) {
        std::string input = getInput();
        std::optional<Command> command;

        try {
            command = parseCommand(input);
        }
        catch (const std::invalid_argument& e) {
            std::println("Invalid argument: {}", e.what());
            continue;
        }
        catch (const std::exception& e) {
            std::println("Exception: {}", e.what());
            continue;
        }

        if (!command.has_value()) {
            std::println("Invalid input");
            continue;
        }

        try {
            bool shouldContinue = handle(command.value());

            if (!shouldContinue) {
                break;
            }
        }
        catch (const std::out_of_range& e) {
            std::println("Out of range");
        }
        catch (const std::exception& e) {
            std::println("Exception: {}", e.what());
        }
    }
}