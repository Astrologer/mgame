#include "command.h"


std::unique_ptr<Command> Command::make_term(ModuleType type) {
    std::unique_ptr<Command> cmd(new Command());
    cmd.get()->dst = type;
    cmd.get()->src = SYSTEM;
    cmd.get()->command = TERM;
    return cmd;
} // Command::make_term
