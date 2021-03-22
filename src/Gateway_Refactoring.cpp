//============================================================================
// Name        : Gateway_Refactoring.cpp
// Author      : Sayeed Reza Alawi
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "CPort.h"
#include "CUartPort.h"
#include "CCanPort.h"
#include "CGateway.h"
using namespace std;

int main() {
	CCanPort can1;
	CCanPort can2;
	CCanPort can3;
	CCanPort can4;
	CUartPort uart1;
	CUartPort uart2;
	CUartPort uart3;
	CUartPort uart4;
	CUartPort uart5;
	CUartPort uart6;


//	CUartPort* uart6=0;
	CGateway gw1(&can1,&uart1);
	CGateway gw2(&can2,&uart2);
//	CGateway gw3(&uart3,&uart4);
	CGateway gw4(&can1,&can2);
	gw4.transmitFromAToB();
//	CGateway gw5(&uart1,uart3);

//	CGateway gw6(CPortFactory::UART,CPortFactory::CAN);
//	gw6.transmitFromAToB();
//	CGateway gw7(CPortFactory::UART,CPortFactory::UART);
//	CGateway gw8(CPortFactory::UART,CPortFactory::UART);
//	CGateway gw9(CPortFactory::UART,CPortFactory::UART);

//	gw1.transmitFromAToB();
//	gw2.transmitFromAToB();
//	gw3.transmitFromAToB();
	return 0;
}
