#ifndef RTW_HEADER_VCU_SW_h_
#define RTW_HEADER_VCU_SW_h_

#include "IO_Driver.h"
#include "IO_CAN.h"
#include "IO_POWER.h"
#include "Pin_Settings.h"
#include "CAN_Properties.h"

// Helper functions

void VCU_SW_initialize(void);
void VCU_SW_terminate(void);

// 1. Before TaskBegin: read CAN and update config

void VCU_SW_pre_step(void);

// 2. In TaskBegin - only update FB and DIAG

void VCU_SW_step_io(void);

// 3. After TaskBegin - only transmit massages

void VCU_SW_post_step(void);

#endif /* RTW_HEADER_VCU_SW_h_ */
