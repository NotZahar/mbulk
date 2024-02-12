#pragma once

#include <cstddef>
#include <string>
#include <mutex>
#include <memory>

#include <boost/asio.hpp>

namespace async {
    namespace asio = boost::asio;

    class LogQueue {
    public:
        LogQueue() = default;
        ~LogQueue() = default;

        static void stdLog(const std::string& log);
        static void fileLog(const std::string& log);
        static void reset();

    private:
        static constexpr std::size_t _stdNumberOfThreads = 1;
        static constexpr std::size_t _fileNumberOfThreads = 2;

        inline static std::mutex 
            _stdMutex, 
            _fileMutex;
        inline static asio::thread_pool 
            _stdQueue{ _stdNumberOfThreads }, 
            _fileQueue{ _fileNumberOfThreads };
    };
}
