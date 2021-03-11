/*
 * CUartPort.cpp
 *
 *  Created on: Mar 11, 2021
 *      Author: reza
 */

#include "CUartPort.h"
#include <iostream>

CUartPort::CUartPort(port_t port, uint32_t baudrate, uint8_t bits,
		parity_t parity, uint8_t stopbits, uint16_t bufferSizeRx,
		uint16_t bufferSizeTx) : CPort(bufferSizeTx, bufferSizeRx)
{
}

RC_t CUartPort::writeByte_hw(uint8_t data){
	std::cout << "Just wrote to UART hardware: " << data << std::endl;
	return RC_SUCCESS;
}
RC_t CUartPort::readByte_hw(uint8_t& data){
	static uint8_t fakeData = 'a';
	static uint8_t counter = 0;

	counter++;
	if(counter >= 20) return RC_NODATA;

	data = fakeData++;

	std::cout << "Just read from UART hardware: " << data << std::endl;

	return RC_SUCCESS;
}

