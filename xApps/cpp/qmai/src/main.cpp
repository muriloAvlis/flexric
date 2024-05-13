// flexric libs
#include "../../../../../src/xApp/e42_xapp_api.h"

// c++ libs
#include <cassert>
#include <unistd.h>

// local libs
#include "logger.hpp"
#include "defer.hpp"
#include "e2.hpp"

// initialize xApp logger
Logger logger(Logger::Level::DEBUG, "QMAI-xApp");

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

    // clear data from e2 nodes when finished
    defer(free_e2_node_arr_xapp(&e2Nodes));

    // print e2 node informatios
    e2::printE2NodesInfo(e2Nodes);

    // xApp stop condition
    while (try_stop_xapp_api() == false)
    {
        usleep(1000); // 1 ms
    }

    logger.info("xApp completed successfully! :)");

    return EXIT_SUCCESS;
}