/*
 * CGateway.h
 *
 *  Created on: Mar 11, 2021
 *      Author: reza
 */

#ifndef CGATEWAY_H_
#define CGATEWAY_H_
#include "CPort.h"
#include "CPortFactory.h"
#include "cfg.h"
#include <vector>

class CGateway {
private:
	CPort* m_portA;
	CPort* m_portB;
	static std::vector<CPort*> m_usedPorts;
public:
	CGateway(CPort* portA, CPort* portB);
	CGateway(CPortFactory::port_t portA, CPortFactory::port_t portB);
	RC_t transmitFromAToB();
	virtual ~CGateway();
};

#endif /* CGATEWAY_H_ */
