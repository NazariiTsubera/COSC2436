//
// Created by nazarii on 6/25/26.
//

#ifndef ASSIGNMENT11_PROGRAM_H
#define ASSIGNMENT11_PROGRAM_H
#include <optional>
#include <string>

#include "BST.h"
#include "Commands.h"

class Program {
public:
    Program();
    virtual ~Program();

    bool handle(Command & cmd);
    std::string getInput();
    std::optional<Command> parseCommand(const std::string &input);


    void run();

private:
    BST tree;
    std::string helpPrompt_;
};

#include "Program.hpp"

#endif //ASSIGNMENT11_PROGRAM_H
