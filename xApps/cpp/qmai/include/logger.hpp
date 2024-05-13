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

#pragma once

#include <iostream>
#include <ctime>
#include <vector>

using std::string, std::cout, std::time_t, std::strftime, std::localtime;

class Logger
{
private:
    string xAppName;

    std::vector<string> levelMsg{
        "\033[1;32mINFO\033[0m",
        "\033[1;33mWARNING\033[0m",
        "\033[1;31mERROR\033[0m",
        "\033[1;34mDEBUG\033[0m"};

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
        INFO,
        WARNING,
        ERROR,
        DEBUG
    };

    Level logLevel;

    /**
     * @brief Construct a new Logger object
     *
     * @param logLevel
     * @param xAppName
     */
    Logger(Level logLevel = Level::WARNING, const string &xAppName = "QMAI-xApp");

    /**
     * @brief Print info message
     *
     * @param message
     */

    template <typename T>
    void info(const T &message)
    {
        cout << "[" << this->getTimestamp() << "]"
             << "[" << this->levelMsg.at(static_cast<u_int8_t>(this->Level::INFO)) << "]"
             << "["
             << this->xAppName
             << "]"
             << "[" << this->getFilename() << "] "
             << message << '\n';
    }

    /**
     * @brief Print warning message
     *
     * @param message
     */

    template <typename T>
    void warn(const T &message)
    {
        if (this->getLogLevel() != this->Level::INFO)
        {
            cout << "[" << this->getTimestamp() << "]"
                 << "[" << this->levelMsg.at(static_cast<u_int8_t>(this->Level::WARNING)) << "]"
                 << "["
                 << this->xAppName
                 << "]"
                 << "[" << this->getFilename() << "] "
                 << message << '\n';
        }
    }

    /**
     * @brief Print error message
     *
     * @param message
     */
    template <typename T>
    void error(const T &message)
    {
        if (this->getLogLevel() != this->Level::WARNING &&
            this->getLogLevel() != this->Level::INFO)
        {
            cout << "[" << this->getTimestamp() << "]"
                 << "[" << this->levelMsg.at(static_cast<u_int8_t>(this->Level::ERROR)) << "]"
                 << "["
                 << this->xAppName
                 << "]"
                 << "[" << this->getFilename() << "] "
                 << message << '\n';
        }
    }

    /**
     * @brief Print debug message
     *
     * @param message
     */
    template <typename T>
    void debug(const T &message)
    {
        if (this->getLogLevel() == this->Level::DEBUG)
        {
            cout << "[" << this->getTimestamp() << "]"
                 << "[" << this->levelMsg.at(static_cast<u_int8_t>(this->Level::DEBUG)) << "]"
                 << "["
                 << this->xAppName
                 << "]"
                 << "[" << this->getFilename() << "] "
                 << message << '\n';
        }
    }

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