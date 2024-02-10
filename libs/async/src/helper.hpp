#pragma once

#include <string>

namespace async {
    struct messages {
        inline static const std::string BULK = "bulk";
        inline static const std::string BULK_CONTENT = "bulk:";
        inline static const std::string LOG_EXT = ".log";
    };
}
