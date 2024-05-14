// flexric libs
#include "../../../../../src/xApp/e42_xapp_api.h"

// c++ libs
#include <cassert>
#include <unistd.h>
#include <string>
#include <iostream>

// local libs
#include "defer.hpp"
#include "rnib.hpp"

// extenal libs
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

void configureLogger(std::string xAppName)
{
    auto console = spdlog::stdout_color_mt("console");
    console->set_pattern("[%Y-%m-%d %H:%M:%S][" + xAppName + "]%^[%l]%$[%s:%#] %v");
    spdlog::set_default_logger(console);
}

int main(int argc, char *argv[])
{
    // get xApp log
    configureLogger("qmai-xapp");

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

    // print e2 node informations
    rnib::printE2NodesInfo(e2Nodes);

    // xApp stop condition
    while (try_stop_xapp_api() == false)
    {
        usleep(1000); // 1 ms
    }

    SPDLOG_INFO("xApp completed successfully! :)");

    return EXIT_SUCCESS;
}