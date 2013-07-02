 /*********************************************************************
 *
 *	Hardware specific definitions for:
 *    - Explorer 16
 *    - PIC32MX
 *    - Ethernet PICtail Plus (ENC28J60)
 *
 *********************************************************************
 * FileName:        HardwareProfile.h
 * Dependencies:    Compiler.h
 * Processor:       PIC32
 * Compiler:        Microchip C32 v1.11 or higher
 * Company:         Microchip Technology, Inc.
 *
 * Software License Agreement
 *
 * Copyright (C) 2002-2010 Microchip Technology Inc.  All rights
 * reserved.
 *
 * Microchip licenses to you the right to use, modify, copy, and
 * distribute:
 * (i)  the Software when embedded on a Microchip microcontroller or
 *      digital signal controller product ("Device") which is
 *      integrated into Licensee's product; or
 * (ii) ONLY the Software driver source files ENC28J60.c, ENC28J60.h,
 *		ENCX24J600.c and ENCX24J600.h ported to a non-Microchip device
 *		used in conjunction with a Microchip ethernet controller for
 *		the sole purpose of interfacing with the ethernet controller.
 *
 * You should refer to the license agreement accompanying this
 * Software for additional information regarding your rights and
 * obligations.
 *
 * THE SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT
 * WARRANTY OF ANY KIND, EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT
 * LIMITATION, ANY WARRANTY OF MERCHANTABILITY, FITNESS FOR A
 * PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT SHALL
 * MICROCHIP BE LIABLE FOR ANY INCIDENTAL, SPECIAL, INDIRECT OR
 * CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF
 * PROCUREMENT OF SUBSTITUTE GOODS, TECHNOLOGY OR SERVICES, ANY CLAIMS
 * BY THIRD PARTIES (INCLUDING BUT NOT LIMITED TO ANY DEFENSE
 * THEREOF), ANY CLAIMS FOR INDEMNITY OR CONTRIBUTION, OR OTHER
 * SIMILAR COSTS, WHETHER ASSERTED ON THE BASIS OF CONTRACT, TORT
 * (INCLUDING NEGLIGENCE), BREACH OF WARRANTY, OR OTHERWISE.
 *
 *
 * Author               Date		Comment
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Howard Schlunder		09/16/2010	Regenerated for specific boards
 ********************************************************************/
#ifndef HARDWARE_PROFILE_H
#define HARDWARE_PROFILE_H

#include "Compiler.h"

// Define a macro describing this hardware set up (used in other files)
#define EXPLORER_16

// Set configuration fuses (but only in MainDemo.c where THIS_IS_STACK_APPLICATION is defined)
#if defined(THIS_IS_STACK_APPLICATION)
//    #pragma config FPLLODIV = DIV_1, FPLLMUL = MUL_20, FPLLIDIV = DIV_2, FWDTEN = OFF, FPBDIV = DIV_1, POSCMOD = XT, FNOSC = PRIPLL, CP = OFF
    #pragma config FPLLODIV = DIV_1, FPLLMUL = MUL_20, FPLLIDIV = DIV_2, FWDTEN = OFF, FPBDIV = DIV_1, POSCMOD = XT, FNOSC = PRIPLL, CP = OFF
#endif


// Clock frequency values
// These directly influence timed events using the Tick module.  They also are used for UART and SPI baud rate generation.
#define GetSystemClock()		(80000000ul)			// Hz
#define GetInstructionClock()	(GetSystemClock()/1)	// Normally GetSystemClock()/4 for PIC18, GetSystemClock()/2 for PIC24/dsPIC, and GetSystemClock()/1 for PIC32.  Might need changing if using Doze modes.
#define GetPeripheralClock()	(GetSystemClock()/1)	// Normally GetSystemClock()/4 for PIC18, GetSystemClock()/2 for PIC24/dsPIC, and GetSystemClock()/1 for PIC32.  Divisor may be different if using a PIC32 since it's configurable.


// Hardware I/O pin mappings

// LEDs
#define LED0_TRIS			(TRISDbits.TRISD1)	// Ref D3
#define LED0_IO				(LATDbits.LATD1)
#define LED1_TRIS			(TRISDbits.TRISD2)	// Ref D4
#define LED1_IO				(LATDbits.LATD2)
#define LED2_TRIS			(TRISGbits.TRISG15)	// Ref D5
#define LED2_IO				(LATGbits.LATG15)
#define LED3_TRIS			(TRISFbits.TRISF3)	// Ref D6
#define LED3_IO				(LATFbits.LATF3)
#define LED4_TRIS			(TRISFbits.TRISF2)	// Ref D7
#define LED4_IO				(LATFbits.LATF2)
#define LED5_TRIS			(TRISFbits.TRISF8)	// Ref D8
#define LED5_IO				(LATFbits.LATF8)
#define LED6_TRIS			(TRISAbits.TRISA2)	// Ref D9
#define LED6_IO				(LATAbits.LATA2)
#define LED7_TRIS			(TRISAbits.TRISA3)	// Ref D10	// Note: This is multiplexed with BUTTON1
#define LED7_IO				(LATAbits.LATA3)
//#define LED_GET()			(*((volatile unsigned char*)(&LATA)))
//#define LED_PUT(a)			(*((volatile unsigned char*)(&LATA)) = (a))

// Momentary push buttons
#define BUTTON0_TRIS                    (TRISCbits.TRISC1)	// Ref S4
#define	BUTTON0_IO			(PORTCbits.RC1)
#define BUTTON1_TRIS                    (TRISCbits.TRISC2)	// Ref S5	// Note: This is multiplexed with LED7
#define	BUTTON1_IO			(PORTCbits.RC2)
#define BUTTON2_TRIS                    (TRISCbits.TRISC3)	// Ref S6
#define	BUTTON2_IO			(PORTCbits.RC3)
#define BUTTON3_TRIS                    (TRISAbits.TRISA4)	// Ref S3
#define	BUTTON3_IO			(PORTAbits.RA4)

#define UARTTX_TRIS			(TRISFbits.TRISF5)
#define UARTTX_IO			(PORTFbits.RF5)
#define UARTRX_TRIS			(TRISFbits.TRISF4)
#define UARTRX_IO			(PORTFbits.RF4)

#define VETHON_TRIS			TRISAbits.TRISA9
#define VETHON_LAT			LATAbits.LATA9


// ENC28J60 I/O pins
#define ENC_RST_TRIS                    (TRISAbits.TRISA0)	// Not connected by default
#define ENC_RST_IO			(PORTAbits.RA0)
#define ENC_CS_TRIS			(TRISGbits.TRISG9)
#define ENC_CS_IO			(PORTGbits.RG9)
#define ENC_SPI_IF			(IFS1bits.SPI2RXIF)
#define ENC_SSPBUF			(SPI2BUF)
#define ENC_SPISTATbits                 (SPI2STATbits)
#define ENC_SPICON1			(SPI2CON)
#define ENC_SPICON1bits                 (SPI2CONbits)
#define ENC_SPIBRG			(SPI2BRG)


// 25LC256 I/O pins
#define EEPROM_CS_TRIS		(TRISDbits.TRISD11)
#define EEPROM_CS_IO		(LATDbits.LATD11)
#define EEPROM_SCK_TRIS		(TRISDbits.TRISD10)
#define EEPROM_SDI_TRIS		(TRISCbits.TRISC4)
#define EEPROM_SDO_TRIS		(TRISDbits.TRISD0)
#define EEPROM_SPI_IF		(IFS0bits.SPI1RXIF)
#define EEPROM_SSPBUF		(SPI1BUF)
#define EEPROM_SPICON1		(SPI1CON)
#define EEPROM_SPICON1bits	(SPI1CONbits)
#define EEPROM_SPIBRG		(SPI1BRG)
#define EEPROM_SPISTAT		(SPI1STAT)
#define EEPROM_SPISTATbits	(SPI1STATbits)


// LCD Module I/O pins.  NOTE: On the Explorer 16, the LCD is wired to the 
// same PMP lines required to communicate with an ENCX24J600 in parallel 
// mode.  Since the LCD does not have a chip select wire, if you are using 
// the ENC424J600/624J600 in parallel mode, the LCD cannot be used.
#if !defined(ENC100_INTERFACE_MODE) || (ENC100_INTERFACE_MODE == 0)	// SPI only
//	#define LCD_DATA_TRIS		(*((volatile unsigned char*)&TRISE))
//	#define LCD_DATA_IO			(*((volatile unsigned char*)&LATE))
//	#define LCD_RD_WR_TRIS		(TRISDbits.TRISD5)
//	#define LCD_RD_WR_IO		(LATDbits.LATD5)
//	#define LCD_RS_TRIS			(TRISBbits.TRISB15)
//	#define LCD_RS_IO			(LATBbits.LATB15)
//	#define LCD_E_TRIS			(TRISDbits.TRISD4)
//	#define LCD_E_IO			(LATDbits.LATD4)
#endif

#ifdef __PIC32MX__
    // Registers for the SPI module you want to use
    #define MDD_USE_SPI_1
    //#define MDD_USE_SPI_2

    //SPI Configuration
    #define SPI_START_CFG_1     (PRI_PRESCAL_64_1 | SEC_PRESCAL_8_1 | MASTER_ENABLE_ON | SPI_CKE_ON | SPI_SMP_ON)
    #define SPI_START_CFG_2     (SPI_ENABLE)

    // Define the SPI frequency
    #define SPI_FREQUENCY			(20000000)

    #if defined MDD_USE_SPI_1
            #warning "MDD_USE_SPI_1"

            // Description: SD-SPI Chip Select Output bit
            #define SD_CS               LATFbits.LATF13
            // Description: SD-SPI Chip Select TRIS bit
            #define SD_CS_TRIS          TRISFbits.TRISF13

            // Description: SD-SPI Card Detect Input bit
            #define SD_CD               PORTAbits.RA1
            // Description: SD-SPI Card Detect TRIS bit
            #define SD_CD_TRIS          TRISAbits.TRISA1

            // Description: SD-SPI Write Protect Check Input bit
            #define SD_WE               PORTAbits.RA10
            // Description: SD-SPI Write Protect Check TRIS bit
            #define SD_WE_TRIS          TRISAbits.TRISA10

            // Description: The main SPI control register
            #define SPICON1             SPI1CON
            // Description: The SPI status register
            #define SPISTAT             SPI1STAT
            // Description: The SPI Buffer
            #define SPIBUF              SPI1BUF
            // Description: The receive buffer full bit in the SPI status register
            #define SPISTAT_RBF         SPI1STATbits.SPIRBF
            // Description: The bitwise define for the SPI control register (i.e. _____bits)
            #define SPICON1bits         SPI1CONbits
            // Description: The bitwise define for the SPI status register (i.e. _____bits)
            #define SPISTATbits         SPI1STATbits
            // Description: The enable bit for the SPI module
            #define SPIENABLE           SPICON1bits.ON
            // Description: The definition for the SPI baud rate generator register (PIC32)
            #define SPIBRG			    SPI1BRG

            // Tris pins for SCK/SDI/SDO lines

            // Description: The TRIS bit for the SCK pin
            #define SPICLOCK            TRISDbits.TRISD10
            // Description: The TRIS bit for the SDI pin
            #define SPIIN               TRISCbits.TRISC4
            // Description: The TRIS bit for the SDO pin
            #define SPIOUT              TRISDbits.TRISD0
            //SPI library functions
            #define putcSPI             putcSPI1
            #define getcSPI             getcSPI1
            #define OpenSPI(config1, config2)   OpenSPI1(config1, config2)

    #elif defined MDD_USE_SPI_2
            #warning "MDD_USE_SPI_2"
            // Description: SD-SPI Chip Select Output bit
            #define SD_CS               LATBbits.LATB9
            // Description: SD-SPI Chip Select TRIS bit
            #define SD_CS_TRIS          TRISBbits.TRISB9

            // Description: SD-SPI Card Detect Input bit
            #define SD_CD               PORTGbits.RG0
            // Description: SD-SPI Card Detect TRIS bit
            #define SD_CD_TRIS          TRISGbits.TRISG0

            // Description: SD-SPI Write Protect Check Input bit
            #define SD_WE               PORTGbits.RG1
            // Description: SD-SPI Write Protect Check TRIS bit
            #define SD_WE_TRIS          TRISGbits.TRISG1

            // Description: The main SPI control register
            #define SPICON1             SPI2CON
            // Description: The SPI status register
            #define SPISTAT             SPI2STAT
            // Description: The SPI Buffer
            #define SPIBUF              SPI2BUF
            // Description: The receive buffer full bit in the SPI status register
            #define SPISTAT_RBF         SPI2STATbits.SPIRBF
            // Description: The bitwise define for the SPI control register (i.e. _____bits)
            #define SPICON1bits         SPI2CONbits
            // Description: The bitwise define for the SPI status register (i.e. _____bits)
            #define SPISTATbits         SPI2STATbits
            // Description: The enable bit for the SPI module
            #define SPIENABLE           SPI2CONbits.ON
            // Description: The definition for the SPI baud rate generator register (PIC32)
            #define SPIBRG			    SPI2BRG

            // Tris pins for SCK/SDI/SDO lines

            // Description: The TRIS bit for the SCK pin
            #define SPICLOCK            TRISGbits.TRISG6
            // Description: The TRIS bit for the SDI pin
            #define SPIIN               TRISGbits.TRISG7
            // Description: The TRIS bit for the SDO pin
            #define SPIOUT              TRISGbits.TRISG8
            //SPI library functions
            #define putcSPI             putcSPI2
            #define getcSPI             getcSPI2
            #define OpenSPI(config1, config2)   OpenSPI2(config1, config2)
    #endif
    // Will generate an error if the clock speed is too low to interface to the card
    #if (GetSystemClock() < 100000)
            #error Clock speed must exceed 100 kHz
    #endif

#endif

// Select which UART the STACK_USE_UART and STACK_USE_UART2TCP_BRIDGE 
// options will use.  You can change these to U1BRG, U1MODE, etc. if you 
// want to use the UART1 module instead of UART2.
#define UBRG				U2BRG
#define UMODE				U2MODE
#define USTA				U2STA
#define BusyUART()			BusyUART2()
#define CloseUART()			CloseUART2()
#define ConfigIntUART(a)	ConfigIntUART2(a)
#define DataRdyUART()		DataRdyUART2()
#define OpenUART(a,b,c)		OpenUART2(a,b,c)
#define ReadUART()			ReadUART2()
#define WriteUART(a)		WriteUART2(a)
#define getsUART(a,b,c)		getsUART2(a,b,c)
#define putsUART(a)			putsUART2(a)
#define getcUART()			getcUART2()
#define putcUART(a)			do{while(BusyUART()); WriteUART(a); while(BusyUART()); }while(0)
#define putrsUART(a)		putrsUART2(a)


#endif // #ifndef HARDWARE_PROFILE_H
