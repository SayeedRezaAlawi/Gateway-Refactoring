/*
 * CUartPort.cpp
 *
 *  Created on: Mar 11, 2021
 *      Author: reza
 */

#include "CUartPort.h"
#include <iostream>
#include "CCentralErrorHandler.h"
#include "cfg.h"

uint16_t CUartPort::m_noUartPort = 0;

CUartPort::CUartPort(port_t port, uint32_t baudrate, uint8_t bits,
		parity_t parity, uint8_t stopbits, uint16_t bufferSizeRx,
		uint16_t bufferSizeTx, uint16_t packagesize): CPort(bufferSizeTx, bufferSizeRx){
	m_packageSize = packagesize;
}

RC_t CUartPort::writeByte_hw(CTRingBuffer<uint8_t>& package){
	std::cout << "Just wrote to UART hardware: Package: [ "
				<< package.operator std::__cxx11::basic_string<char,
				std::char_traits<char>,std::allocator<char>>() << " ]" << std::endl;
		return RC_SUCCESS;
}
RC_t CUartPort::readByte_hw(CTRingBuffer<uint8_t>& package){
	static uint8_t fakeData = 'a';
	static uint8_t counter = 0;
	RC_t result = RC_ERROR;
	if(counter < 20)
	{
		do{
			result = package.write(fakeData);
			if(result == RC_SUCCESS){
				fakeData++;
				counter++;
			}
		}while(result == RC_SUCCESS && counter < 20);

		std::cout << "Just read from UART hardware: Package: [ "
				<< package.operator std::__cxx11::basic_string<char,
				std::char_traits<char>,std::allocator<char>>() << " ]" << std::endl;
		return RC_SUCCESS;
	}
	else
	{
		return RC_NODATA;
	}
}

uint16_t CUartPort::getDriverPackageSize() const{
	return m_packageSize;
}

void CUartPort::noUartPortIncreament() {
	CUartPort::m_noUartPort++;
}

uint16_t CUartPort::getNoUartPort(){
	return CUartPort::m_noUartPort;
}
