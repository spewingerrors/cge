#ifndef LOGGER_H
#define LOGGER_H
#include <string>
#include <ctime>

struct Logger {
    std::string filename;
    Logger();
    void File(std::string filename);
    //Logger() : Logger("debug.log") {
    //    this->filename = "debug.log";
    //};
    void Write(std::string toLogger);
    std::string Time();
};


#endif
