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
	m_packageSize = CAN_DEFAULTBYTESIZE;
}
RC_t CCanPort::writeByte_hw(CTRingBuffer<uint8_t> package){

	std::cout << "Just wrote to CAN hardware: Package: [ "
			<< package.operator std::__cxx11::basic_string<char,
			std::char_traits<char>,std::allocator<char>>() << " ]" << std::endl;
	return RC_SUCCESS;
}
RC_t CCanPort::readByte_hw(CTRingBuffer<uint8_t>& package){
	static uint8_t fakeData = 'a';
	static uint8_t counter = 0;
	RC_t result = RC_ERROR;
	CTRingBuffer<uint8_t> packagedata(getDriverPackageSize());
	if(counter < 20)
	{
		do{
			result = packagedata.write(fakeData);
			if(result == RC_SUCCESS){
				fakeData++;
				counter++;
			}
		}while(result == RC_SUCCESS && counter < 20);
		fakeData--;
		package = packagedata;

		std::cout << "Just read from CAN hardware: Package: [ "
				<< package.operator std::__cxx11::basic_string<char,
				std::char_traits<char>,std::allocator<char>>() << " ]" << std::endl;
		fakeData--;
		return RC_SUCCESS;
	}
	else
	{
//		std::cout << "return RC_NODATA" << std::endl;
		return RC_NODATA;
	}


}

uint16_t CCanPort::getDriverPackageSize(){
	return m_packageSize;
}

