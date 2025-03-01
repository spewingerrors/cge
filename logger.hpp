#ifndef LOGGER_H
#define LOGGER_H
#include <string>
#include <ctime>
#include <filesystem> 

struct Logger {
    std::string filename;
    std::filesystem::path pathname;

    Logger();
    Logger(std::filesystem::path relativePath);
    void File(std::string filename);
    void Write(std::string toLogger);
    std::string Time();
};


#endif
