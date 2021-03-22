/*
 * CErrorWriter.h
 *
 *  Created on: Mar 19, 2021
 *      Author: reza
 */

#ifndef CERRORWRITER_H_
#define CERRORWRITER_H_

#include <string>
#include <iostream>

class CErrorWriter {
private:
	std::ostream &m_out;
public:
	CErrorWriter(std::ostream& stream = std::cerr);
	void operator()(std::string message);
	~CErrorWriter();
};

#endif /* CERRORWRITER_H_ */
