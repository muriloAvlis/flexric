// flexric libs
#include "../../../../../src/xApp/e42_xapp_api.h"
#include "../../../../../src/util/ngran_types.h"

// c++ libs
#include <cassert>
#include <unistd.h>

// local libs
#include "logger.hpp"

// set log level
Logger logger(Logger::Level::DEBUG);

int main(int argc, char *argv[])
{
    // xApp args
    fr_args_t args = init_fr_args(argc, argv);

    // init xApp
    init_xapp_api(&args);
    sleep(1);

    // get e2Nodes
    e2_node_arr_xapp_t e2Nodes = e2_nodes_xapp_api();

    assert(e2Nodes.len > 0);

    // print e2 nodes count
    logger.debug("E2 Nodes QTD: " + std::to_string(e2Nodes.len));

    // xApp stop condition
    while (try_stop_xapp_api() == false)
    {
        usleep(1000); // 10 ms
    }

    // clear xApp data
    free_e2_node_arr_xapp(&e2Nodes);

    return EXIT_SUCCESS;
}