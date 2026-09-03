/*
 * File: VCU_SW.c
 *
 * Code generated for Simulink model 'VCU_SW'.
 *
 * Model version                  : 2.3
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Tue Jul 14 11:26:00 2026
 *
 * Target selection: ttc_500_series.tlc
 * Embedded hardware selection: Texas Instruments->TMS570 Cortex-R4
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "VCU_SW.h"
#include "VCU_SW_private.h"
#include "IO_ADC.h"

const float8 VCU_SW_RGND = 0.0; /* float8 ground */

/* Step function */
void VCU_SW_step(void)
{
    ubyte1 idx_grp;

    for (idx_grp = 0; idx_grp < NUM_GROUPS; idx_grp++)
    {
        // 1. Читаем новое CAN-сообщение для этой группы
        Process_CAN_RX(idx_grp);

        // 2. Обрабатываем каждый из 4-х пинов в группе
        ubyte1 idx_pin;

        for (idx_pin = 0; idx_pin < 4; idx_pin++)
        {
            // Получаем текущее значение пина
            ubyte1 val_pin = Get_Pin_Value(&g_groups[idx_grp].current_cmd, idx_pin);

            if (Compare_Confs(idx_grp, idx_pin))
            {
                // Конфигурация поменялась — нужно переинициализировать пин
                Pin_DeInit(idx_grp, idx_pin);
                Pin_Init(idx_grp, idx_pin, val_pin);
            }

            // 3. Обновляем FB и DIAG для пина
            Update_Pin_FB_and_DIAG(idx_grp, idx_pin);
        }

        // 4. Синхронизируем old_cmd с current_cmd после обработки всех пинов
        // Без этого Compare_Confs будет всегда возвращать true!
        Update_Old_CMD_Values(idx_grp);

        // 5. Отправляем FB и DIAG по CAN
        Process_CAN_TX(idx_grp);
    }
}

/* Model initialize function */
void VCU_SW_initialize(void)
{

    /* Turning the POWER_SUPPLY_0 */
    IO_POWER_Set(IO_SENSOR_SUPPLY_0, IO_POWER_ON);

    Init_CAN_System_All();
}

/* Model terminate function */
void VCU_SW_terminate(void)
{
    /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
