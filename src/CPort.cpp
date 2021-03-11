/*
 * CPort.cpp
 *
 *  Created on: Mar 11, 2021
 *      Author: reza
 */

#include "CPort.h"

CPort::CPort(uint16_t txSize, uint16_t rxSize) : m_ringBufferRx(rxSize), m_ringBufferTx(txSize){
}

RC_t CPort::writeByteStream(std::string const& data) {
	RC_t result = RC_ERROR;

	for(uint16_t i =0; i < data.length();i++){
		result = m_ringBufferTx.write(data[i]);
		if(RC_SUCCESS != result) return RC_ERROR;
	}
	portTx_isr();
	return RC_SUCCESS;
}

RC_t CPort::readByteStream(std::string &data) {
	std::string dataFromDriver = "";
	RC_t result = RC_ERROR;
	do{
		uint8_t ldata = 0;
		result = m_ringBufferRx.read(ldata);
		if(result == RC_SUCCESS){
			dataFromDriver += (char)ldata;
		}
	}while(RC_SUCCESS == result);
	data = dataFromDriver;
	return RC_SUCCESS;;
}

RC_t CPort::portTx_isr(){
	RC_t result = RC_ERROR;

	do{
		uint8_t data = 0;
		result = m_ringBufferTx.read(data);
		if(RC_SUCCESS == result)
		{
			writeByte_hw(data);
		}
	}while(RC_SUCCESS == result);

	return RC_SUCCESS;
}
RC_t CPort::portRx_isr(){
	RC_t result = RC_ERROR;
	do
	{
		uint8_t data = 0;

		result = readByte_hw(data);
		if (RC_SUCCESS == result)
		{
			m_ringBufferRx.write(data);
		}

	} while (RC_SUCCESS == result);

	return RC_SUCCESS;
}
