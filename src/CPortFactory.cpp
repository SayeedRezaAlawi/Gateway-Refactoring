/*
 * CPortFactory.cpp
 *
 *  Created on: Mar 20, 2021
 *      Author: reza
 */

#include "CPortFactory.h"

CPort* CPortFactory::createCanPort(CCanPort::port_t port, uint32_t baudrate,
		uint16_t bufferSizeRx, uint16_t bufferSizeTx, uint16_t packagesize) {
	return new CCanPort(port, baudrate, bufferSizeRx, bufferSizeTx, packagesize);
}

CPort* CPortFactory::createUartPort(CUartPort::port_t port, uint32_t baudrate, uint8_t bits, CUartPort::parity_t parity,
			uint8_t stopbits, uint16_t bufferSizeRx, uint16_t bufferSizeTx, uint16_t packagesize){
	return new CUartPort(port, baudrate, bits, parity, stopbits, bufferSizeRx, bufferSizeTx, packagesize);
}

CPort* CPortFactory::createPort(port_t port){
	switch(port){
	case UART : return createUartPort();
	case CAN : return createCanPort();
	default : break;
	}
	return 0;
}
