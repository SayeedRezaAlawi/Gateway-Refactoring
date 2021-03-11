/*
 * CGateway.cpp
 *
 *  Created on: Mar 11, 2021
 *      Author: reza
 */

#include "CGateway.h"

CGateway::CGateway(CPort *portA, CPort *portB) {
	m_portA = portA;
	m_portB = portB;
	m_portA->portRx_isr();
}

RC_t CGateway::transmitFromAToB(){

	if( 0 == m_portA || 0 == m_portB)
	{
		return RC_ERROR;
	}

	RC_t result = RC_ERROR;
	//Transmit from A to B
	std::string data;

	//Read the data
	result = m_portA->readByteStream(data);

	//Do something with the data

	//Write the data
	result = m_portB->writeByteStream(data);

	return result;
}

CGateway::~CGateway() {
	m_portA = 0;
	m_portB = 0;
}

