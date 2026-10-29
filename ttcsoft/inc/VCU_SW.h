#ifndef RTW_HEADER_VCU_SW_h_
#define RTW_HEADER_VCU_SW_h_

#include "IO_Driver.h"
#include "IO_CAN.h"
#include "IO_POWER.h"
#include "Pin_Settings.h"
#include "CAN_Properties.h"

/* Using functions */

void VCU_SW_initialize(void);
void VCU_SW_step(void);
void VCU_SW_terminate(void);

#endif /* RTW_HEADER_VCU_SW_h_ */
