/*
 * CCanPort.cpp
 *
 *  Created on: Mar 11, 2021
 *      Author: reza
 */

#include "CCanPort.h"
#include <iostream>
#include "CCentralErrorHandler.h"

uint16_t CCanPort::m_noCanPort = 0;

CCanPort::CCanPort(port_t port,
			 uint32_t baudrate,
			 uint16_t bufferSizeRx,
			 uint16_t bufferSizeTx,
			 uint16_t packagesize
			 ) : CPort(bufferSizeTx, bufferSizeRx){
		m_packageSize = packagesize;
}

RC_t CCanPort::writeByte_hw(CTRingBuffer<uint8_t>& package){

	std::cout << "Just wrote to CAN hardware: Package: [ "
			<< package.operator std::__cxx11::basic_string<char,
			std::char_traits<char>,std::allocator<char>>() << " ]" << std::endl;
	return RC_SUCCESS;
}

void CCanPort::noCanPortIncreament() {
	CCanPort::m_noCanPort++;
}

uint16_t CCanPort::getNoCanPort(){
	return CCanPort::m_noCanPort;
}

RC_t CCanPort::readByte_hw(CTRingBuffer<uint8_t>& package){
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

		std::cout << "Just read from CAN hardware: Package: [ "
				<< package.operator std::__cxx11::basic_string<char,
				std::char_traits<char>,std::allocator<char>>() << " ]" << std::endl;
		return RC_SUCCESS;
	}
	else
	{
		return RC_NODATA;
	}
}

uint16_t CCanPort::getDriverPackageSize() const{
	return m_packageSize;
}
