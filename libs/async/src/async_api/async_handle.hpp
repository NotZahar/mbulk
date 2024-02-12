#pragma once

#include <memory>

#include <boost/asio.hpp>

namespace async {
    namespace asio = boost::asio;

    class AsyncHandle {
    public:
        AsyncHandle();

        virtual ~AsyncHandle() = default;

    protected:
        template <class Function>
        void appendTask(Function function) {
            asio::post(_taskQueue, std::move(function));
        }

        void finish();

    private:
        boost::asio::thread_pool _taskQueue;
    };
}
