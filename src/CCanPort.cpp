/*
 * CCanPort.cpp
 *
 *  Created on: Mar 11, 2021
 *      Author: reza
 */

#include "CCanPort.h"
#include <iostream>

CCanPort::CCanPort(port_t port,
			 uint32_t baudrate,
			 uint16_t bufferSizeRx,
			 uint16_t bufferSizeTx
			 ):CPort(bufferSizeTx,bufferSizeRx){

}
RC_t CCanPort::writeByte_hw(uint8_t data){
	std::cout << "Just wrote to CAN hardware: " << data << std::endl;
	return RC_SUCCESS;
}
RC_t CCanPort::readByte_hw(uint8_t& data){
	static uint8_t fakeData = 'a';
	static uint8_t counter = 0;

	counter++;

	if (counter >= 20) return RC_NODATA;

	data = fakeData++;

	std::cout << "Just read from CAN hardware: " << data << std::endl;
	return RC_SUCCESS;
}

