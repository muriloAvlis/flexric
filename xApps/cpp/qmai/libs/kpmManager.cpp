// FlexRIC libs
#include "../../../../../src/xApp/e2_node_arr_xapp.h"

// C/C++ libs
#include <pthread.h>

// local libs
#include "kpmManager.hpp"

// Report period
static u_int64_t gran_period_ms = 1000; // 1s

// Mutex
static pthread_mutex_t mutex;

static void print_ue_id(ue_id_e2sm_e type, ue_id_e2sm_t ue_id)
{
    switch (type)
    {
    case ue_id_e2sm_e::GNB_UE_ID_E2SM:
        break;
    case ue_id_e2sm_e::GNB_DU_UE_ID_E2SM:
        break;
    case ue_id_e2sm_e::GNB_CU_UP_UE_ID_E2SM:
        break;
    case ue_id_e2sm_e::NG_ENB_UE_ID_E2SM:
        break;
    case ue_id_e2sm_e::NG_ENB_DU_UE_ID_E2SM:
        break;
    case ue_id_e2sm_e::EN_GNB_UE_ID_E2SM:
        break;
    case ue_id_e2sm_e::ENB_UE_ID_E2SM:
        break;
    case ue_id_e2sm_e::END_UE_ID_E2SM:
        break;
    default:
        break;
    }
}