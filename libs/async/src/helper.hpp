#pragma once

#include <string>
#include <chrono>

#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <boost/lexical_cast.hpp>

namespace async {
    namespace chrono = std::chrono;
    namespace uuids = boost::uuids;

    struct utility {
        static std::string getNow() {
            const auto now = chrono::system_clock::now();
            return std::to_string(
                chrono::duration_cast<chrono::milliseconds>(
                    now.time_since_epoch()
                ).count()
            );
        }
        
        static std::string getUUID() {
            return boost::lexical_cast<std::string>(uuids::random_generator()());
        }
    };

    struct messages {
        inline static const std::string BULK = "bulk";
        inline static const std::string BULK_CONTENT = "bulk:";
        inline static const std::string LOG_EXT = ".log";
    };
}
