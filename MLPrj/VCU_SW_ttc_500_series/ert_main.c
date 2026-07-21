/*
 * File: ert_main.c
 *
 * Code generated for Simulink model 'VCU_SW'.
 *
 * Model version                  : 2.437
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Mon Jul  6 11:47:51 2026
 *
 * Target selection: ttc_500_series.tlc
 * Embedded hardware selection: Texas Instruments->TMS570 Cortex-R4
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

// Includes
#include "APDB.h"
#include "IO_Driver.h"
#include "IO_RTC.h"
#include "IO_Power.h"
#include "VCU_SW.h"

// Defines
#define MAJOR_NUMBER                   0
#define MINOR_NUMBER                   0
#define REVISION_NUMBER                1
#define STEP_SIZE                      10000                     /* Sample Time in microseconds */

// Definitions
// APDB

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

// Safety configuration
static const IO_DRIVER_SAFETY_CONF c_driver_safety_conf = {
  10,
  STEP_SIZE,
  SAFETY_CONF_WINDOW_SIZE_100_PERCENT,
  SAFETY_CONF_RESETS_1,
  NULL,
  NULL
};

static IO_ErrorType EEPROM_Sts;

// Function with application
void task (void)
{
  IO_Driver_TaskBegin();
  VCU_SW_step();

  /* Get model outputs here */
  IO_Driver_TaskEnd();
  while (IO_RTC_GetTimeUS(timestamp) < STEP_SIZE) ;// wait until STEP_SIZE have passed
  timestamp += STEP_SIZE;
}

// Main function
void main(void)
{
  // Global Initialization of IO drivers
  IO_Driver_Init(&c_driver_safety_conf);

  // Enable powerstages
  IO_POWER_Set (IO_INT_POWERSTAGE_ENABLE, IO_POWER_ON);

  // Enable 0 safety switch for shut off group ¹ 0
  IO_POWER_Set (IO_INT_SAFETY_SW_0, IO_POWER_ON);

  // Enable 1 safety switch for shut off group ¹ 1
  IO_POWER_Set (IO_INT_SAFETY_SW_1, IO_POWER_ON);

  // Enable 2 safety switch for shut off group ¹ 2
  IO_POWER_Set (IO_INT_SAFETY_SW_2, IO_POWER_ON);

  // Initialize external RTC device
  IO_RTC_InitDateAndTime();

  // Initialization of CAN driver for IO_CAN_CHANNEL_0
  IO_CAN_Init(IO_CAN_CHANNEL_0, IO_CAN_BIT_250_KB, 0, 0, 0, 0);

  // Initialization of CAN driver for IO_CAN_CHANNEL_1
  IO_CAN_Init(IO_CAN_CHANNEL_1, IO_CAN_BIT_250_KB, 0, 0, 0, 0);

  // Initialization of CAN driver for IO_CAN_CHANNEL_2
  IO_CAN_Init(IO_CAN_CHANNEL_2, IO_CAN_BIT_250_KB, 0, 0, 0, 0);

  // Initialization of CAN driver for IO_CAN_CHANNEL_3
  IO_CAN_Init(IO_CAN_CHANNEL_3, IO_CAN_BIT_250_KB, 0, 0, 0, 0);

  // Initialization of CAN driver for IO_CAN_CHANNEL_4
  IO_CAN_Init(IO_CAN_CHANNEL_4, IO_CAN_BIT_250_KB, 0, 0, 0, 0);

  // Initialization of CAN driver for IO_CAN_CHANNEL_5
  IO_CAN_Init(IO_CAN_CHANNEL_5, IO_CAN_BIT_250_KB, 0, 0, 0, 0);

  // Initialization of CAN driver for IO_CAN_CHANNEL_6
  IO_CAN_Init(IO_CAN_CHANNEL_6, IO_CAN_BIT_250_KB, 0, 0, 0, 0);

  // Other initialization
  VCU_SW_initialize();

  // Get timestamp
  IO_RTC_StartTime(&timestamp);
  while (1) {
    task();
  }

  // Actions after model termination
  VCU_SW_terminate();
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
