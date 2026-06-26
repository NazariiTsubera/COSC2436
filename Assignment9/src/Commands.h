//
// Created by nazarii on 6/9/26.
//

#ifndef ASSIGNMENT9_COMMANDS_H
#define ASSIGNMENT9_COMMANDS_H
#include <variant>
#include <string>

struct InsertCommand {
    std::string value;
};
struct InsertAlphaCommand {
    std::string value;
};
struct DeleteCommand {
    std::string value;
};
struct CountCommand {};
struct ClearCommand {};
struct ExitCommand {};


using Command = std::variant<
    InsertCommand,
    InsertAlphaCommand,
    ClearCommand,
    ExitCommand,
    DeleteCommand,
    CountCommand
>;

#endif //ASSIGNMENT9_COMMANDS_H
