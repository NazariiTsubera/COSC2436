//
// Created by nazarii on 6/9/26.
//

#ifndef ASSIGNMENT1_CLI_H
#define ASSIGNMENT1_CLI_H
#include <optional>
#include <string>

#include "Commands.h"
#include "LinkedList.h"

//T represents type of vector
class Program {
public:
    Program();
    virtual ~Program();

    bool handle(Command & cmd);
    std::string getInput();
    std::optional<Command> parseCommand(const std::string &input);


    void run();

private:
    LinkedList list;
    std::string helpPrompt_;
};

#include "Program.hpp"

#endif //ASSIGNMENT1_CLI_H
