#ifndef LOGGER_H
#define LOGGER_H
#include <string>

struct Logger {
    std::string filename;
    Logger(std::string filename);
    void WriteToLogger(std::string toLogger);
};


#endif
