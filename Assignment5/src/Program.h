//
// Created by nazarii on 6/9/26.
//

#ifndef ASSIGNMENT1_CLI_H
#define ASSIGNMENT1_CLI_H
#include <optional>
#include <string>



class Program {
public:
    Program();
    virtual ~Program();

    int getInput();
    int fibonacci(int levels, int depth=0);

    void run();

private:
    std::string helpPrompt_;
};

#include "Program.hpp"

#endif //ASSIGNMENT1_CLI_H
