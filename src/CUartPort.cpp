/*
 * CUartPort.cpp
 *
 *  Created on: Mar 11, 2021
 *      Author: reza
 */

#include "CUartPort.h"

CUartPort::CUartPort(port_t port, uint32_t baudrate, uint8_t bits,
		parity_t parity, uint8_t stopbits, uint16_t bufferSizeRx,
		uint16_t bufferSizeTx) : CPort(bufferSizeTx, bufferSizeRx)
{
}

RC_t CUartPort::writeByte_hw(uint8_t data){
	return RC_SUCCESS;
}
RC_t CUartPort::readByte_hw(uint8_t& data){
	return RC_SUCCESS;
}

