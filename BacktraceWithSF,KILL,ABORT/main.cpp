#define BOOST_LOG_DYN_LINK
#define BOOST_STACKTRACE_DYN_LINK

#include <iostream>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>
#include <boost/stacktrace.hpp>
#include "temp.h"
#include <csignal>

using namespace std;
namespace Log = boost::log;


void fun5() {
	
	Temp temp;
	cout << "before infun5" << endl;
	temp.fun();
	cout << "after infun5" << endl;
}

void signal_handler(int signum)
{


    cout << "Signal code: " << signum;
    cout << "\n" << boost::stacktrace::stacktrace()
         << "-----------------------------------------------------------------------------\n";

    
    signal(signum, SIG_DFL);
}


int main()
{
    signal(SIGSEGV, signal_handler);
    signal(SIGKILL, signal_handler);
    signal(SIGABRT, signal_handler);

    cout << "before fun5" << endl;
    fun5();
    cout << "after fun5" << endl;
     
    string* ptr = nullptr;
    *ptr = "simant";

    cout << "after" << endl;

    return 0;
}

