/**
 * @file e2.hpp
 * @author Murilo C. da Silva (murilosilva@itec.ufpa.br)
 * @brief A e2 library for QMAI-xApp
 * @version 0.0.1
 * @date 2024-05-13
 *
 * @copyright Copyright (c) 2024 Murilo Silva - All Rights Reserved
 *
 */

#pragma once

// local libs
#include "../include/logger.hpp"

// FlexRIC libs
#include "../../../../../src/xApp/e2_node_arr_xapp.h"
#include "../../../../../src/util/ngran_types.h"

// c++ libs
#include <string>
#include <map>

extern Logger logger;

namespace e2
{
    // Map to name of RAN functions
    std::map<ran_func_def_e, std::string> ranFuncMap{
        {ran_func_def_e::KPM_RAN_FUNC_DEF_E, "ORAN-E2SM-KPM"},
        {ran_func_def_e::RC_RAN_FUNC_DEF_E, "ORAN-E2SM-RC"},
        {ran_func_def_e::MAC_RAN_FUNC_DEF_E, "MAC_STATS_V0"},
        {ran_func_def_e::RLC_RAN_FUNC_DEF_E, "RLC_STATS_V0"},
        {ran_func_def_e::PDCP_RAN_FUNC_DEF_E, "PDCP_STATS_V0"},
        {ran_func_def_e::GTP_RAN_FUNC_DEF_E, "GTP_STATS_V0"},
        {ran_func_def_e::SLICE_RAN_FUNC_DEF_E, "SLICE_STATS_V0"},
        {ran_func_def_e::TC_RAN_FUNC_DEF_E, "TC_STATS_V0"},
    };

    /**
     * @brief Shows information about connected E2 nodes
     *
     * @param e2Nodes
     */
    void printE2NodesInfo(e2_node_arr_xapp_t &e2Nodes)
    {
        logger.info("Connected E2 nodes = " + std::to_string(e2Nodes.len));

        for (size_t i = 0; i < e2Nodes.len; i++)
        {
            // get ran type
            ngran_node_t ran_type = e2Nodes.n[i].id.type;

            // print E2 node infos
            logger.info(
                "E2 node " + std::to_string(i) + " => "
                                                 "nb_id " +
                std::to_string(e2Nodes.n[i].id.nb_id.nb_id) + " | " +
                "mcc " + std::to_string(e2Nodes.n[i].id.plmn.mcc) + " | " +
                "mnc " + std::to_string(e2Nodes.n[i].id.plmn.mnc) + " | " +
                "mnc_digit_len " + std::to_string(e2Nodes.n[i].id.plmn.mnc_digit_len) + " | " +
                "ran_type " + get_ngran_name(ran_type));

            // print CU | CU_UP | DU | MBMS ID
            if (!NODE_IS_MONOLITHIC(ran_type) && !NODE_IS_CU(ran_type)) // FIXME: problem printing CU ID
            {
                if (*e2Nodes.n[i].id.cu_du_id != 0)
                {
                    logger.info("E2 node " + std::to_string(i) + " => " +
                                get_ngran_name(ran_type) + " ID " + std::to_string(*e2Nodes.n[i].id.cu_du_id));
                }
            }

            // print supported RAN functions
            for (size_t j = 0; j < e2Nodes.n[i].len_rf; j++)
            {
                logger.debug("E2 node " + std::to_string(i) + " => " +
                             "RAN Function ID = " + std::to_string(e2Nodes.n[i].rf[j].id) + " | RAN Function Name = " +
                             ranFuncMap.at(e2Nodes.n[i].rf[j].defn.type));
            }
        }
    }

    // TODO: code KPM functions
}