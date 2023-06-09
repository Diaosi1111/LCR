/*!
    \file    main.h
    \brief   the header file of main

    \version 2016-08-15, V1.0.0, firmware for GD32F4xx
    \version 2018-12-12, V2.0.0, firmware for GD32F4xx
    \version 2020-09-30, V2.1.0, firmware for GD32F4xx
    \version 2022-03-09, V3.0.0, firmware for GD32F4xx
*/

/*
    Copyright (c) 2022, GigaDevice Semiconductor Inc.

    Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:

    1. Redistributions of source code must retain the above copyright notice, this
       list of conditions and the following disclaimer.
    2. Redistributions in binary form must reproduce the above copyright notice,
       this list of conditions and the following disclaimer in the documentation
       and/or other materials provided with the distribution.
    3. Neither the name of the copyright holder nor the names of its contributors
       may be used to endorse or promote products derived from this software without
       specific prior written permission.

    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY
OF SUCH DAMAGE.
*/

#ifndef __MAIN_H
#define __MAIN_H

#include "gd32f4xx_direct_io.h"

#define USE_FREERTOS 1

#define RCU_LED1     RCU_GPIOE
#define PORT_LED1    GPIOE
#define PIN_LED1     GPIO_PIN_3

#define RCU_LED2     RCU_GPIOD  // LED2的时钟
#define PORT_LED2    GPIOD      // LED2的端口
#define PIN_LED2     GPIO_PIN_7 // LED2的引脚

#define RCU_LED3     RCU_GPIOG
#define PORT_LED3    GPIOG
#define PIN_LED3     GPIO_PIN_3

#define RCU_LED4     RCU_GPIOA
#define PORT_LED4    GPIOA
#define PIN_LED4     GPIO_PIN_5

#define BSP_KEY_PORT GPIOA
#define BSP_KEY_PIN  GPIO_PIN_0
#define BSP_KEY_IN   PAin(0)

#define PWR_ON       PFout(9) = 1;
#define PWR_OFF      PFout(9) = 0;

#endif /* __MAIN_H */
