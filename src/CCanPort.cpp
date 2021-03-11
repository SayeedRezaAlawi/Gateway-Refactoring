/*
 * CCanPort.cpp
 *
 *  Created on: Mar 11, 2021
 *      Author: reza
 */

#include "CCanPort.h"

CCanPort::CCanPort(port_t port,
			 uint32_t baudrate,
			 uint16_t bufferSizeRx,
			 uint16_t bufferSizeTx
			 ):CPort(bufferSizeTx,bufferSizeRx){

}
RC_t CCanPort::writeByte_hw(uint8_t data){
	return RC_SUCCESS;
}
RC_t CCanPort::readByte_hw(uint8_t& data){
	return RC_SUCCESS;
}

