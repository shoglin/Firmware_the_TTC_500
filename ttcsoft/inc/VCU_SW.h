#ifndef RTW_HEADER_VCU_SW_h_
#define RTW_HEADER_VCU_SW_h_

#include "IO_Driver.h"
#include "IO_CAN.h"
#include "IO_POWER.h"
#include "Pin_Settings.h"
#include "CAN_Properties.h"

/* Using functions */

void VCU_SW_initialize(void);
void VCU_SW_terminate(void);

/* 1. ‘аза до TaskBegin: прием CAN и применение новой конфигурации */
void VCU_SW_pre_step(void);
/* 2. ‘аза внутри TaskBegin / TaskEnd: только регул€рный опрос датчиков */
void VCU_SW_step_io(void);

/* 3. ‘аза после TaskEnd: передача кадров текущей группы в CAN */
void VCU_SW_post_step(void);

#endif /* RTW_HEADER_VCU_SW_h_ */
