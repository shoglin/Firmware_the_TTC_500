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

void VCU_SW_step(void)
{
    ubyte1 idx_grp;
    ubyte1 idx_pin;

    for (idx_grp = 0U; idx_grp < NUM_GROUPS; idx_grp++)
    {
        // 1. Read massages for this group
        Process_CAN_RX(idx_grp);

        // 2. Process all 4th pins in this group

        for (idx_pin = 0U; idx_pin < 4U; idx_pin++)
        {
            ubyte1 val_pin = Get_Pin_Value(&g_groups[idx_grp].current_cmd, idx_pin);

            // A. If working mode pin changed - deinit and init again

            if (Compare_Confs(idx_grp, idx_pin))
            {
                Pin_DeInit(idx_grp, idx_pin);
                Pin_Init(idx_grp, idx_pin, val_pin);
            }
            // B. If working mode pin not changed, but changed guidance value

            else if (Compare_Values(idx_grp, idx_pin))
            {
                Pin_Write_Value(idx_grp, idx_pin, val_pin);
            }

            // 3. Collection of measurements and writing to FB and DIAG
            Update_Pin_FB_and_DIAG(idx_grp, idx_pin);
        }

        // 4. Update old_cmd (old_cmd = current_cmd)

        Update_Old_CMD_Values(idx_grp);

        // 5. Cycling transmit massages FB and DIAG

        Process_CAN_TX(idx_grp);
    }
}

void VCU_SW_terminate(void)
{
}
