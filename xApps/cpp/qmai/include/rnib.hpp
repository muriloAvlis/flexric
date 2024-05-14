/**
 * @file rnib.hpp
 * @author Murilo C. da Silva (murilosilva@itec.ufpa.br)
 * @brief The R-NIB library for QMAI-xApp
 * @version 0.0.1
 * @date 2024-05-13
 *
 * @copyright Copyright (c) 2024 Murilo Silva - All Rights Reserved
 *
 */

#pragma once

// FlexRIC libs
#include "../../../../../src/xApp/e2_node_arr_xapp.h"

// c/c++ libs
#include <map>
#include <string>

namespace rnib
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
    void printE2NodesInfo(e2_node_arr_xapp_t &e2Nodes);
}