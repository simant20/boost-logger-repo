TEMPLATE = app
CONFIG += c++11
CONFIG -= app_bundle
CONFIG -= qt


LIBS += -lboost_log_setup -lboost_log -lboost_thread -lboost_stacktrace_backtrace

DEFINES += \
        BOOST_LOG_DYN_LINK\
        BOOST_STACKTRACE_DYN_LINK\


SOURCES += \
        main.cpp
