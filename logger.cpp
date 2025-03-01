#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <filesystem>
#include "logger.hpp"

Logger::Logger() {
    std::filesystem::path defaultpath = "./logs/";
    if (std::filesystem::exists(defaultpath)) {
        std::cout << "###############################\n";
        std::cout << "### TOTALLY EXISTS.\n";
        std::cout << "###############################\n";
    }
    else {
        std::filesystem::create_directory(defaultpath);
        std::cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n";
        std::cout << "!!! We made it.\n";
        std::cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n";
    }
    this->filename = "pilot.log";
    this->pathname = defaultpath;
}

Logger::Logger(std::filesystem::path relativePath) {
    std::filesystem::path defaultpath = "";
    std::string filename;
    if (!(std::filesystem::exists(relativePath))) {
        // if the relative path doesn't exist, try to make it.
        if (!(std::filesystem::create_directory(relativePath))) {
            std::cerr << "Unable to resolve this path. ";
            std::cerr << "Defaulting logging to \"./logs/error.log\". ";
            std::cerr << "Check your path for errors." << std::endl;
            defaultpath = "";
            this->filename = "error.log";
            this->pathname = defaultpath;
        }
    } else {
        // if the realtive path DOES exist...
        this->pathname = relativePath;
    }
    this->filename = "pilot.log";
    this->pathname = defaultpath;
}

void Logger::File(std::string filename) {
    filename = this->pathname.string() + filename;
    if (this->filename != filename) {
        this->Write("Switching logger from " + this->filename + " to " + filename + ".");
        this->filename = filename;
    }
    std::ofstream logfile;
    logfile.open(this->filename, std::ios::app);
    if (logfile.is_open()) {
        logfile << Time();
        logfile << "Successfully created logger.\n";
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
    retval = month + "/" + day + "/" + year + "@" + hour + ":" + minute + ":" + second + "->";
    return retval;
}

void Logger::Write(std::string toLogger) {
    std::ofstream logfile("logs/" + filename);
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
