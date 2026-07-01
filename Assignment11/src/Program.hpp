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
        "FIND <item>\n"
        "INSERT <item>\n"
        "DELETE <item>\n"
        "DELETE_TREE\n"
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

    if (operation == "FIND") {
        int item;

        if (!(ss >> item)) {
            throw std::invalid_argument("FIND requires an integer item");
        }

        std::string extra;
        if (ss >> extra) {
            throw std::invalid_argument("Too many arguments");
        }

        return FindCommand{item};
    }

    if (operation == "INSERT") {
        int item;

        if (!(ss >> item)) {
            throw std::invalid_argument("INSERT requires an integer item");
        }

        std::string extra;
        if (ss >> extra) {
            throw std::invalid_argument("Too many arguments");
        }

        return InsertCommand{item};
    }

    if (operation == "DELETE") {
        int item;

        if (!(ss >> item)) {
            throw std::invalid_argument("DELETE requires an integer item");
        }

        std::string extra;
        if (ss >> extra) {
            throw std::invalid_argument("Too many arguments");
        }

        return DeleteCommand{item};
    }

    if (operation == "DELETE_TREE") {
        std::string extra;

        if (ss >> extra) {
            throw std::invalid_argument("DELETE_TREE takes no arguments");
        }

        return DeleteTreeCommand{};
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
    if (auto command = std::get_if<FindCommand>(&cmd)) {
        if (tree.find(command->item)) {
            std::println("{} was found", command->item);
        }
        else {
            std::println("{} was not found", command->item);
        }

        tree.drawTree();
        return true;
    }

    if (auto command = std::get_if<InsertCommand>(&cmd)) {
        tree.insert(command->item);
        tree.drawTree();
        return true;
    }

    if (auto command = std::get_if<DeleteCommand>(&cmd)) {
        tree.remove(command->item);
        tree.drawTree();
        return true;
    }

    if (std::get_if<DeleteTreeCommand>(&cmd)) {
        tree.deleteTree();
        tree.drawTree();
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
