#define BOOST_LOG_DYN_LINK
#define BOOST_STACKTRACE_DYN_LINK

#include <iostream>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>
#include <boost/stacktrace.hpp>
#include <csignal>

using namespace std;
namespace Log = boost::log;

class Temp 
{
public:
    void fun2() 
    {
        int *ptr = nullptr;
        *ptr = 2;
    }
    
    void fun1()
    {
        fun2();
    }
};

void fun5() 
{    
    Temp temp;
    temp.fun1();
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
    fun5();    
    string* ptr = nullptr;
    *ptr = "simant";    
    return 0;
}

