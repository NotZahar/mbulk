#include "log_queue.hpp"

#include "logger.hpp"

namespace async {
    void LogQueue::stdLog(const std::string& log) {
        std::lock_guard lock{ _stdMutex };
        boost::asio::post(_stdPool, [log] {
            Logger::stdLog(log);
        });
    }
    
    void LogQueue::fileLog(const std::string& log) {
        std::lock_guard lock{ _fileMutex };
        boost::asio::post(_filePool, [log] {
            Logger::fileLog(log);
        });
    }
}