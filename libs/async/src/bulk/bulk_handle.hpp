#pragma once

#include <cstddef>
#include <string>

#include "../async_api/async_handle.hpp"
#include "bulk.hpp"

namespace async {
    class BulkHandle : public AsyncHandle {
    public:
        BulkHandle() = delete;
        explicit BulkHandle(std::size_t batchSize);

        ~BulkHandle() override = default;

        void receive(std::string expression);
        void endReceive();

    private:
        const std::size_t _size;
        SBulk<std::string> _sbulk;
        DBulk<std::string> _dbulk;
    };
}
