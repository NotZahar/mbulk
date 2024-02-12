#include "logger.hpp"

#include <iostream>
#include <fstream>

#include "helper.hpp"

namespace async {
    void Logger::stdLog(const std::string& string) {
        std::cout << string << '\n';
    }
    
    void Logger::fileLog(const std::string& string) {
        const auto logName = messages::BULK + utility::now() + '_' + utility::UUID();
        std::ofstream logFile(logName + messages::LOG_EXT);
        logFile << string << '\n';
        logFile.close();
    }
}