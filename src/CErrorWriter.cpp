/*
 * CErrorWriter.cpp
 *
 *  Created on: Mar 19, 2021
 *      Author: reza
 */

#include "CErrorWriter.h"

CErrorWriter::CErrorWriter(std::ostream &stream) : m_out{stream} {
}

void CErrorWriter::operator ()(std::string message) {
	m_out << message << std::endl;
}

CErrorWriter::~CErrorWriter() {
}
