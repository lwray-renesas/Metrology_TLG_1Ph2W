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
* File Name    : r_cg_pclbuz.c
* Version      : Applilet4 for RL78/I1C V1.01.07.02 [08 Nov 2021]
* Device(s)    : R5F10NLG
* Tool-Chain   : CCRL
* Description  : This file implements device driver for PCLBUZ module.
* Creation Date: 23/10/2023
***********************************************************************************************************************/

/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_cg_macrodriver.h"
#include "r_cg_pclbuz.h"
/* Start user code for include. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#include "r_cg_userdefine.h"

/***********************************************************************************************************************
Pragma directive
***********************************************************************************************************************/
/* Start user code for pragma. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
/* Start user code for global. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: R_PCLBUZ0_Create
* Description  : This function initializes the PCLBUZ0 module.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_PCLBUZ0_Create(void)
{
    PCLOE0 = 0U;    /* output disable */
    CKS0 = _08_PCLBUZ_OUTCLK_fSX0;
    /* Set PCLBUZ0 pin */
    P4 &= 0xF7U;
    PM4 &= 0xF7U;
}
/***********************************************************************************************************************
* Function Name: R_PCLBUZ0_Start
* Description  : This function starts the PCLBUZ0 module.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_PCLBUZ0_Start(void)
{
    PCLOE0 = 1U;    /* output enable */
}
/***********************************************************************************************************************
* Function Name: R_PCLBUZ0_Stop
* Description  : This function stops the PCLBUZ0 module.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_PCLBUZ0_Stop(void)
{
    PCLOE0 = 0U;    /* output disable */
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
