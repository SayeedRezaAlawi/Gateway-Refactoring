/*
 * CTRingBuffer.h
 *
 *  Created on: Mar 8, 2021
 *      Author: reza
 */

#ifndef CTRINGBUFFER_H_
#define CTRINGBUFFER_H_
#include "global.h"

#define DEFAULTRINGBUFFERSIZE 10

template <class DATA>
class CTRingBuffer {
private:
	DATA* m_data;
	uint16_t m_size;
	uint16_t m_fillLevel;
	uint16_t m_writeIdx;
	uint16_t m_readIdx;
public:
	typedef DATA iterator;
	CTRingBuffer(uint16_t size = DEFAULTRINGBUFFERSIZE);
	bool write(const DATA element);
	bool read(DATA& element);
	CTRingBuffer<DATA>& operator=(const CTRingBuffer<DATA>& other);
	bool operator +=(const DATA& element);
	DATA operator *();
	uint16_t first();
	uint16_t last();
	void clear();
	virtual ~CTRingBuffer();
};

template<class DATA>
inline CTRingBuffer<DATA>::CTRingBuffer(uint16_t size) {
	if (size == 0)
	{
	size = 5;
	}
	m_size = size;
	m_fillLevel = 0;
	m_readIdx = 0;
	m_writeIdx = 0;
	m_data = new DATA[m_size];
	for(unsigned int i=0; i < m_size; i++){
		m_data[i] = DATA();
	}
}

template<class DATA>
inline bool CTRingBuffer<DATA>::write(const DATA element) {
	bool result = false;
	if(m_fillLevel < m_size){
		m_data[(m_writeIdx++) % m_size] = element;
		m_fillLevel++;
		result = true;
	}
	else{
		result = false;
		throw RC_BUFFEROVERFLOW;
	}
	return result;
}

template<class DATA>
inline bool CTRingBuffer<DATA>::read(DATA &element) {
	bool result = false;
	if(m_fillLevel > 0){
		element = m_data[m_readIdx++];
		m_readIdx %= m_size;
		m_fillLevel--;
		result = true;
	}
	else{
		result = false;
		throw RC_BUFFERUNDERFLOW;
	}
	return result;
}

template<class DATA>
inline CTRingBuffer<DATA>& CTRingBuffer<DATA>::operator =(const CTRingBuffer<DATA> &other) {
	m_size = other.m_size;
	m_fillLevel = other.m_fillLevel;
	m_readIdx = other.m_readIdx;
	m_writeIdx = other.m_writeIdx;
	m_data = new DATA[m_size];
	for(unsigned int i=0; i < m_size; i++){
		m_data[i] = other.m_data[i];
	}
}

template<class DATA>
inline bool CTRingBuffer<DATA>::operator +=(const DATA &element) {
	bool result = false;
	if(m_fillLevel < m_size){
		m_data[m_writeIdx++] = element;
		m_writeIdx %= m_size;
		m_fillLevel++;
		result = true;
	}
	else{
		result = false;
		throw RC_BUFFEROVERFLOW;
	}
	return result;
}

template<class DATA>
inline DATA CTRingBuffer<DATA>::operator *() {
	if (m_fillLevel > 0)
	{
		m_fillLevel--;
		return m_data[(m_readIdx++) % m_size];
	}
	else
	{
	throw RC_BUFFERUNDERFLOW;
	}
	return 0; //will never be reached
}

template<class DATA>
inline uint16_t CTRingBuffer<DATA>::first() {
	return m_readIdx;
}

template<class DATA>
inline uint16_t CTRingBuffer<DATA>::last() {
	if (m_writeIdx > m_readIdx)
	{
	return m_writeIdx;
	}
	else
	{
	return m_size + m_writeIdx - m_readIdx ;
	}
}

template<class DATA>
inline void CTRingBuffer<DATA>::clear() {
	m_fillLevel = 0;
	m_readIdx = 0;
	m_writeIdx = 0;
	for(unsigned int i=0; i < m_size; i++){
		m_data[i] = DATA();
	}
}

template<class DATA>
inline CTRingBuffer<DATA>::~CTRingBuffer() {
	delete [] m_data;
}

#endif /* CTRINGBUFFER_H_ */