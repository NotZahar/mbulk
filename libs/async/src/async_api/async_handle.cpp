#include "async_handle.hpp"

namespace async {
    AsyncHandle::AsyncHandle()
        : _taskQueue(1)
    {}

    void AsyncHandle::finish() {
        _taskQueue.join();
    }
}