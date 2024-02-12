#include "log_queue.hpp"

#include "logger.hpp"

namespace async {
    void LogQueue::stdLog(const std::string& log) {
        std::lock_guard lock{ _stdMutex };
        boost::asio::post(_stdQueue, [log] {
            Logger::stdLog(log);
        });
    }
    
    void LogQueue::fileLog(const std::string& log) {
        std::lock_guard lock{ _fileMutex };
        boost::asio::post(_fileQueue, [log] {
            Logger::fileLog(log);
        });
    }

    void LogQueue::reset() {
        _stdQueue.join();
        _fileQueue.join();
    }
}