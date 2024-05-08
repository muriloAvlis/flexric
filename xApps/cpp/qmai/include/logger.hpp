/**
 * @file logger.hpp
 * @author Murilo C. da Silva (murilosilva@itec.ufpa.br)
 * @brief A log lib for QMAI-xApp
 * @version 0.0.1
 * @date 2024-05-06
 *
 * @copyright Copyright (c) 2024 Murilo Silva - All Rights Reserved
 *
 */

#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <iostream>
#include <ctime>
#include <filesystem>
#include <vector>

using std::string, std::cout, std::time_t, std::strftime, std::localtime;

class Logger
{
private:
    string xAppName;

    std::vector<string> levelStr{
        "\033[1;34mDEBUG\033[0m",
        "\033[1;32mINFO\033[0m",
        "\033[1;33mWARNING\033[0m",
        "\033[1;31mERROR\033[0m"};

    /**
     * @brief Get the Timestamp
     *
     * @return string
     */
    string getTimestamp();

    /**
     * @brief Get the Filename
     *
     * @return string
     */
    string getFilename();

public:
    // log level types
    enum class Level
    {
        DEBUG,
        INFO,
        WARNING,
        ERROR
    };

    Level logLevel;

    /**
     * @brief Construct a new Logger object
     *
     * @param logLevel
     * @param xAppName
     */
    Logger(Level logLevel = Level::INFO, const string &xAppName = "QMAI-xApp");

    /**
     * @brief Print info message
     *
     * @param message
     */
    void info(const string &message);

    /**
     * @brief Print warning message
     *
     * @param message
     */
    void warn(const string &message);

    /**
     * @brief Print error message
     *
     * @param message
     */
    void error(const string &message);

    /**
     * @brief Print debug message
     *
     * @param message
     */
    void debug(const string &message);

    /**
     * @brief Get the Log Level
     *
     * @return Level
     */
    Level getLogLevel();

    /**
     * @brief Set the Log Level
     *
     * @param logLevel
     */
    void setLogLevel(Level logLevel);
};

#endif // LOGGER_HPP