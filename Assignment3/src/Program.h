//
// Created by nazarii on 6/9/26.
//

#ifndef ASSIGNMENT1_CLI_H
#define ASSIGNMENT1_CLI_H
#include <optional>
#include <string>

#include "Stack.h"

struct ValidationResult {
    bool valid;
    std::optional<std::string> error = std::nullopt;
};

//T represents type of vector
class Program {
public:
    Program();
    virtual ~Program();

    std::string getInput();
    ValidationResult checkInput(const std::string& input);

    void run();

private:
    std::string helpPrompt_;
};

#include "Program.hpp"

#endif //ASSIGNMENT1_CLI_H
