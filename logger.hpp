#ifndef LOGGER_H
#define LOGGER_H
#include <string>
#include <ctime>

struct Logger {
    std::string filename;
    Logger(std::string filename);
    Logger() : Logger("log.log") {
        this->filename = "log.log";
    };
    void WriteToLogger(std::string toLogger);
    std::string Time();
};


#endif
