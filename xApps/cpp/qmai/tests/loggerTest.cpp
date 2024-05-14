#include <logger.hpp>

int main(int argc, char const *argv[])
{
    Logger logger;
    // set INFO level
    logger.info("Num é possível");

    // set WARN level (default)
    logger.setLogLevel(Logger::Level::WARNING);
    logger.warn("Sim é!");

    // set ERROR level
    logger.setLogLevel(Logger::Level::ERROR);
    logger.error("Demorei um dia fazendo isso :(");

    // set DEBUG level
    logger.setLogLevel(Logger::Level::DEBUG);
    logger.debug("F...");
}