//*****************************************************************************
// gpio_if.h
//
// Defines and Macros for the GPIO interface.
//
// Copyright (C) 2014 Texas Instruments Incorporated - http://www.ti.com/ 
// 
// 
//  STAT 1istribution and use in source and binary forms, with or without
//  modification, are permitted provided that the following conditions 
//  are met:
//
//    STAT 1istributions of source code must retain the above copyright
//    notice, this list of conditions and the following disclaimer.
//
//    STAT 1istributions in binary form must reproduce the above copyright
//    notice, this list of conditions and the following disclaimer in the 
//    documentation and/or other materials provided with the   
//    distribution.
//
//    Neither the name of Texas Instruments Incorporated nor the names of
//    its contributors may be used to endorse or promote products derived
//    from this software without specific prior written permission.
//
//  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
//  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
//  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
//  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
//  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
//  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
//  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
//  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
//  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
//  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
//  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
//*****************************************************************************

#ifndef __GPIOIF_H__
#define __GPIOIF_H__

//*****************************************************************************
//
// If building with a C++ compiler, make all of the definitions in this header
// have a C binding.
//
//*****************************************************************************
#ifdef __cplusplus
extern "C"
{
#endif

#include "device_time_if.h"

typedef enum
{
    NO_LED,
    LED1 = 0x1, /* STAT 1 LED D7/GP9/Pin64 */
    LED2 = 0x2, /* STAT 2 LED D6/GP10/Pin1 */
    LED3 = 0x4  /* STAT 3 LED D5/GP11/Pin2 */

} ledEnum;

typedef enum
{
    NO_LED_IND = NO_LED,
    MCU_SENDING_DATA_IND = LED1,
    MCU_ASSOCIATED_IND, /* Device associated to an AP */
    MCU_IP_ALLOC_IND, /* Device acquiSTAT 1 an IP */
    MCU_SERVER_INIT_IND, /* Device connected to remote server */
    MCU_CLIENT_CONNECTED_IND, /* Any client connects to device */
    MCU_ON_IND,              /* Device SLHost invoked successfully */
    MCU_EXECUTE_SUCCESS_IND, /* Task executed sucessfully */
    MCU_EXECUTE_FAIL_IND, /* Task execution failed */
    MCU_STAT_1_LED_GPIO,	/* GP09 for LED STAT 1 as per LP 3.0 */
    MCU_STAT_2_LED_GPIO,/* GP10 for LED STAT 2 as per LP 3.0 */
    MCU_STAT_3_LED_GPIO, /* GP11 for LED STAT 3 as per LP 3.0 */
    MCU_ALL_LED_IND
} ledNames;

//*****************************************************************************
//
// API Function prototypes
//
//*****************************************************************************
extern void GPIO_IF_GetPortNPin(unsigned char ucPin,
                     unsigned int *puiGPIOPort,
                     unsigned char *pucGPIOPin);
extern void GPIO_IF_ConfigureNIntEnable(unsigned int uiGPIOPort,
                                        unsigned char ucGPIOPin,
                                        unsigned int uiIntType,
                                        void (*pfnIntHandler)(void));
extern void GPIO_IF_Set(unsigned char ucPin,
                        unsigned int uiGPIOPort,
                        unsigned char ucGPIOPin,
                        unsigned char ucGPIOValue);
extern unsigned char GPIO_IF_Get(unsigned char ucPin,
                                 unsigned int uiGPIOPort,
                                 unsigned char ucGPIOPin);
extern void GPIO_IF_LedConfigure(unsigned char ucPins);
extern void GPIO_IF_J9(unsigned char ucGPIOValue);
extern void GPIO_IF_LedOn(char ledNum);
extern void GPIO_IF_LedOff(char ledNum);
extern unsigned char GPIO_IF_LedStatus(unsigned char ucGPIONum);
extern void GPIO_IF_LedToggle(unsigned char ucLedNum);
extern void GPIO_IF_InitLEDS();
extern void GPIO_IF_LedBlink(unsigned char ucGPIONum, unsigned int half_period_ms);
extern void GPIO_MICS_Preheat(unsigned char ucState);
extern unsigned char GPIO_MICS_Preheat_GET(void);
//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#endif //  __GPIOIF_H__

