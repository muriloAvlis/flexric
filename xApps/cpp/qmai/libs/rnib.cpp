/**
 * @file rnib.cpp
 * @author Murilo C. da Silva (murilosilva@itec.ufpa.br)
 * @brief The R-NIB library for QMAI-xApp
 * @version 0.0.1
 * @date 2024-05-13
 *
 * @copyright Copyright (c) 2024 Murilo Silva - All Rights Reserved
 *
 */

// header
#include "rnib.hpp"

// FlexRIC libs
#include "../../../../../src/xApp/e2_node_arr_xapp.h"
#include "../../../../../src/util/ngran_types.h"

// C/C++ libs
#include <string>

// extenal libs
#include "spdlog/spdlog.h"

namespace rnib
{
    void printE2NodesInfo(e2_node_arr_xapp_t &e2Nodes)
    {
        SPDLOG_INFO("Connected E2 nodes = {}", e2Nodes.len);

        for (size_t i = 0; i < e2Nodes.len; i++)
        {
            // get ran type
            ngran_node_t ran_type = e2Nodes.n[i].id.type;

            // print E2 node infos
            SPDLOG_INFO("E2 Node {} => nb_id {} | mcc {} | mnc {} | mnc_digit_len {} | ran_type {}",
                        i, e2Nodes.n[i].id.nb_id.nb_id, e2Nodes.n[i].id.plmn.mcc, e2Nodes.n[i].id.plmn.mnc,
                        e2Nodes.n[i].id.plmn.mnc_digit_len, get_ngran_name(ran_type));

            // print CU | CU_UP | DU | MBMS ID
            if (!NODE_IS_MONOLITHIC(ran_type) && !NODE_IS_CU(ran_type)) // FIXME: problem printing CU ID
            {
                if (*e2Nodes.n[i].id.cu_du_id != 0)
                {
                    SPDLOG_INFO("E2 Node {} => Type {} | ID {}", i, get_ngran_name(ran_type), *e2Nodes.n[i].id.cu_du_id);
                }
            }

            // print supported RAN functions
            for (size_t j = 0; j < e2Nodes.n[i].len_rf; j++)
            {
                SPDLOG_DEBUG("E2 Node {} => RAN function ID {} | RAN function name {}",
                             i, e2Nodes.n[i].rf[j].id, ranFuncMap.at(e2Nodes.n[i].rf[j].defn.type));
            }
        }
    }
}