#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include "logger.hpp"

Logger::Logger(std::string filename) {
    std::ofstream logfile;
    logfile.open(filename, std::ios::app);
    if (logfile.is_open()) {
        logfile << Time();
        logfile << "Successfully created logger.\n";
        this->filename = filename;
        logfile.close();
    }
    else {
        std::cout << "Unable to create logger.\n";
    }
}

std::string Logger::Time() {
    const time_t now = std::time(0);
    std::tm* curtime = std::localtime(&now);
    std::string day, month, year, hour, minute, second, retval;
    month = std::to_string(curtime->tm_mon);
    day = std::to_string(curtime->tm_mday);
    year = std::to_string(curtime->tm_year + 1900);
    hour = std::to_string(curtime->tm_hour);
    minute = std::to_string(curtime->tm_min);
    second = std::to_string(curtime->tm_sec);
    retval = month + "/" + day + "/" + year + "," + hour + ":" + minute + ":" + second + "->";
    return retval;
}

void Logger::WriteToLogger(std::string toLogger) {
    std::ofstream logfile;
    logfile.open(this->filename, std::ios::app);
    if (logfile.is_open()) {
        char end = toLogger.back();
        if (end != '\n') {
            toLogger += "\n";
        }
        logfile << Time();
        logfile << toLogger;
        logfile.close();
    }
    else {
        std::cout << "Unable to write to logger.\n";
    }
}
