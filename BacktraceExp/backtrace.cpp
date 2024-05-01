#define BOOST_LOG_DYN_LINK
#define BOOST_STACKTRACE_DYN_LINK
#include <iostream>
#include <boost/stacktrace.hpp>

using namespace std;

void fun2()
{
  cout << boost::stacktrace::stacktrace() << endl;
}

void fun1()
{
  fun2();
}

int main()
{
fun1();
return 0;
}
