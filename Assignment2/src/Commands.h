//
// Created by nazarii on 6/9/26.
//

#ifndef ASSIGNMENT1_COMMANDS_H
#define ASSIGNMENT1_COMMANDS_H
#include <variant>


template<typename T>
struct AddCommand {
    T element;
};

struct PopCommand {};
struct ShowCommand {};
struct ClearCommand {};
struct ExitCommand {};
struct HelpCommand {};
struct CountCommand {};

template<typename T>
using Command = std::variant<
    AddCommand<T>,
    ShowCommand,
    ClearCommand,
    ExitCommand,
    HelpCommand,
    CountCommand,
    PopCommand
>;

#endif //ASSIGNMENT1_COMMANDS_H
