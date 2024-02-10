#pragma once

#include <string_view>

namespace async {
    class Logger final {
    public:
        Logger(const Logger&) = delete;
        Logger(Logger&&) = delete;
        Logger& operator=(Logger const&) = delete;
        Logger& operator=(Logger &&) = delete;
        
        static Logger& instance();
        void log(const std::string& string) const;

    private:
        Logger() = default;
        ~Logger() = default;
    };
}
