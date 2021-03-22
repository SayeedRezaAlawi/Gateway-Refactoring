/*
 * CCentralErrorHandler.h
 *
 *  Created on: Mar 19, 2021
 *      Author: reza
 */

#ifndef CCENTRALERRORHANDLER_H_
#define CCENTRALERRORHANDLER_H_

#include <string>
#include "global.h"
#include "CentralErrorHandler_cfg.h"
#include "CErrorWriter.h"

class CCentralErrorHandler {
public:
	typedef void (*fct_out_t)(std::string errMsg);
	typedef void (*fct_terminate_t)();
private:
	CErrorWriter& m_outFct;
	fct_terminate_t m_terminateFct;
public:
	CCentralErrorHandler(CErrorWriter& errorFct,
				fct_terminate_t terminateFct = 0);

	RC_t report(CEH_source_t err);
};

#endif /* CCENTRALERRORHANDLER_H_ */
