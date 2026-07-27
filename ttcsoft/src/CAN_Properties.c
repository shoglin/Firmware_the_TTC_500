#include "CAN_Properties.h"

// Генерация ID с битовой маской

void Generate_Group_IDs(ubyte1 index, ubyte4 *ptr_CMD, ubyte4 *ptr_FB,
                               ubyte4 *ptr_DIAG)
{
    ubyte4 base_cmd = 0x18FF00FAU;
    ubyte4 base_fb = 0x18FF0027U;
    ubyte4 base_diag = 0x18FF0027U;
    ubyte4 mask = 0x0000FF00U; // Биты 8-15

    *ptr_CMD = (base_cmd & ~mask) | ((ubyte4) index << 8);
    *ptr_FB = (base_fb & ~mask) | ((ubyte4) (index * 2) << 8);
    *ptr_DIAG = (base_diag & ~mask) | ((ubyte4) ((index * 2) + 1) << 8);
}

// Настрорйка кадра по дефолту и подстановка айдишника

void Init_CAN_Frame_Defaults(IO_CAN_DATA_FRAME *frame, ubyte4 id)
{
    frame->id = id;
    frame->id_format = IO_CAN_EXT_FRAME;
    frame->length = 8U;
    // data[8] обнулится или перезапишется перед отправкой
}

// Функции упаковки и распаковки

void Unpack_CMD(const ubyte1 *can_data, CMD_Values *cmd)
{
    cmd->config_Pin0 = can_data[0] & 0x07U;
    cmd->value_Pin0 = can_data[1];
    cmd->config_Pin1 = can_data[2] & 0x07U;
    cmd->value_Pin1 = can_data[3];
    cmd->config_Pin2 = can_data[4] & 0x07U;
    cmd->value_Pin2 = can_data[5];
    cmd->config_Pin3 = can_data[6] & 0x07U;
    cmd->value_Pin3 = can_data[7];
}

void Pack_FB(const FB_Values *fb, ubyte1 *can_data)
{
    can_data[0] = (ubyte1) (fb->val_Pin0 & 0xFFU);
    can_data[1] = (ubyte1) ((fb->val_Pin0 >> 8) & 0xFFU);
    can_data[2] = (ubyte1) (fb->val_Pin1 & 0xFFU);
    can_data[3] = (ubyte1) ((fb->val_Pin1 >> 8) & 0xFFU);
    can_data[4] = (ubyte1) (fb->val_Pin2 & 0xFFU);
    can_data[5] = (ubyte1) ((fb->val_Pin2 >> 8) & 0xFFU);
    can_data[6] = (ubyte1) (fb->val_Pin3 & 0xFFU);
    can_data[7] = (ubyte1) ((fb->val_Pin3 >> 8) & 0xFFU);
}

void Pack_DIAG(const DIAG_Values *diag, ubyte1 *can_data)
{
    can_data[0] = (ubyte1) (diag->val_Pin0 & 0xFFU);
    can_data[1] = (ubyte1) ((diag->val_Pin0 >> 8) & 0xFFU);
    can_data[2] = (ubyte1) (diag->val_Pin1 & 0xFFU);
    can_data[3] = (ubyte1) ((diag->val_Pin1 >> 8) & 0xFFU);
    can_data[4] = (ubyte1) (diag->val_Pin2 & 0xFFU);
    can_data[5] = (ubyte1) ((diag->val_Pin2 >> 8) & 0xFFU);
    can_data[6] = (ubyte1) (diag->val_Pin3 & 0xFFU);
    can_data[7] = (ubyte1) ((diag->val_Pin3 >> 8) & 0xFFU);
}

// Главная функция инициализации

IO_ErrorType Init_CAN_System(void)
{

    ubyte1 i;

    // 1. Инициализация Канала 0 (RX CMD + TX FB) на 250 кбит/с
    IO_CAN_Init(IO_CAN_CHANNEL_0, IO_CAN_BIT_250_KB, 0, 0, 0, 0);

    // 2. Инициализация Канала 1 (TX DIAG) на 250 кбит/с
    IO_CAN_Init(IO_CAN_CHANNEL_1, IO_CAN_BIT_250_KB, 0, 0, 0, 0);

    // 3. Настройка 24 групп
    for (i = 0; i < NUM_GROUPS; i++)
    {

        // Генерация уникальных ID
        Generate_Group_IDs(i, &g_groups[i].can.frame_CMD.id,
                           &g_groups[i].can.frame_FB.id,
                           &g_groups[i].can.frame_DIAG.id);

        // Заполнение полей кадра по дефолту (length=8, id_format=EXT)

        Init_CAN_Frame_Defaults(&g_groups[i].can.frame_CMD,
                                g_groups[i].can.frame_CMD.id);
        Init_CAN_Frame_Defaults(&g_groups[i].can.frame_FB,
                                g_groups[i].can.frame_FB.id);
        Init_CAN_Frame_Defaults(&g_groups[i].can.frame_DIAG,
                                g_groups[i].can.frame_DIAG.id);

        // Канал 0: Прием (CMD)

        IO_CAN_ConfigMsg(&g_groups[i].can.handle_CMD, IO_CAN_CHANNEL_0,
        IO_CAN_MSG_READ,
                         IO_CAN_EXT_FRAME, g_groups[i].can.frame_CMD.id,
                         0x1FFFFFFFU);

        // Канал 0: Передача (FB)

        IO_CAN_ConfigMsg(&g_groups[i].can.handle_FB, IO_CAN_CHANNEL_0,
        IO_CAN_MSG_WRITE,
                         IO_CAN_EXT_FRAME, g_groups[i].can.frame_FB.id, 0U);

        // Канал 1: Передача (DIAG)

        IO_CAN_ConfigMsg(&g_groups[i].can.handle_DIAG, IO_CAN_CHANNEL_1,
        IO_CAN_MSG_WRITE,
                         IO_CAN_EXT_FRAME, g_groups[i].can.frame_DIAG.id, 0U);

    }

    return IO_E_OK;
}

// Основной цикл приема и передачи

void Cyclic_CAN_Task(void)
{
    ubyte1 i;

    // Локальная переменная только для приема
    IO_CAN_DATA_FRAME rx_frame;

    for (i = 0; i < NUM_GROUPS; i++)
    {

        // Чтение (RX)

        if (IO_CAN_MsgStatus(g_groups[i].can.handle_CMD) == IO_E_OK)
        {
            if (IO_CAN_ReadMsg(g_groups[i].can.handle_CMD, &rx_frame) == IO_E_OK)
            {

                // Сверка ID и длины
                if ((rx_frame.length == 8U)
                        && (rx_frame.id == g_groups[i].can.frame_CMD.id))
                {
                    Unpack_CMD(rx_frame.data, &g_groups[i].cmd);
                    // Данные готовы: g_groups[i].cmd.config_Pin0, value_Pin0 и т.д.
                }
            }
        }

        // 2. Запись данных после снятия с пинов и конвертации (FB) на Канале 0

        // 1. Упаковываем

        Pack_FB(&g_groups[i].fb, g_groups[i].can.frame_FB.data);

        // 2. Отправляем (ID, length и id_format уже настроены при инициализации)
        IO_CAN_WriteMsg(g_groups[i].can.handle_FB, &g_groups[i].can.frame_FB);


        // 3. Запись диагностики (DIAG) на Канале 1

        // 1. Упаковываем
        Pack_DIAG(&g_groups[i].diag, g_groups[i].can.frame_DIAG.data);

        // 2. Отправляем
        IO_CAN_WriteMsg(g_groups[i].can.handle_DIAG,

        &g_groups[i].can.frame_DIAG);
    }
}
