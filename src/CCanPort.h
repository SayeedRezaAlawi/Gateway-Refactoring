/*
 * CCanPort.h
 *
 *  Created on: Mar 11, 2021
 *      Author: reza
 */

#ifndef CCANPORT_H_
#define CCANPORT_H_

#include "CPort.h"
#include "cfg.h"

#define CAN_DEFAULTBUFFERSIZE 64
#define CAN_DEFAULTBYTESIZE 8

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
			 uint16_t bufferSizeTx = CAN_DEFAULTBUFFERSIZE,
			 uint16_t packagesize = 8
			 );
	static void noCanPortIncreament();
	static uint16_t getNoCanPort();

private:
	RC_t writeByte_hw(CTRingBuffer<uint8_t>& package);
	RC_t readByte_hw(CTRingBuffer<uint8_t>& package);
	uint16_t getDriverPackageSize() const;
	uint16_t m_packageSize;
private:
	static uint16_t m_noCanPort;
};

#endif /* CCANPORT_H_ */
