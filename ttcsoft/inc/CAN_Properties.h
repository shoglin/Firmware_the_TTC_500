#ifndef CAN_Properties_h_
#define CAN_Properties_h_

#include "IO_Driver.h"
#include "IO_CAN.h"

#define NUM_GROUPS 24U  // 24 группы (48 буферов на Канале 0, 24 на Канале 1)

// TTCшня структура

typedef struct
{
    ubyte1 Extended;
    ubyte1 Length;
    ubyte1 Remote;
    ubyte1 Error;
    ubyte4 ID;
    float8 Timestamp;
    ubyte1 Data[8];
} CAN_MESSAGE_BUS;

// Настройки CAN для одной группы

typedef struct
{
    ubyte2 handle_CMD;
    ubyte2 handle_FB;
    ubyte2 handle_DIAG;

    CAN_MESSAGE_BUS bus_CMD;
    CAN_MESSAGE_BUS bus_FB;
    CAN_MESSAGE_BUS bus_DIAG;
} CAN_Msg_Props;

// Данные команд (RX)
// Каждый параметр в отдельном байте. config занимает младшие 3 бита, 5 старших = резерв.

typedef struct
{
    ubyte1 config_Pin0;
    ubyte1 value_Pin0;
    ubyte1 config_Pin1;
    ubyte1 value_Pin1;
    ubyte1 config_Pin2;
    ubyte1 value_Pin2;
    ubyte1 config_Pin3;
    ubyte1 value_Pin3;
} CMD_Values;

// Данные обратной связи (TX)

typedef struct
{
    ubyte2 val_Pin0;
    ubyte2 val_Pin1;
    ubyte2 val_Pin2;
    ubyte2 val_Pin3;
} FB_Values;

// Данные диагностики (TX)
typedef struct
{
    ubyte2 val_Pin0;
    ubyte2 val_Pin1;
    ubyte2 val_Pin2;
    ubyte2 val_Pin3;
} DIAG_Values;

// Объединенная структура для удобного доступа ко всем данным группы

typedef struct
{
    CAN_Msg_Props can;
    CMD_Values cmd;
    FB_Values fb;
    DIAG_Values diag;
} GroupData_t;

// Массив всех 24 групп
GroupData_t g_groups[NUM_GROUPS];

// Генерация ID
extern void Generate_Group_IDs(ubyte1 index, ubyte4 *ptr_CMD, ubyte4 *ptr_FB,
                               ubyte4 *ptr_DIAG);

// Заполнение дефолтных полей CAN_MESSAGE_BUS
extern void Init_CAN_Bus_Defaults(CAN_MESSAGE_BUS *bus);

// Распаковка принятого CAN-сообщения в CMD_Values

extern void Unpack_CMD(const ubyte1 *can_data, CMD_Values *cmd);

// Упаковка FB_Values в массив байт

extern void Pack_FB(const FB_Values *fb, ubyte1 *can_data);

// Упаковка DIAG_Values в массив байт

extern void Pack_DIAG(const DIAG_Values *diag, ubyte1 *can_data);

// Функция инициализации

extern IO_ErrorType Init_CAN_System(void);

// Основной цикл приёма-передачи по CAN

extern void Cyclic_CAN_Task(void);

#endif                                 /* CAN_Properties_h_ */
