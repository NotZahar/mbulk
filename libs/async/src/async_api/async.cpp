#include "async.hpp"

#include "../bulk/bulk_handle.hpp"

namespace async {
    handle_t connect(std::size_t bulk) {
        return new BulkHandle{ bulk };
    }

    void receive(handle_t handle, const char* data, std::size_t size) {
        auto bulkHandle = reinterpret_cast<BulkHandle*>(handle);
        bulkHandle->receive(std::string(data, size));
    }

    void disconnect(handle_t handle) {
        auto bulkHandle = reinterpret_cast<BulkHandle*>(handle);
        bulkHandle->endReceive();
        bulkHandle->finish();
        // delete bulkHandle;
    }
}