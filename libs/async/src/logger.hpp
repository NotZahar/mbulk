#pragma once

#include <string>

namespace async {
    class Logger {
    public:
        Logger() = default;
        ~Logger() = default;

        static void stdLog(const std::string& string);
        static void fileLog(const std::string& string);
    };
}
