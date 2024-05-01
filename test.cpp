#include "test.h"
#include <iostream>

using namespace std;

Test::Test(const unsigned int &value) {
    ptr = new int(value);
}

void Test::fun1() {
    this->fun2();
}

void Test::fun2() {
    try {
        cout << "\n ptr: " << ptr << endl;
        cout << "\n*ptr: " << *ptr << endl;

    } catch (const exception &error) {
        cout << "\n Exception :- " << error.what() << endl;
    } catch (...) {
        cout << "\n Unhandled exception" << endl;
    }
}

void Test::_delete_() {
    if(ptr) delete ptr;
    ptr = NULL;
}
