//
// Created by nazarii on 6/25/26.
//

#ifndef ASSIGNMENT9_CLI_H
#define ASSIGNMENT9_CLI_H
#include <optional>
#include <string>

#include "Commands.h"
#include "DoublyLinkedList.h"

class Program {
public:
    Program();
    virtual ~Program();

    bool handle(Command & cmd);
    std::string getInput();
    std::optional<Command> parseCommand(const std::string &input);


    void run();

private:
    DoublyLinkedList list;
    std::string helpPrompt_;
};

#include "Program.hpp"

#endif //ASSIGNMENT9_CLI_H
