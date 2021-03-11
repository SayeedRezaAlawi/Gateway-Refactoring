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
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	CCanPort can2;
	CCanPort can1;
	CGateway gw1(&can2,&can1);
	gw1.transmitFromAToB();
	return 0;
}
