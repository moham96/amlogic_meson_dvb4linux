/*
 * Availink AVL6261 DVB-S/S2/S2X demodulator driver
 *
 * Copyright (C) 2020 Availink, Inc. (opensource@availink.com)
 *
 *    This program is free software; you can redistribute it and/or modify
 *    it under the terms of the GNU General Public License as published by
 *    the Free Software Foundation; either version 2 of the License, or
 *    (at your option) any later version.
 *
 *    This program is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU General Public License for more details.
 *
 *    You should have received a copy of the GNU General Public License along
 *    with this program; if not, write to the Free Software Foundation, Inc.,
 *    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#ifndef _AVL62X1_INTERNAL_H_
#define _AVL62X1_INTERNAL_H_

#include "AVL_Types.h"

#ifdef AVL_CPLUSPLUS
extern "C"
{
#endif

#define AVL_min(x, y) (((x) < (y)) ? (x) : (y))
#define AVL_max(x, y) (((x) < (y)) ? (y) : (x))
#define AVL_abs(a) (((a) > 0) ? (a) : (-(a)))

#define AVL_EC_OK 0           // There is no error.
#define AVL_EC_GENERAL_FAIL 1 // A general failure has occurred.
#define AVL_EC_RUNNING 2
#define AVL_EC_MemoryRunout 4
#define AVL_EC_TimeOut 8
#define AVL_EC_COMMAND_FAILED 16
#define AVL_EC_ConvertXLFSRToN_FAIL 0x0FFFFFFF //for system to judge wether convert success or not

#define AVL_CONSTANT_10_TO_THE_9TH 1000000000 //10e9

#define AVL62X1_API_VER_MAJOR 1  //Public API rev
#define AVL62X1_API_VER_MINOR 8  //SDK-FW API rev
#define AVL62X1_API_VER_BUILD 23 //internal rev

#define MAX_II2C_READ_SIZE 64
#define MAX_II2C_WRITE_SIZE 64

  // Stores an unsigned 64-bit integer
  typedef struct AVL62X1_uint64
  {
    AVL_uint32 uiHighWord; // The most significant 32-bits of the unsigned 64-bit integer
    AVL_uint32 uiLowWord;  // The least significant 32-bits of the unsigned 64-bit integer
  } AVL62X1_uint64;

  // Stores a signed 64-bit integer
  typedef struct AVL62X1_int64
  {
    AVL_int32 iHighWord;  // The most significant 32-bits of the signed 64-bit integer
    AVL_uint32 uiLowWord; // The least significant 32-bits of the signed 64-bit integer
  } AVL62X1_int64;

  AVL_uint16 DeChunk16_AVL62X1(const AVL_puchar pBuff);
  AVL_uint32 DeChunk32_AVL62X1(const AVL_puchar pBuff);
  void Chunk16_AVL62X1(AVL_uint16 uidata, AVL_puchar pBuff);
  void Chunk32_AVL62X1(AVL_uint32 uidata, AVL_puchar pBuff);
  void ChunkAddr_AVL62X1(AVL_uint32 uiaddr, AVL_puchar pBuff);
  void Add32To64_AVL62X1(AVL62X1_uint64 *pSum, AVL_uint32 uiAddend);
  AVL_uint32 Divide64_AVL62X1(AVL62X1_uint64 y, AVL62X1_uint64 x);
  AVL_uint32 GreaterThanOrEqual64_AVL62X1(AVL62X1_uint64 a, AVL62X1_uint64 b);
  void Subtract64_AVL62X1(AVL62X1_uint64 *pA, AVL62X1_uint64 b);
  void Multiply32_AVL62X1(AVL62X1_uint64 *pDst, AVL_uint32 m1, AVL_uint32 m2);
  void AddScaled32To64_AVL62X1(AVL62X1_uint64 *pDst, AVL_uint32 a);
  AVL_uint32 Min32_AVL62X1(AVL_uint32 a, AVL_uint32 b);
  AVL_uint32 Max32_AVL62X1(AVL_uint32 a, AVL_uint32 b);

  AVL_ErrorCode AVL_II2C_Initialize(void);

  AVL_ErrorCode II2C_Read_AVL62X1(AVL_uint16 uiSlaveAddr, AVL_uint32 uiOffset, AVL_puchar pucBuff, AVL_uint32 uiSize);
  AVL_ErrorCode II2C_Read8_AVL62X1(AVL_uint16 uiSlaveAddr, AVL_uint32 uiAddr, AVL_puchar puiData);
  AVL_ErrorCode II2C_Read16_AVL62X1(AVL_uint16 uiSlaveAddr, AVL_uint32 uiAddr, AVL_puint16 puiData);
  AVL_ErrorCode II2C_Read32_AVL62X1(AVL_uint16 uiSlaveAddr, AVL_uint32 uiAddr, AVL_puint32 puiData);
  AVL_ErrorCode II2C_ReadDirect_AVL62X1(AVL_uint16 uiSlaveAddr, AVL_puchar pucBuff, AVL_uint16 uiSize);
  AVL_ErrorCode II2C_Write_FW_AVL62X1(AVL_uint16 uiSlaveAddr, AVL_puchar pucBuff, AVL_uint32 uiSize);
  AVL_ErrorCode II2C_WriteDirect_AVL62X1(AVL_uint16 uiSlaveAddr, AVL_puchar pucBuff, AVL_uint16 uiSize);
  AVL_ErrorCode II2C_Write_AVL62X1(AVL_uint16 uiSlaveAddr, AVL_puchar pucBuff, AVL_uint32 uiSize);
  AVL_ErrorCode II2C_Write8_AVL62X1(AVL_uint16 uiSlaveAddr, AVL_uint32 uiAddr, AVL_uchar ucData);
  AVL_ErrorCode II2C_Write16_AVL62X1(AVL_uint16 uiSlaveAddr, AVL_uint32 uiAddr, AVL_uint16 uiData);
  AVL_ErrorCode II2C_Write32_AVL62X1(AVL_uint16 uiSlaveAddr, AVL_uint32 uiAddr, AVL_uint32 uiData);

  AVL_uchar patch_read8_AVL62X1(AVL_puchar pPatchBuf, AVL_uint32 *idx);
  AVL_uint16 patch_read16_AVL62X1(AVL_puchar pPatchBuf, AVL_uint32 *idx);
  AVL_uint32 patch_read32_AVL62X1(AVL_puchar pPatchBuf, AVL_uint32 *idx);
  AVL_uint32 Convert_XLFSRToN_AVL62X1(AVL_uint32 XLFSR);

#ifdef AVL_CPLUSPLUS
}
#endif

#endif
