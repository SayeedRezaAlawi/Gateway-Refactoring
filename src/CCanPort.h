/*
 * CCanPort.h
 *
 *  Created on: Mar 11, 2021
 *      Author: reza
 */

#ifndef CCANPORT_H_
#define CCANPORT_H_

#include "CPort.h"

#define CAN_DEFAULTBUFFERSIZE 64

class CCanPort : public CPort {
public:
	enum port_t{
	CAN1,		/**< \brief CAN Port 1 */
	CAN2, 		/**< \brief CAN Port 2 */
	NONE,		/**< \brief default value no valid port */
	};
public:
	CCanPort(port_t port = NONE,
			 uint32_t baudrate = 1000000,
			 uint16_t bufferSizeRx = CAN_DEFAULTBUFFERSIZE,
			 uint16_t bufferSizeTx = CAN_DEFAULTBUFFERSIZE
			 );
private:
	RC_t writeByte_hw(uint8_t data);
	RC_t readByte_hw(uint8_t& data);
};

#endif /* CCANPORT_H_ */