/**
 * @file logger.cpp
 * @author Murilo C. da Silva (murilosilva@itec.ufpa.br)
 * @brief A log lib for QMAI-xApp
 * @version 0.0.1
 * @date 2024-05-06
 *
 * @copyright Copyright (c) 2024 Murilo Silva - All Rights Reserved
 *
 */

#include "../include/logger.hpp"

#include <iostream>
#include <ctime>
#include <fstream>

using std::string, std::cout, std::time_t, std::strftime, std::localtime;

Logger::Logger(Level logLevel, const string &xAppName) : xAppName(xAppName), logLevel(logLevel) {}

string Logger::getTimestamp()
{
    char timestamp[64]; // time length

    const time_t now = std::time(nullptr);                                        // datetime
    strftime(timestamp, sizeof(timestamp), "%d-%m-%Y %H:%M:%S", localtime(&now)); // format datetime
    return string(timestamp);
}

// FIXME
string Logger::getFilename()
{
    // only for Linux
    string sp;
    std::ifstream("/proc/self/comm") >> sp;
    return sp + ".cpp";
}

Logger::Level Logger::getLogLevel()
{
    return Logger::logLevel;
}

void Logger::setLogLevel(Level logLevel)
{
    Logger::logLevel = logLevel;
}
