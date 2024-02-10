#pragma once

#include <boost/asio/dispatch.hpp>
#include <memory>

#include <boost/asio.hpp>

namespace async {
    namespace asio = boost::asio;

    class AsyncHandle {
    public:
        AsyncHandle();

        ~AsyncHandle();

        template <class Function>
        void appendTask(Function function) {
            asio::post(*_contextPtr, std::move(function));
        }

    private:
        std::shared_ptr<asio::io_context> _contextPtr;
        std::shared_ptr<
                asio::executor_work_guard<decltype(_contextPtr->get_executor())>
            > _workGuardPtr;
    };
}
