#include "temp.h"
#include <iostream>
using namespace std;

void Temp::fun2() {
	int *ptr = nullptr;
        *ptr = 2;
}

void Temp::fun(){
	std::cout << "Hello" << std::endl;
	fun2();
}

