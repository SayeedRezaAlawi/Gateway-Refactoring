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
		uint16_t bufferSizeTx) : CPort(bufferSizeTx, bufferSizeRx){
	m_packageSize = UART_DEFAULTBYTESIZE;
}

RC_t CUartPort::writeByte_hw(CTRingBuffer<uint8_t> package){
	std::string datastream ="";
	uint8_t ldata;
	RC_t result = RC_ERROR;
	do{
		result = package.read(ldata);
		if(result == RC_SUCCESS){
			datastream += (char)ldata;
		}

	}while(result == RC_SUCCESS);
	std::cout << "Just wrote to UART hardware: " << datastream << std::endl;
	return RC_SUCCESS;
}
RC_t CUartPort::readByte_hw(CTRingBuffer<uint8_t>& package){
	static uint8_t fakeData = 'a';
	static uint8_t counter = 0;
	RC_t result = RC_ERROR;
	CTRingBuffer<uint8_t> packagedata(getDriverPackageSize());
	do{
		result = packagedata.write(fakeData);
		if(result == RC_SUCCESS){
			fakeData++;
			counter++;
		}
	}while(result == RC_SUCCESS && counter < 20);
	fakeData--;
	package = packagedata;

	std::cout << "Just read from UART hardware: Package: [ "
				<< package.operator std::__cxx11::basic_string<char,
				std::char_traits<char>,std::allocator<char>>() << " ]" << std::endl;
		fakeData--;

	if (counter >= 20) return RC_NODATA;

	return RC_SUCCESS;
}

uint16_t CUartPort::getDriverPackageSize(){
	return m_packageSize;
}

