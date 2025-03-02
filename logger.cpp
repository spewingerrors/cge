#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <filesystem>
#include "logger.hpp"

Logger::Logger() {
    this->filename = "pilot.log";
    std::filesystem::path defaultpath = "./logs/";
    if (!(std::filesystem::exists(defaultpath))) {
        std::cout << "Unable to find path.\n";
        if (std::filesystem::create_directory(defaultpath)) {
            std::cout << "Successfully created path.\n";
        } else {
            this->filename = "error.log";
            this->pathname = "";
        }
    }
    this->pathname = defaultpath;
    this->Write("Successfully created logger.");
}

void Logger::Branch(std::string newfilename) {
    if (this->filename != newfilename) {
        this->Write("Switching logger from " + this->filename + " to " + newfilename + ".");
        this->filename = newfilename;
    }
    this->Write("Successfully branched to " + newfilename + ".");
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
    retval = month + "/" + day + "/" + year + "@" + hour + ":" + minute + ":" + second + "->";
    return retval;
}

void Logger::Write(std::string toLogger) {
    //std::ofstream logfile(this->pathname.string() + filename);
    std::ofstream logfile;
    //logfile.open(this->filename, std::ios::app);
    logfile.open(this->pathname.string() + this->filename, std::ios::app);
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
        this->pathname = "";
        this->filename = "error.log";
        // This should probably be tested to ensure it can't 
        // go out of control.
        this->Write("Logger errored while trying to write \"" + toLogger + "\".");
    }
}
