/*
 * CGateway.h
 *
 *  Created on: Mar 11, 2021
 *      Author: reza
 */

#ifndef CGATEWAY_H_
#define CGATEWAY_H_
#include "CPort.h"

class CGateway {
private:
	CPort* m_portA;
	CPort* m_portB;
public:
	CGateway(CPort* portA, CPort* portB);
	RC_t transmitFromAToB();
	virtual ~CGateway();
};

#endif /* CGATEWAY_H_ */
