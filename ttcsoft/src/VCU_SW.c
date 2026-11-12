#include "VCU_SW.h"
#include "VCU_SW_private.h"
#include "CAN_Properties.h"
#include "Pin_Settings.h"
#include "Pin_Init_DeInit.h"
#include "Pin_Gets_Val_Err.h"
#include "IO_POWER.h"

const float8 VCU_SW_RGND = 0.0;

// Helper function for init

void VCU_SW_initialize(void)
{
    // 1. Sensors supply 5Â

    (void)IO_POWER_Set(IO_SENSOR_SUPPLY_0, IO_POWER_ON);

    // 2. Supply

    (void)IO_POWER_Set(IO_INT_POWERSTAGE_ENABLE, IO_POWER_ON);

    // 3.Enabling safety keys for all 3 output groups

    (void)IO_POWER_Set(IO_INT_SAFETY_SW_0, IO_POWER_ON);
    (void)IO_POWER_Set(IO_INT_SAFETY_SW_1, IO_POWER_ON);
    (void)IO_POWER_Set(IO_INT_SAFETY_SW_2, IO_POWER_ON);

    // 4. Configuration pins map

    Pin_Properties();

    // 5.Can Init

    (void)Init_CAN_System_All();
}

// Function - step

// 1. Before TaskBegin: read CAN and update config

void VCU_SW_pre_step(void)
{
    ubyte1 idx_grp;
    ubyte1 idx_pin;

    // Read CAN for CAN0 channels and check changes configs

    for (idx_grp = 0U; idx_grp < NUM_GROUPS; idx_grp++)
    {
        Process_CAN_RX(idx_grp);
    }

    // Check changes configs some pins

    for (idx_grp = 0U; idx_grp < NUM_GROUPS; idx_grp++)
    {
        for (idx_pin = 0U; idx_pin < 4U; idx_pin++)
        {
            ubyte1 val_pin = Get_Pin_Value(&g_groups[idx_grp].current_cmd, idx_pin);

            // If current config changed - reinitialize

            if (Compare_Confs(idx_grp, idx_pin))
            {
                Pin_DeInit(idx_grp, idx_pin);
                Pin_Init(idx_grp, idx_pin, val_pin);
            }

            // If current config not changed, but changed value

            else if (Compare_Values(idx_grp, idx_pin))
            {
                Pin_Write_Value(idx_grp, idx_pin, val_pin);
            }
        }
        Update_Old_CMD_Values(idx_grp);
    }
}

// 2. In TaskBegin - only update FB and DIAG

void VCU_SW_step_io(void)
{
    ubyte1 idx_grp;
    ubyte1 idx_pin;

    for (idx_grp = 0U; idx_grp < NUM_GROUPS; idx_grp++)
    {
        for (idx_pin = 0U; idx_pin < 4U; idx_pin++)
        {
            Update_Pin_FB_and_DIAG(idx_grp, idx_pin);
        }
    }
}

// 3. After TaskBegin - only transmit massages

void VCU_SW_post_step(void)
{
    ubyte1 idx_grp;
    for (idx_grp = 0U; idx_grp < NUM_GROUPS; idx_grp++)
    {
        Process_CAN_TX(idx_grp);
    }
}
