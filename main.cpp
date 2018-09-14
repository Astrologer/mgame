#include <iostream>
#include "terminal.h"
#include "router.h"
#include "parser.h"


int main(int argc, char *arvg[]) {
    Router router(10);
    auto router_queue = router.get_queue();
    Terminal terminal(router_queue);
    Parser parser(router_queue);

    router.registr(terminal.get_type(), terminal.get_queue());
    router.registr(parser.get_type(), parser.get_queue());

    router.start();
    parser.start();
    terminal.start();

    terminal.listen();

    router_queue.get()->enqueue(Command::make_term(PARSE));
    router_queue.get()->enqueue(Command::make_term(TERMINAL));
    router_queue.get()->enqueue(Command::make_term(ROUTE));

    return(0);
}
