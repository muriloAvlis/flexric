// flexric libs
#include "../../../../src/xApp/e42_xapp_api.h"

// c++ libs
#include <iostream>
#include <unistd.h>
#include <cassert>


using namespace std;

int main(int argc, char* argv[]) 
{
    // xApp args
    fr_args_t args = init_fr_args(argc, argv);
    
    // init xApp
    init_xapp_api(&args);
    sleep(1);

    // get e2Nodes
    e2_node_arr_xapp_t e2Nodes = e2_nodes_xapp_api();

    assert(e2Nodes.len > 0);

    cout << "[qmai-xApp]: Connected E2 Nodes: " << unsigned(e2Nodes.len) << endl;

    // xApp stop condition
    while (try_stop_xapp_api() == false)
    {
        usleep(1000);
    }
    
    // clear xApp data
    free_e2_node_arr_xapp(&e2Nodes);

    
    cout << "[qmai-xApp]: Finishing xApp..." << endl;
    return 0;
}