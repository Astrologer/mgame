#include <iostream>
#include "router.h"


int main(int argc, char *argv[]) {
    std::shared_ptr<Queue<std::unique_ptr<Command>>> w1 = std::make_shared<Queue<std::unique_ptr<Command>>>();
    std::shared_ptr<Queue<std::unique_ptr<Command>>> w2 = std::make_shared<Queue<std::unique_ptr<Command>>>();

    Router router(5);
    std::shared_ptr<Queue<std::unique_ptr<Command>>> rt = router.get_queue();

    router.registr(TERMINAL, w1);
    router.registr(PARSE, w2);

    std::unique_ptr<Command> cmd_inp(new Command());
    std::unique_ptr<Command> cmd_par(new Command());
    std::unique_ptr<Command> cmd_rtr(new Command());

    cmd_inp.get()->dst = TERMINAL;
    cmd_inp.get()->command = TEST;

    cmd_par.get()->dst = PARSE;
    cmd_par.get()->command = CMD;

    cmd_rtr.get()->dst = ROUTE;
    cmd_rtr.get()->command = TERM;

    router.start();
    rt.get()->enqueue(std::move(cmd_inp));
    rt.get()->enqueue(std::move(cmd_par));
    rt.get()->enqueue(std::move(cmd_rtr));

    std::unique_ptr<Command> cmd1 = w1.get()->dequeue();
    std::unique_ptr<Command> cmd2 = w2.get()->dequeue();

    std::cout << cmd1.get()->command << "\n";
    std::cout << cmd2.get()->command << "\n";

    return 0;
}
