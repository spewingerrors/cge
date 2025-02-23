#include <iostream>
#include <fstream>
#include <string>
#include "logger.hpp"

Logger::Logger(std::string filename) {
    std::ofstream logfile;
    logfile.open(filename);
    if (logfile.is_open()) {
        logfile << "Successfully created logger.\n";
        this->filename = filename;
        logfile.close();
    }
    else {
        std::cout << "Unable to create logger.\n";
    }
}

void Logger::WriteToLogger(std::string toLogger) {
    std::ofstream logfile;
    logfile.open(this->filename);
    if (logfile.is_open()) {
        logfile << toLogger;
        logfile.close();
    }
    else {
        std::cout << "Unable to write to logger.\n";
    }
}