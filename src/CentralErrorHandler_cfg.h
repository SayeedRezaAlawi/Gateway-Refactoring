/*
 * CentralErrorHandler_cfg.h
 *
 *  Created on: Mar 19, 2021
 *      Author: reza
 */

#ifndef CENTRALERRORHANDLER_CFG_H_
#define CENTRALERRORHANDLER_CFG_H_

#define CEH_CFG_ENUM(name, report, terminate)		CEH_##name,

#define CEH_CFG_ENUM_STR(name, report, terminate)	#name,

#define CEH_CFG_ENTRY(name, report, terminate)		{CEH_##name, report, terminate},



#define CEH_CFG(DEF)\
		DEF(			EMPTY,						false,			false)		/**< \brief  NOP, do not remove */													\
		DEF(			PORT_EMPTY,					true,			false)		/**< \brief  Buffer was empty, error e.g. in case of read operation */				\
		DEF(			PORT_OCCUPIED,				true,			true)		/**< \brief  Buffer was empty, error e.g. in case of read operation */				\
		DEF(			NO_MORE_UART_PORT,			true,			true)		/**< \brief  Buffer was full, error e.g. in case of write operation */				\
		DEF(			NO_MORE_CAN_PORT,			true,			true)		/**< \brief  Buffer was full, error e.g. in case of write operation */				\
		DEF(			NULL_POINTER,				true,			true)		/**< \brief  Invalid Pointer */														\

typedef enum
{
			CEH_CFG(CEH_CFG_ENUM)CEH_SOURCE_MAX
} CEH_source_t;

typedef struct
{
	CEH_source_t source;
	bool report;
	bool terminate;
} CEH_event_table_entry_t;

#endif /* CENTRALERRORHANDLER_CFG_H_ */
