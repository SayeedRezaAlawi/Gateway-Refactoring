/*
 * CGateway.cpp
 *
 *  Created on: Mar 11, 2021
 *      Author: reza
 */

#include "CGateway.h"
#include <iostream>
#include "CCentralErrorHandler.h"
#include <algorithm>

std::vector<CPort*> CGateway::m_usedPorts{0};

void terminateError()
{
	std::cerr << "Hard termination" << std::endl;
	std::terminate();
}

void terminateWarning()
{
	std::cerr << "No termination - program continues" << std::endl;
}


CGateway::CGateway(CPort *portA, CPort *portB) {
	CErrorWriter errwriter(std::cerr);
	CCentralErrorHandler errorTerminator(errwriter, terminateError);
	try
	{
		auto searchPortAResult = std::find(m_usedPorts.begin(), m_usedPorts.end(), portA);
		if (searchPortAResult != m_usedPorts.end())
		{
			throw CEH_PORT_OCCUPIED;
		}
		else if (dynamic_cast<CUartPort*>(portA)) {
			if(CUartPort::getNoUartPort() < PORT_ASCLINMAX){
				m_usedPorts.push_back(portA);
				m_portA = portA;
				CUartPort::noUartPortIncreament();
			}
			else{
				throw CEH_NO_MORE_UART_PORT;
			}
		}
		else if (dynamic_cast<CCanPort*>(portA)){
			if(CCanPort::getNoCanPort() < PORT_CANNMAX){
				m_usedPorts.push_back(portA);
				m_portA = portA;
				CCanPort::noCanPortIncreament();
			}
			else{
				throw CEH_NO_MORE_CAN_PORT;
			}
		}
		else{
			throw CEH_NULL_POINTER;
		}
	}catch(CEH_source_t& err)
	{
		errorTerminator.report(err);
	}

	try
	{
		auto searchPortBResult = std::find(m_usedPorts.begin(), m_usedPorts.end(), portB);
		if (searchPortBResult != m_usedPorts.end())
		{
			throw CEH_PORT_OCCUPIED;
		}
		else if (dynamic_cast<CUartPort*>(portB)) {
			if(CUartPort::getNoUartPort() < PORT_ASCLINMAX){
				m_usedPorts.push_back(portB);
				m_portB = portB;
				CUartPort::noUartPortIncreament();
			}
			else{
				throw CEH_NO_MORE_UART_PORT;
			}
		}
		else if (dynamic_cast<CCanPort*>(portB)){
			if(CCanPort::getNoCanPort() < PORT_CANNMAX){
				m_usedPorts.push_back(portB);
				m_portB = portB;
				CCanPort::noCanPortIncreament();
			}
			else{
				throw CEH_NO_MORE_CAN_PORT;
			}
		}
		else{
			throw CEH_NULL_POINTER;
		}
	}catch(CEH_source_t& err)
	{
		errorTerminator.report(err);
	}
	m_portA->portRx_isr();
}

CGateway::CGateway(CPortFactory::port_t portA, CPortFactory::port_t portB){
	CErrorWriter errwriter(std::cerr);
	CCentralErrorHandler errorTerminator(errwriter, terminateError);
	switch(portA){
	case CPortFactory::UART:
		try{
			if(CUartPort::getNoUartPort() < PORT_ASCLINMAX){
				std::cout << "step01 " << std::endl;
				m_portA = CPortFactory::createUartPort();
				m_usedPorts.push_back(m_portA);
				CUartPort::noUartPortIncreament();
			}
			else{
				throw CEH_NO_MORE_UART_PORT;
			}
		}catch(CEH_source_t& err)
		{
			errorTerminator.report(err);
		}
		break;
	case CPortFactory::CAN:
		try{
			if(CCanPort::getNoCanPort() < PORT_CANNMAX){
				m_portA = CPortFactory::createCanPort();
				m_usedPorts.push_back(m_portA);
				CCanPort::noCanPortIncreament();
			}
			else{
				throw CEH_NO_MORE_CAN_PORT;
			}
		}catch(CEH_source_t& err)
		{
			errorTerminator.report(err);
		}
		break;
	default:
		break;
	}

	switch(portB){
	case CPortFactory::UART:
		try{
			if(CUartPort::getNoUartPort() < PORT_ASCLINMAX){
					m_portB = CPortFactory::createUartPort();
					m_usedPorts.push_back(m_portB);
					std::cout << "step02 " << std::endl;
					CUartPort::noUartPortIncreament();
			}
			else{
				throw CEH_NO_MORE_UART_PORT;
			}
		}catch(CEH_source_t& err)
		{
			errorTerminator.report(err);
		}
		break;
	case CPortFactory::CAN:
		try{
			if(CCanPort::getNoCanPort() < PORT_CANNMAX){
				m_portB = CPortFactory::createCanPort();
				m_usedPorts.push_back(m_portB);
				CCanPort::noCanPortIncreament();
			}
			else{
				throw CEH_NO_MORE_CAN_PORT;
			}
		}catch(CEH_source_t& err)
		{
			errorTerminator.report(err);
		}
		break;
	default:
		break;
	}
	m_portA->portRx_isr();
}

RC_t CGateway::transmitFromAToB(){

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
