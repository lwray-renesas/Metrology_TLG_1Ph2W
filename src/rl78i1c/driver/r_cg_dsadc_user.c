/***********************************************************************************************************************
* DISCLAIMER
* This software is supplied by Renesas Electronics Corporation and is only intended for use with Renesas products.
* No other uses are authorized. This software is owned by Renesas Electronics Corporation and is protected under all
* applicable laws, including copyright laws. 
* THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING THIS SOFTWARE, WHETHER EXPRESS, IMPLIED
* OR STATUTORY, INCLUDING BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
* NON-INFRINGEMENT.  ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED.TO THE MAXIMUM EXTENT PERMITTED NOT PROHIBITED BY
* LAW, NEITHER RENESAS ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES SHALL BE LIABLE FOR ANY DIRECT,
* INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR ANY REASON RELATED TO THIS SOFTWARE, EVEN IF RENESAS OR
* ITS AFFILIATES HAVE BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
* Renesas reserves the right, without notice, to make changes to this software and to discontinue the availability 
* of this software. By using this software, you agree to the additional terms and conditions found by accessing the 
* following link:
* http://www.renesas.com/disclaimer
*
* Copyright (C) 2015, 2021 Renesas Electronics Corporation. All rights reserved.
***********************************************************************************************************************/

/***********************************************************************************************************************
* File Name    : r_cg_dsadc_user.c
* Version      : Applilet4 for RL78/I1C V1.01.07.02 [08 Nov 2021]
* Device(s)    : R5F10NLG
* Tool-Chain   : CCRL
* Description  : This file implements device driver for DSADC module.
* Creation Date: 18/10/2023
***********************************************************************************************************************/

/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_cg_macrodriver.h"
#include "r_cg_dsadc.h"
/* Start user code for include. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#include "r_cg_userdefine.h"

/***********************************************************************************************************************
Pragma directive
***********************************************************************************************************************/

#pragma interrupt r_dsadc_interrupt(vect=INTDSAD)

/* Start user code for pragma. Do not edit comment generated here */

#ifdef METER_ENABLE_MEASURE_CPU_LOAD
#include "load_test.h"
#define DSAD_MEASUREMENT_TIME   (65535)
uint16_t g_timer0_dsad_counter = 0;

uint16_t g_timer0_dsad_maxcounter = 0;
uint16_t g_timer0_dsad_mincounter = 0;

uint16_t g_dsad_count = DSAD_MEASUREMENT_TIME;
const uint16_t g_dsad_max_count = DSAD_MEASUREMENT_TIME;

uint32_t g_timer0_dsad_sum_counter = 0;

uint16_t g_timer0_diff = 0;
#endif

extern void EM_ADC_InterruptCallback(void);
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
/* Start user code for global. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: r_dsadc_interrupt
* Description  : None
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
static void __near r_dsadc_interrupt(void)
{
    /* Start user code. Do not edit comment generated here */
#ifdef METER_ENABLE_MEASURE_CPU_LOAD
    if (g_dsad_count < g_dsad_max_count)
    {
        g_dsad_count++;
        LOADTEST_TAU_Start();
    }
#endif

    EM_ADC_InterruptCallback();

#ifdef METER_ENABLE_MEASURE_CPU_LOAD
g_timer0_diff = LOADTEST_TAU_Diff();

LOADTEST_TAU_Stop();

g_timer0_dsad_sum_counter += g_timer0_diff;

if (g_dsad_count <=  g_dsad_max_count)
{
    g_timer0_dsad_counter = g_timer0_diff;

    if ( g_timer0_dsad_counter > g_timer0_dsad_maxcounter)
    {
        g_timer0_dsad_maxcounter = g_timer0_dsad_counter;
    }

    if ( g_timer0_dsad_counter < g_timer0_dsad_mincounter)
    {
        g_timer0_dsad_mincounter = g_timer0_dsad_counter;
    }
}

#endif
    /* End user code. Do not edit comment generated here */
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
