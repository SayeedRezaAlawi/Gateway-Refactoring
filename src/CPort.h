/*
 * CPort.h
 *
 *  Created on: Mar 11, 2021
 *      Author: reza
 */

#ifndef CPORT_H_
#define CPORT_H_
#include "CTRingBuffer.h"
#include <string>

class CPort {
protected:
	CTRingBuffer<uint8_t> m_ringBufferTx;
	CTRingBuffer<uint8_t> m_ringBufferRx;
public:
	CPort(uint16_t txSize = 10, uint16_t rxSize = 10);
	RC_t writeByteStream(std::string const& data);
	RC_t readByteStream(std::string& data);
	RC_t portTx_isr();
	RC_t portRx_isr();
private:
	virtual RC_t writeByte_hw(CTRingBuffer<uint8_t>& package) = 0;
	virtual RC_t readByte_hw(CTRingBuffer<uint8_t>& package) = 0;
	virtual uint16_t getDriverPackageSize() const = 0;
};

#endif /* CPORT_H_ */
