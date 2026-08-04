#ifndef PIN_INIT_H_
#define PIN_INIT_H_

#include "Pin_Settings.h"
#include "CAN_Properties.h"
#include "IO_DIO.h"
#include "IO_ADC.h"
#include "IO_PWD.h"
#include "IO_PVG.h"
#include "IO_PWM.h"
#include "IO_VOUT.h"

typedef enum
{
    PIN_MODE_UNUSED = 0,
    PIN_MODE_DI = 1,
    PIN_MODE_ADC = 2,
    PIN_MODE_PWD = 3,
    PIN_MODE_PVG = 4,
    PIN_MODE_DO = 5,
    PIN_MODE_PWM = 6,
    PIN_MODE_VOUT = 7
} Pin_modes_t;

extern void Pin_Init(ubyte1 group_idx, ubyte1 pin_idx, ubyte1 pin_value);

extern void Pin_DeInit(ubyte1 group_idx, ubyte1 pin_idx);

#endif /* PIN_INIT_H_ */
