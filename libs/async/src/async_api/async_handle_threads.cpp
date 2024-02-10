#include "async_handle_threads.hpp"

namespace async {
    AsyncHandleThreads::AsyncHandleThreads()
    {}

    AsyncHandleThreads& AsyncHandleThreads::instance() {
        static AsyncHandleThreads instance;
        return instance;
    }
}