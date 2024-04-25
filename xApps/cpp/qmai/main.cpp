// flexric libs
#include "../../../../src/xApp/e42_xapp_api.h"
#include "../../../../src/util/ngran_types.h"

// c++ libs
#include <iostream>
#include <unistd.h>
#include <cassert>

using namespace std;

void print_e2_nodes_info(e2_node_arr_xapp_t e2Nodes)
{
    cout << "[qmai-xApp]: Showing E2 Nodes informations..." << endl;
    
    ngran_node_t ran_type;
    string ran_type_acronym;

    for (uint8_t i = 0; i < e2Nodes.len; i++ ) {     
        // get E2 Node type
        ran_type = e2Nodes.n[i].id.type;

        // print E2 node infos
        cout << "[qmai-xApp]: " <<
            "E2 Node " << unsigned(i) << " infos: " << 
            "RAN type " << get_ngran_name(ran_type) << " | " <<
            "nb_id " << e2Nodes.n[i].id.nb_id.nb_id << " | " <<
            "mcc " << e2Nodes.n[i].id.plmn.mcc << " | " <<
            "mnc " << e2Nodes.n[i].id.plmn.mnc << " | " <<
            "mnc_digit_len " << unsigned(e2Nodes.n[i].id.plmn.mnc_digit_len) << " | ";

        if (!NODE_IS_MONOLITHIC(ran_type)) {
            // print CU|DU|MBMS_STA ID
            ran_type_acronym = (NODE_IS_CU(ran_type) ? "CU" :
                                      (NODE_IS_DU(ran_type) ? "DU" :
                                      (NODE_IS_MBMS(ran_type) ? "MBMS_STA" :
                                      "Unknown type")));
            if (e2Nodes.n[i].id.cu_du_id != nullptr) {
                cout << ran_type_acronym << " ID " << *(e2Nodes.n[i].id.cu_du_id) << endl;
            } else {
                cout << ran_type_acronym << " ID is unknown" << endl;
            }
        }

        // print RAN Functions supporteds
        cout << "[qmai-xApp]: E2 Node " << unsigned(i) << " support the following functions IDs: ";
        for (size_t j = 0; j < e2Nodes.n[i].len_rf; j++) {
            cout << e2Nodes.n[i].rf[j].id << " ";
        }
        cout << endl;
    }
}

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

    // print connected e2 nodes
    cout << "[qmai-xApp]: Connected E2 Nodes = " << unsigned(e2Nodes.len) << endl;

    print_e2_nodes_info(e2Nodes);

    // xApp stop condition
    while (try_stop_xapp_api() == false)
    {
        usleep(1000);
    }
    
    // clear xApp data
    free_e2_node_arr_xapp(&e2Nodes);

    cout << "[qmai-xApp]: xApp successfully finalized!" << endl;
    return 0;
}