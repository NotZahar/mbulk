#pragma once

#include <mutex>

#include <boost/asio.hpp>

namespace async {
    namespace asio = boost::asio;

    class AsyncHandleThreads final {
    public:
        AsyncHandleThreads(const AsyncHandleThreads&) = delete;
        AsyncHandleThreads(AsyncHandleThreads&&) = delete;
        AsyncHandleThreads& operator=(AsyncHandleThreads const&) = delete;
        AsyncHandleThreads& operator=(AsyncHandleThreads &&) = delete;
        
        static AsyncHandleThreads& instance();

        template <class Function>
        void appendThread(Function function) {
            std::lock_guard lock{ _mutex };
            _threads.create_thread(std::move(function));
        }

    private:
        AsyncHandleThreads();
        ~AsyncHandleThreads() = default;

        std::mutex _mutex;
        asio::detail::thread_group _threads;
    };
}
