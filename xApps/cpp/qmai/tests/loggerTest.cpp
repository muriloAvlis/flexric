#include <logger.hpp>

int main(int argc, char const *argv[])
{
    // set INFO level
    Logger log(Logger::Level::INFO);
    log.info("Show informational messages only");

    // change log leve to WARNING
    log.setLogLevel(Logger::Level::WARNING);
    log.warn("Show informational and warning messages");

    // change log leve to ERROR
    log.setLogLevel(Logger::Level::ERROR);
    log.error("Show informational, warning and error messages");

    // change log leve to ERROR
    log.setLogLevel(Logger::Level::DEBUG);
    log.debug("Show all level messages");
    return EXIT_SUCCESS;
}