#include "APDB.h"
#include "IO_Driver.h"
#include "IO_RTC.h"
#include "IO_Power.h"
#include "VCU_SW.h"

#define MAJOR_NUMBER        0
#define MINOR_NUMBER        0
#define REVISION_NUMBER     1
#define STEP_SIZE           10000   /* Base step: 10 000 mks (10 ms) */

/* For TTC-Downloader */

#pragma SET_DATA_SECTION (".APDB_SEC")

volatile const BL_APDB Apdb_t = {
  APDB_VERSION,        /* APDB version                                        */

  { 0 },               /* Flash date (provided by TTC-Downloader)             */

  /* Build date                                          */
  { ((((RTS_TTC_FLASH_DATE_YEAR) & 0x0FFF) << 0) |
     (((RTS_TTC_FLASH_DATE_MONTH) & 0x0F ) << 12) |
     (((RTS_TTC_FLASH_DATE_DAY) & 0x1F ) << 16) |
     (((RTS_TTC_FLASH_DATE_HOUR) & 0x1F ) << 21) |
     (((RTS_TTC_FLASH_DATE_MINUTE) & 0x3F ) << 26)) },
  0,                   /* Node type                                           */
  0,                   /* CRC start address (provided by TTC-Downloader)      */
  0,                   /* code size (provided by TTC-Downloader)              */
  0,                   /* Legacy application CRC (provided by TTC-Downloader) */
  0,                   /* Application CRC (provided by TTC-Downloader)        */
  1,                   /* Node number                                         */
  0,                   /* CRC seed (provided by TTC-Downloader)               */
  0,                   /* Flags                                               */
  0,                   /* Hook 1                                              */
  0,                   /* Hook 2                                              */
  0,                   /* Hook 3                                              */
  APPL_START,          /* Main address, i.e., application entry point         */

  { 0, 1 },            /* CAN download ID (standard format, ID 0x1)           */

  { 0, 2 },            /* CAN upload ID (standard format, ID 0x2)             */
  0,                   /* Legacy header CRC (provided by TTC-Downloader)      */

  /* Application version (major.minor.revision)          */
  ((((ubyte4)REVISION_NUMBER) << 0) |
   (((ubyte4) MINOR_NUMBER) << 16) |
   (((ubyte4) MAJOR_NUMBER) << 24)),
  250,                     /* CAN baud rate in kbps                           */
  0,                   /* CAN channel                                         */
  0,                   /* Password (disable password protection)              */
  0,                   /* Magic seed                                          */

  { 10, 100, 30, 200 },/* Target IP address                                   */

  { 255, 255, 0, 0 },  /* Subnet mask                                         */

  { 239, 0, 0, 1 },    /* Multicast IP address                                */
  0,                   /* Debug key                                           */
  0,                   /* Automatic baud rate detection timeout               */
  0x00,                /* Manufacturer ID                                     */
  0x00,                /* Application ID                                      */

  { 0 },               /* Reserved, must be set to zero                       */
  0                    /* Header CRC (provided by TTC-Downloader)             */
};

#pragma SET_DATA_SECTION()

static ubyte4 timestamp = 0;

void task(void)
{
    /* Task function for IO Driver. This function shall be called at the beginning of the task. */

    IO_Driver_TaskBegin();

    /* Executing a program step */

    VCU_SW_step();

    /* Task function for IO Driver. This function shall be called at the end of the task. */

    IO_Driver_TaskEnd();

    /* Waiting for the completion of a 10 ms real-time interval */

    while (IO_RTC_GetTimeUS(timestamp) < STEP_SIZE) {
        /* wait */
    }
    timestamp += STEP_SIZE;
}

#pragma TASK(main);
void main(void)
{
    IO_DRIVER_SAFETY_CONF safety_conf;

    /* Initial Driver Safety Configuration */

    safety_conf.command_period     = STEP_SIZE;                           /* 10000 mks */
    safety_conf.window_size       = SAFETY_CONF_WINDOW_SIZE_100_PERCENT;
    safety_conf.reset_behavior     = SAFETY_CONF_RESETS_DISABLED;
    safety_conf.glitch_filter_time = 30;
    safety_conf.error_callback     = NULL;
    safety_conf.notify_callback    = NULL;

    /* 1. Global initialization of IO driver */

    (void)IO_Driver_Init(&safety_conf);

    /* 2. Function initial */

    VCU_SW_initialize();

    /* 3. Returns a timestamp */

    IO_RTC_StartTime(&timestamp);

    /* 4. Infinity loop */

    while (1) {
        task();
    }

    VCU_SW_terminate();
}
