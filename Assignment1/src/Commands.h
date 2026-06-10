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

template<typename T>
struct InsertCommand {
    T element;
    std::size_t index;
};



struct RemoveCommand {
    std::size_t index;
};
struct ShowCommand {};
struct ClearCommand {};
struct ExitCommand {};
struct HelpCommand {};

template<typename T>
using Command = std::variant<
    AddCommand<T>,
    InsertCommand<T>,
    RemoveCommand,
    ShowCommand,
    ClearCommand,
    ExitCommand,
    HelpCommand
>;

#endif //ASSIGNMENT1_COMMANDS_H
