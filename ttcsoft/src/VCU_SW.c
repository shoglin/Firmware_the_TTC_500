#include "VCU_SW.h"

/* Function initial */

void VCU_SW_initialize(void)
{
    /* Supply sensors 5V */

    (void)IO_POWER_Set(IO_SENSOR_SUPPLY_0, IO_POWER_ON);

    /* Initial CAN */

    (void)Init_CAN_System_All();
}

/* Step-by-step execution */

void VCU_SW_step(void)
{
    /* 1. RX CAN messages */

    Process_CAN_RX_All();

    /* 2. TX CAN messages */
    Process_CAN_TX_Scheduler();
}

void VCU_SW_terminate(void)
{
    /* For ending */
}
