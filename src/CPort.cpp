/*
 * CPort.cpp
 *
 *  Created on: Mar 11, 2021
 *      Author: reza
 */

#include "CPort.h"

CPort::CPort(uint16_t txSize, uint16_t rxSize) : m_ringBufferRx(rxSize), m_ringBufferTx(txSize){
}

RC_t CPort::writeByteStream(const std::string &data) {
	return RC_SUCCESS;
}

RC_t CPort::readByteStream(std::string &data) {
	return RC_SUCCESS;;
}

RC_t CPort::portTx_isr(){
	return RC_SUCCESS;;
}
RC_t CPort::portRx_isr(){
	return RC_SUCCESS;;
}
