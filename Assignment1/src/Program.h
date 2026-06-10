//
// Created by nazarii on 6/9/26.
//

#ifndef ASSIGNMENT1_CLI_H
#define ASSIGNMENT1_CLI_H
#include <optional>
#include <string>

#include "Commands.h"
#include "Vector.h"

//T represents type of vector
template<typename T>
class Program {
public:
    Program();
    virtual ~Program();

    void printVector();
    bool handle(Command<T> & cmd);
    void help();
    std::string getInput();
    std::optional<Command<T>> parseCommand(const std::string &input);


    void run();

private:
    Vector<T> vector_;
    std::string helpPrompt_;
};

#include "Program.hpp"

#endif //ASSIGNMENT1_CLI_H
