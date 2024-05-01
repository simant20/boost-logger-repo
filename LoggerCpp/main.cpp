#include <iostream>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>
#include <boost/stacktrace.hpp>

using namespace std;
namespace Log = boost::log;

void init_logging() {

    Log::add_file_log(
        Log::keywords::file_name = "/mnt/Data/QT_Tasks/LoggerCpp/Logs/logs_%N.log",
        Log::keywords::rotation_size = 10 * 1024 * 1024,
        Log::keywords::time_based_rotation = Log::sinks::file::rotation_at_time_point(0, 0, 0),
        Log::keywords::open_mode = ios_base::app,
        Log::keywords::format = "[%TimeStamp%] [%ThreadID%] [%Severity%][%LineID%] %Message%"
    );

    string errorMessageFormat = "[%TimeStamp%] [%ThreadID%] [%Severity%][%LineID%] %Message%\n"
                                "-----------------------------------------------------------------------------------------------\n";
    Log::add_file_log(
        Log::keywords::file_name ="/mnt/Data/QT_Tasks/LoggerCpp/Logs/%Y-%m-%derror.log",
        Log::keywords::open_mode = ios_base::app,
        Log::keywords::format = errorMessageFormat,
        Log::keywords::filter = Log::trivial::severity >= Log::trivial::error
    );

        Log::core::get()->set_filter(
        Log::trivial::severity >= Log::trivial::info
   );
}

int main()
{
      init_logging();
      boost::log::add_common_attributes();

      BOOST_LOG_TRIVIAL(trace) << "This is a trace severity message";
      BOOST_LOG_TRIVIAL(debug) << "This is a debug severity message";
      BOOST_LOG_TRIVIAL(info) << "This is an informational severity message";
      BOOST_LOG_TRIVIAL(warning) << "This is a warning severity message";
      BOOST_LOG_TRIVIAL(error) << "This is an error severity message";
      BOOST_LOG_TRIVIAL(fatal) << "and this is a fatal severity message";
      return 0;
}
