/*------------------------------------------------------------------------------
 * Title: CORE_PECI.H - PECI function for KBC firmware.
 *
 * Copyright (c) 2010 - , ITE INC. All Rights Reserved.
 *
 * You may not reproduce, distribute, publish, display, perform, modify, adapt,
 * transmit, broadcast, present, recite, release, license or otherwise exploit
 * any part of this publication in any form, by any means, without the prior
 * written permission of ITE INC. .
 *----------------------------------------------------------------------------*/

#ifndef	CORE_PECI_H
#define	CORE_PECI_H

#define	PECI_Softwave_AWFCS	0		// 1 : softwave calculate AW_FCS
// 0 : H.W. calculate AW_FCS
#define	PECI_HostID			0x01	// Host ID = PECI_HostID << 1 (bit7 ~ bit0)

//-----------------------------------------------------------------------------
// Define CPU address
//-----------------------------------------------------------------------------
#define	PECI_CPU_ADDR		0x30

//-----------------------------------------------------------------------------
// Define processor Tjmax
//-----------------------------------------------------------------------------
#define	PECI_CPU_Tjmax		100
#define	PECI_Read_TjmaxTO	10		// Re-try to read CPU Tjmax via PECI

//-----------------------------------------------------------------------------
// Define PECI command
//-----------------------------------------------------------------------------
#define	PECI_CMD_GetDIB				0xF7
#define	PECI_CMD_Pin				0x00
#define	PECI_CMD_GetTemp			0x01
#define	PECI_CMD_RdPkgConfig		0xA1
#define	PECI_CMD_WrPkgConfig		0xA5
#define	PECI_CMD_RdIAMSR			0xB1
#define	PECI_CMD_WrIAMSR			0xB5
#define	PECI_CMD_RdPCIConfig		0x61
#define	PECI_CMD_WrPCIConfig		0x65
#define	PECI_CMD_RdPCIConfigLocal	0xE1
#define	PECI_CMD_WrPCIConfigLocal	0xE5

//-----------------------------------------------------------------------------
// Define completion code
//-----------------------------------------------------------------------------
#define	PECI_CC_Valid			0x40
#define	PECI_CC_TimeOut			0x80
#define	PECI_CC_Ignored			0x90

extern void Init_PECI(void);
extern void PECI_HostEnable(void);
extern void PECI_HostDisable(void);
extern BYTE PECI_CheckHostBusy(void);
extern BYTE PECI_CheckHostFinish(void);
extern void ResetPECIStatus(void);
extern void PECI_HostControl(BYTE control);
extern BYTE PECI_Ping(BYTE addr, BYTE ReadLen, BYTE WriteLen);
extern BYTE PECI_GetDIB(BYTE addr, XBYTE *ReadData, BYTE ReadLen, BYTE WriteLen);
extern BYTE PECI_GetTemp(BYTE addr, XBYTE *ReadData, BYTE Domain, BYTE ReadLen, BYTE WriteLen);
extern BYTE PECI_RdPkgConfig(BYTE addr, XBYTE *ReadData, BYTE Domain, BYTE Retry, BYTE Index, BYTE LSB, BYTE MSB, BYTE ReadLen, BYTE WriteLen);
extern BYTE PECI_WrPkgConfig(BYTE addr, XBYTE *WriteData, BYTE Domain, BYTE Retry, BYTE Index, BYTE LSB, BYTE MSB, BYTE ReadLen, BYTE WriteLen);
extern BYTE PECI_RdIAMSR(BYTE addr, XBYTE *ReadData, BYTE Domain, BYTE Retry, BYTE ProcessorID, BYTE LSB, BYTE MSB, BYTE ReadLen, BYTE WriteLen);

#endif	/* CORE_PECI_H */

