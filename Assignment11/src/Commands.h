//
// Created by nazarii on 6/25/26.
//

#ifndef ASSIGNMENT11_COMMANDS_H
#define ASSIGNMENT11_COMMANDS_H
#include <variant>

struct FindCommand {
    int item;
};
struct InsertCommand {
    int item;
};
struct DeleteCommand {
    int item;
};
struct DeleteTreeCommand {};
struct ExitCommand {};


using Command = std::variant<
    FindCommand,
    InsertCommand,
    DeleteCommand,
    DeleteTreeCommand,
    ExitCommand
>;

#endif //ASSIGNMENT11_COMMANDS_H
