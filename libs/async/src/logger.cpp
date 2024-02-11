#include "logger.hpp"

#include <iostream>
#include <fstream>
#include <chrono>

#include "helper.hpp"

namespace async {
    Logger& Logger::instance() {
        static Logger instance;
        return instance;
    }

    void Logger::stdoutLog(const std::string& string) const {
        std::cout << string << '\n';
    }
    
    void Logger::fileLog(const std::string& string) const {
        const auto logName = messages::BULK + utility::getNow() + '_' + utility::getUUID();
        std::ofstream logFile(logName + messages::LOG_EXT);
        logFile << string << '\n';
        logFile.close();
    }
}