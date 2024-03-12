/*******************************************************************************
* Title                 :   MCP25625 HAL
* Filename              :   MCP25625_hal.c
* Author                :   MSV
* Origin Date           :   01/02/2016
* Notes                 :   None
*******************************************************************************/
/*************** MODULE REVISION LOG ******************************************
*
*    Date    Software Version    Initials       Description
*  01/02/16       1.0.0             MSV        Module Created.
*
*******************************************************************************/
/**
 * @file MCP25625_hal.c
 * @brief <h2> HAL layer </h2>
 */
/******************************************************************************
* Includes
*******************************************************************************/
#include "MCP25625_hal.h"
#include "libs/gpio/pin_defs.h"
#include "libs/gpio/api.h"
#include "libs/spi/api.h"

/******************************************************************************
* Module Preprocessor Constants
*******************************************************************************/

/******************************************************************************
* Module Preprocessor Macros
*******************************************************************************/
#define __MIKROC_PRO_FOR_AVR__ (1)
/******************************************************************************
* Module Typedefs
*******************************************************************************/

/******************************************************************************
* Module Variable Definitions
*******************************************************************************/
#if defined( __MIKROC_PRO_FOR_ARM__ )       || \
    defined( __MIKROC_PRO_FOR_DSPIC__ )
static void             ( *write_spi_p )    ( unsigned int data_out );
static unsigned int     ( *read_spi_p )     ( unsigned int buffer );

#elif defined( __MIKROC_PRO_FOR_AVR__ )     || \
      defined( __MIKROC_PRO_FOR_PIC__ )     || \
      defined( __MIKROC_PRO_FOR_8051__ )    || \
      defined( __MIKROC_PRO_FOR_FT90x__ )
//static void             ( *write_spi_p )    ( unsigned char data_out );
// static unsigned char    ( *read_spi_p )     ( unsigned char dummy );

#elif defined( __MIKROC_PRO_FOR_PIC32__ )
static void             ( *write_spi_p )    ( unsigned long data_out );
static unsigned long    ( *read_spi_p )     ( unsigned long buffer );

#endif

#if defined( __MIKROC_PRO_FOR_ARM__ )     || \
    defined( __MIKROC_PRO_FOR_AVR__ )     || \
    defined( __MIKROC_PRO_FOR_PIC__ )     || \
    defined( __MIKROC_PRO_FOR_PIC32__ )   || \
    defined( __MIKROC_PRO_FOR_DSPIC__ )   || \
    defined( __MIKROC_PRO_FOR_8051__ )    || \
    defined( __MIKROC_PRO_FOR_FT90x__ )
// REDACTED SINCE WE DON'T USE SFR FOR GPIO PINS
// extern sfr sbit MCP25625_CS;
// extern sfr sbit MCP25625_RST;
// extern sfr sbit MCP25625_STB;
// extern sfr sbit MCP25625_TX0;
// extern sfr sbit MCP25625_TX1;
// extern sfr sbit MCP25625_RX0;
// extern sfr sbit MCP25625_RX1;
#endif
/******************************************************************************
* Function Prototypes
*******************************************************************************/
gpio_t CHARGER_CS = PC4;
gpio_t CHARGER_RESET = PC5;
gpio_t CHARGER_STBY = PB6;
/******************************************************************************
* Function Definitions
*******************************************************************************/
void MCP25625_hal_cs( int state )
{
    if (state == 0){
        gpio_clear_pin(CHARGER_CS);
    }
    if (state == 1){
        gpio_set_pin(CHARGER_CS);
    }
#ifdef __GNUC__

#else
    MCP25625_CS = state;
#endif
}

void MCP25625_hal_rst( int state )
{
    if (state == 0){
        gpio_clear_pin(CHARGER_RESET);
    }
    if (state == 1){
        gpio_set_pin(CHARGER_RESET);
    }
#ifdef __GNUC__

#else
    MCP25625_RST = state;
#endif
}

void MCP25625_hal_stb( int state )
{
    if (state == 0){
        gpio_clear_pin(CHARGER_STBY);
    }
    if (state == 1){
        gpio_set_pin(CHARGER_STBY);
    }
#ifdef __GNUC__

#else
    MCP25625_STB = state;
#endif
}

void MCP25625_hal_tx0( int state )
{
#ifdef __GNUC__

#else
    MCP25625_TX0 = state;
#endif
}

void MCP25625_hal_tx1( int state )
{
#ifdef __GNUC__

#else
    MCP25625_TX1 = state;
#endif
}

// REDACTED FOR COMPILATION
// int MCP25625_hal_rx0()
// {
// #ifdef __GNUC__

// #else
//     return MCP25625_RX0;
// #endif
// }

// int MCP25625_hal_rx1()
// {
// #ifdef __GNUC__

// #else
//     return MCP25625_RX1;
// #endif
// }

void MCP25625_hal_init()
{
    gpio_set_mode(CHARGER_CS, OUTPUT);
    gpio_set_mode(CHARGER_RESET, OUTPUT);
    gpio_set_mode(CHARGER_STBY, OUTPUT);
#if defined( __MIKROC_PRO_FOR_ARM__ )   || \
    defined( __MIKROC_PRO_FOR_AVR__ )   || \
    defined( __MIKROC_PRO_FOR_DSPIC__ ) || \
    defined( __MIKROC_PRO_FOR_PIC32__ ) || \
    defined( __MIKROC_PRO_FOR_8051__ )  || \
    defined( __MIKROC_PRO_FOR_FT90x__ )
    //write_spi_p             = SPI_Wr_Ptr;
    // read_spi_p              = SPI_Rd_Ptr;

#elif defined( __MIKROC_PRO_FOR_PIC__ )
    write_spi_p             = SPI1_Write;
    read_spi_p              = SPI1_Read;
#endif
}

void MCP25625_hal_cmd( uint8_t cmd )
{
#if defined( __MIKROC_PRO_FOR_ARM__ )   || \
    defined( __MIKROC_PRO_FOR_AVR__ )   || \
    defined( __MIKROC_PRO_FOR_DSPIC__ ) || \
    defined( __MIKROC_PRO_FOR_PIC32__ ) || \
    defined( __MIKROC_PRO_FOR_8051__ )  || \
    defined( __MIKROC_PRO_FOR_FT90x__ ) || \
    defined( __MIKROC_PRO_FOR_PIC__ )
    spi_transceive(&cmd, NULL, 1);
    // write_spi_p( cmd );
#endif
}

void MCP25625_hal_write( uint8_t *buffer,
                         uint16_t count )
{
#if defined( __MIKROC_PRO_FOR_ARM__ )   || \
    defined( __MIKROC_PRO_FOR_AVR__ )   || \
    defined( __MIKROC_PRO_FOR_DSPIC__ ) || \
    defined( __MIKROC_PRO_FOR_PIC32__ ) || \
    defined( __MIKROC_PRO_FOR_8051__ )  || \
    defined( __MIKROC_PRO_FOR_FT90x__ ) || \
    defined( __MIKROC_PRO_FOR_PIC__ )
    //while( count-- )
    spi_transceive(buffer, NULL, count);
        // write_spi_p( *buffer++ );
#endif
}

void MCP25625_hal_read( uint8_t *buffer,
                        uint16_t count )
{
#if defined( __MIKROC_PRO_FOR_ARM__ )   || \
    defined( __MIKROC_PRO_FOR_AVR__ )   || \
    defined( __MIKROC_PRO_FOR_DSPIC__ ) || \
    defined( __MIKROC_PRO_FOR_PIC32__ ) || \
    defined( __MIKROC_PRO_FOR_8051__ )  || \
    defined( __MIKROC_PRO_FOR_FT90x__ ) || \
    defined( __MIKROC_PRO_FOR_PIC__ )
    // while( count-- )
    //     *buffer++ = read_spi_p( DUMMY_BYTE );
    spi_receive(buffer, count);
#endif
}

/*************** END OF FUNCTIONS ***************************************************************************/
