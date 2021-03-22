/*
 * CCentralErrorHandler.cpp
 *
 *  Created on: Mar 19, 2021
 *      Author: reza
 */

#include "CCentralErrorHandler.h"

const char* const CEH__source_strings[] =
{ CEH_CFG(CEH_CFG_ENUM_STR)};

const CEH_event_table_entry_t CEH_event_table[]=
{
		CEH_CFG(CEH_CFG_ENTRY)
};

CCentralErrorHandler::CCentralErrorHandler(CErrorWriter& errorFct,
				fct_terminate_t terminateFct) :
				m_outFct(errorFct), m_terminateFct(terminateFct){
}

RC_t CCentralErrorHandler::report(CEH_source_t err){

	uint16_t index = (uint16_t) err;

	if(0 == m_terminateFct){
		return RC_ERROR;
	}
	std::string errorMessage = CEH__source_strings[index];

	if(true == CEH_event_table[index].report)
	{
		m_outFct(errorMessage);
	}

	if(true == CEH_event_table[index].terminate)
	{
		m_terminateFct();
	}
	return RC_SUCCESS;
}
