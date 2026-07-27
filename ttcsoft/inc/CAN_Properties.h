#ifndef CAN_Properties_h_
#define CAN_Properties_h_

#include "IO_Driver.h"
#include "IO_CAN.h"

#define NUM_GROUPS 24U  // 24 группы

// Данные команд (RX)

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

// Свойства CAN для одной группы

typedef struct
{
    ubyte2 handle_CMD;
    ubyte2 handle_FB;
    ubyte2 handle_DIAG;

    // Храним фреймы, чтобы в цикле менять только data и вызывать WriteMsg

    IO_CAN_DATA_FRAME frame_CMD;  // Для сверки ID при приеме
    IO_CAN_DATA_FRAME frame_FB;   // Готовый шаблон для отправки
    IO_CAN_DATA_FRAME frame_DIAG; // Готовый шаблон для отправки

} CAN_Msg_Props;

// Объединенная структура для удобного доступа ко всем данным группы

typedef struct
{
    CAN_Msg_Props can;
    CMD_Values cmd;
    FB_Values fb;
    DIAG_Values diag;
} GroupData_t;

// Глобальный массив всех 24 групп

GroupData_t g_groups[NUM_GROUPS];

// Генерация ID с битовой маской

extern void Generate_Group_IDs(ubyte1 index, ubyte4 *ptr_CMD, ubyte4 *ptr_FB,
                               ubyte4 *ptr_DIAG);

// Настройка кадра по дефолту и подстановка айдишника

extern void Init_CAN_Frame_Defaults(IO_CAN_DATA_FRAME *frame, ubyte4 id);

// Функции упаковки и распаковки

extern void Unpack_CMD(const ubyte1 *can_data, CMD_Values *cmd);

extern void Pack_FB(const FB_Values *fb, ubyte1 *can_data);

extern void Pack_DIAG(const DIAG_Values *diag, ubyte1 *can_data);

// Главная функция инициализации

extern IO_ErrorType Init_CAN_System(void);

// Основной цикл приема и передачи

extern void Cyclic_CAN_Task(void);

#endif                                 /* CAN_Properties_h_ */
