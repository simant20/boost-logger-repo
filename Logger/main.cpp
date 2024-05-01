#include "mainwindow.h"

#include <QApplication>
#include <iostream>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>
#include <boost/stacktrace.hpp>
#include <csignal>

using namespace std;
namespace Log = boost::log;


void fun5() {
    MainWindow temp;
    temp.fun1();
}

void signal_handler(int signum)
{
    cout << "Signal code: " << signum << endl;
    cout << "\n" << boost::stacktrace::stacktrace()
         << "-----------------------------------------------------------------------------\n" <<endl;

    signal(signum, SIG_DFL);
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    signal(SIGSEGV, signal_handler);
    signal(SIGKILL, signal_handler);
    signal(SIGABRT, signal_handler);

    fun5();

    string* ptr = nullptr;
    *ptr = "simant";

    return a.exec();
}
