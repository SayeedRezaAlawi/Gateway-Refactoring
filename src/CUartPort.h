/*
 * CUartPort.h
 *
 *  Created on: Mar 11, 2021
 *      Author: reza
 */

#ifndef CUARTPORT_H_
#define CUARTPORT_H_
#include "CPort.h"

#define UART_DEFAULTBUFFERSIZE 20
#define UART_DEFAULTBYTESIZE 1

class CUartPort : public CPort {
public:
	enum port_t{
		ASCLIN1,		/**< \brief ASCLIN Port 1, per default mapped to USB bridge */
		ASCLIN2, 		/**< \brief ASCLIN Port 2, can be mapped to PIN P12(0),PIN P12(2) */
		ASCLIN3, 		/**< \brief ASCLIN Port 3, can be mapped to PIN P12(3),PIN P12(4) */
		ASCLIN4, 		/**< \brief ASCLIN Port 4, can be mapped to PIN P12(1),PIN P12(5) */
		ASCLIN5, 		/**< \brief ASCLIN Port 5, can be mapped to PIN P12(6) */
		NONE,			/**< \brief default value no valid port */
	};

	enum parity_t{
		ODD, 			/**< \brief ODD parity, will detect single bit transmission errors */
		EVEN, 			/**< \brief EVEN parity, will detect single bit transmission errors */
		NOPARITY,		/**< \brief NO parity check, only recommended for baudrates below 115200 */
	};

public:
	CUartPort(
			port_t port = NONE,
			uint32_t baudrate = 115200,
			uint8_t bits = 8,
			parity_t parity = NOPARITY,
			uint8_t stopbits = 1,
			uint16_t bufferSizeRx = UART_DEFAULTBUFFERSIZE,
			uint16_t bufferSizeTx = UART_DEFAULTBUFFERSIZE);
private:
	RC_t writeByte_hw(CTRingBuffer<uint8_t> package);
	RC_t readByte_hw(CTRingBuffer<uint8_t>& package);
	uint16_t getDriverPackageSize();
	uint16_t m_packageSize;
};

#endif /* CUARTPORT_H_ */
