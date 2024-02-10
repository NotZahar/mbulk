#include "async.hpp"

#include <iostream>

#include "async_handle.hpp"

namespace async {
    handle_t connect(std::size_t /*bulk*/) {
        return new AsyncHandle{};
    }

    void receive(handle_t handle, const char */*data*/, std::size_t size) {
        auto asyncHandle = reinterpret_cast<AsyncHandle*>(handle);
        asyncHandle->appendTask([size]() {
            auto sum = 0ll;
            for (long long i = 0; i < 100'000'000; ++i) {
                sum += 1;
            }

            std::cout << sum << ' ' << size << '\n'; 
        });
    }

    void disconnect(handle_t handle) {
        auto asyncHandle = reinterpret_cast<AsyncHandle*>(handle);
        // std::cout << "delete\n";
        delete asyncHandle;
    }
}