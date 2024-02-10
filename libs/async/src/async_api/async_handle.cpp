#include "async_handle.hpp"

#include "async_handle_threads.hpp"

namespace async {
    AsyncHandle::AsyncHandle() 
    {
        _contextPtr = std::make_shared<asio::io_context>();
        _workGuardPtr = std::make_shared<
                asio::executor_work_guard<decltype(_contextPtr->get_executor())>
            >(_contextPtr->get_executor());
        AsyncHandleThreads::instance().appendThread(
            [contextPtr = _contextPtr] { contextPtr->run(); }
        );
    }

    AsyncHandle::~AsyncHandle() {
        _workGuardPtr->reset();
    }
}