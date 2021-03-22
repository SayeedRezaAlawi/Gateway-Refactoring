/*
 * CPortFactory.h
 *
 *  Created on: Mar 20, 2021
 *      Author: reza
 */

#ifndef CPORTFACTORY_H_
#define CPORTFACTORY_H_
#include "CPort.h"
#include "CCanPort.h"
#include "CUartPort.h"

class CPortFactory {
public:
	enum port_t
	{
		UART, CAN, NONE
	};
	static CPort* createCanPort(
			CCanPort::port_t port = CCanPort::NONE,
			uint32_t baudrate = 1000000,
			uint16_t bufferSizeRx = CAN_DEFAULTBUFFERSIZE,
			uint16_t bufferSizeTx = CAN_DEFAULTBUFFERSIZE,
			uint16_t packagesize = 8);

	static CPort* createUartPort(
			CUartPort::port_t port = CUartPort::NONE,
			uint32_t baudrate = 115200,
			uint8_t bits = 8,
			CUartPort::parity_t parity = CUartPort::NOPARITY,
			uint8_t stopbits = 1,
			uint16_t bufferSizeRx =UART_DEFAULTBUFFERSIZE,
			uint16_t bufferSizeTx = UART_DEFAULTBUFFERSIZE,
			uint16_t packagesize = 1);
	static CPort* createPort(port_t port);
};

#endif /* CPORTFACTORY_H_ */
