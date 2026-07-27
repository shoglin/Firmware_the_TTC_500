#include "CAN_Properties.h"

// Генерация ID
static void Generate_Group_IDs(ubyte1 index, ubyte4 *ptr_CMD, ubyte4 *ptr_FB,
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

// Заполнение дефолтных полей CAN_MESSAGE_BUS
static void Init_CAN_Bus_Defaults(CAN_MESSAGE_BUS *bus)
{
    bus->Extended = 1U; // IO_CAN_EXT_FRAME
    bus->Length = 8U;
    bus->Remote = 0U;
    bus->Error = 0U;
}

// Распаковка принятого CAN-сообщения в CMD_Values
static void Unpack_CMD(const ubyte1 *can_data, CMD_Values *cmd)
{
    // Пин 0
    cmd->config_Pin0 = can_data[0] & 0x07U; // Оставляем только 3 младших бита
    cmd->value_Pin0 = can_data[1];         // Весь байт целиком

    // Пин 1
    cmd->config_Pin1 = can_data[2] & 0x07U;
    cmd->value_Pin1 = can_data[3];

    // Пин 2
    cmd->config_Pin2 = can_data[4] & 0x07U;
    cmd->value_Pin2 = can_data[5];

    // Пин 3
    cmd->config_Pin3 = can_data[6] & 0x07U;
    cmd->value_Pin3 = can_data[7];
}

// Упаковка FB_Values в массив байт

static void Pack_FB(const FB_Values *fb, ubyte1 *can_data)
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

// Упаковка DIAG_Values в массив байт

static void Pack_DIAG(const DIAG_Values *diag, ubyte1 *can_data)
{
    can_data[0] = (ubyte1) (diag->val_Pin0 & 0xFFU);
    can_data[1] = (ubyte1) ((diag->val_Pin0 >> 8) & 0xFFU);
    can_data[2] =

    (ubyte1) (diag->val_Pin1 & 0xFFU);
    can_data[3] = (ubyte1) ((diag->val_Pin1 >> 8) & 0xFFU);
    can_data[4] = (ubyte1) (diag->val_Pin2 & 0xFFU);
    can_data[5] = (ubyte1) ((diag->val_Pin2 >> 8) & 0xFFU);
    can_data[6] = (ubyte1) (diag->val_Pin3 & 0xFFU);
    can_data[7] = (ubyte1) ((diag->val_Pin3 >> 8) & 0xFFU);
}

// Функция инициализации

IO_ErrorType Init_CAN_System(void)
{
    // Заводим номер заиниченной группы

    ubyte1 i;

    // 1. Инициализация Канала 0 (RX CMD + TX FB) на 250 кбит/с) Вообще подумать: наверное, стоит вынести инит каналов, напрммер, в ert_main (??!!)
    IO_CAN_Init(IO_CAN_CHANNEL_0, IO_CAN_BIT_250_KB, 0, 0, 0, 0);

    // 2. Инициализация Канала 1 (TX DIAG) на 250 кбит/с)
    IO_CAN_Init(IO_CAN_CHANNEL_1, IO_CAN_BIT_250_KB, 0, 0, 0, 0);

    // 3. Настройка 24 групп
    for (i = 0; i < NUM_GROUPS; i++)
    {

        // Генерация уникальных ID
        Generate_Group_IDs(i, &g_groups[i].can.bus_CMD.ID,
                           &g_groups[i].can.bus_FB.ID,
                           &g_groups[i].can.bus_DIAG.ID);

        // Заполнение дефолтных полей
        Init_CAN_Bus_Defaults(&g_groups[i].can.bus_CMD);
        Init_CAN_Bus_Defaults(&g_groups[i].can.bus_FB);
        Init_CAN_Bus_Defaults(&g_groups[i].can.bus_DIAG);

        // Канал 0: Прием (CMD)

        IO_CAN_ConfigMsg(&g_groups[i].can.handle_CMD, IO_CAN_CHANNEL_0,
        IO_CAN_MSG_READ,
                         IO_CAN_EXT_FRAME, g_groups[i].can.bus_CMD.ID,
                         0x1FFFFFFFU);

        // Канал 0: Передача (FB)
        IO_CAN_ConfigMsg(&g_groups[i].can.handle_FB, IO_CAN_CHANNEL_0,
        IO_CAN_MSG_WRITE,
                         IO_CAN_EXT_FRAME, g_groups[i].can.bus_FB.ID, 0U);

        // Канал 1: Передача (DIAG)
        IO_CAN_ConfigMsg(&g_groups[i].can.handle_DIAG, IO_CAN_CHANNEL_1,
        IO_CAN_MSG_WRITE,
                               IO_CAN_EXT_FRAME, g_groups[i].can.bus_DIAG.ID,
                               0U);
    }

    return IO_E_OK;
}

// Основной цикл приёма-передачи по CAN

static void Cyclic_CAN_Task(void)
{
    // Заводим номер заиниченной группы

    ubyte1 i;

    // Задаём кадры

    IO_CAN_DATA_FRAME rx_frame;
    IO_CAN_DATA_FRAME tx_frame;

    // Предварительная инициализация дефолтных полей TX фрейма

    tx_frame.id_format = IO_CAN_EXT_FRAME;
    tx_frame.length = 8U;

    for (i = 0; i < NUM_GROUPS; i++)
    {


        // 1. Чтение (RX)

        if (IO_CAN_MsgStatus(g_groups[i].can.handle_CMD) == IO_E_OK)
        {
            if (IO_CAN_ReadMsg(g_groups[i].can.handle_CMD, &rx_frame) == IO_E_OK)
            {

                // Дополнительная проверка длины и ID (как в Simulink)
                if ((rx_frame.length == 8U)
                        && (rx_frame.id == g_groups[i].can.bus_CMD.ID))
                {

                    // Распаковываем сырые байты в структуру
                    Unpack_CMD(rx_frame.data, &g_groups[i].cmd);

                    // Теперь можно использовать:
                    // g_groups[i].cmd.config_Pin0 (0-7)
                    // g_groups[i].cmd.value_Pin0  (0-255)
                    // и так далее для всех 4 пинов этой группы
                }
            }
        }

        // 2. Запись обратной свящи (FB) на Канале 0

        // 1. Упаковываем  данные

        Pack_FB(&g_groups[i].fb, tx_frame.data);

        // 2. Задаем ID текущей группы

        tx_frame.id = g_groups[i].can.bus_FB.ID;

        // 3. Отправляем
        IO_CAN_WriteMsg(g_groups[i].can.handle_FB, &tx_frame);


        // 3. Запмсь диагностики (DIAG) на Канале 1

        // 1. Упаковываем  данные
        Pack_DIAG(&g_groups[i].diag, tx_frame.data);

        // 2. Задаем ID текущей группы
        tx_frame.id = g_groups[i].can.bus_DIAG.ID;

        // 3. Отправляем
        IO_CAN_WriteMsg(g_groups[i].can.handle_DIAG, &tx_frame);
    }
}
