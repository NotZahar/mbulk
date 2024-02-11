#include <cstddef>
#include <thread>

#include <async.hpp>

int main() {
    std::jthread thread1{[]() {
        std::size_t bulk = 3; 
        auto handle = async::connect(bulk);
        async::receive(handle, "cmd1 1", 6);
        async::receive(handle, "cmd2 1", 6);
        async::receive(handle, "{", 1);
        async::receive(handle, "cmd3 1", 6);
        async::receive(handle, "cmd4 1", 6);
        async::receive(handle, "}", 1);
        async::receive(handle, "{", 1);
        async::receive(handle, "cmd5 1", 6);
        async::receive(handle, "cmd6 1", 6);
        async::receive(handle, "{", 1);
        async::receive(handle, "cmd7 1", 6);
        async::receive(handle, "cmd8 1", 6);
        async::receive(handle, "}", 1);
        async::receive(handle, "cmd9 1", 6);
        async::receive(handle, "}", 1);
        async::receive(handle, "{", 1);
        async::receive(handle, "cmd10 1", 6);
        async::receive(handle, "cmd11 1", 6);
        async::disconnect(handle);
    }};

    std::jthread thread2{[]() { 
        std::size_t bulk = 3; 
        auto handle = async::connect(bulk);
        async::receive(handle, "cmd1 2", 6);
        async::receive(handle, "cmd2 2", 6);
        async::receive(handle, "{", 1);
        async::receive(handle, "cmd3 2", 6);
        async::receive(handle, "cmd4 2", 6);
        async::receive(handle, "}", 1);
        async::receive(handle, "{", 1);
        async::receive(handle, "cmd5 2", 6);
        async::receive(handle, "cmd6 2", 6);
        async::receive(handle, "{", 1);
        async::receive(handle, "cmd7 2", 6);
        async::receive(handle, "cmd8 2", 6);
        async::receive(handle, "}", 1);
        async::receive(handle, "cmd9 2", 6);
        async::receive(handle, "}", 1);
        async::receive(handle, "{", 1);
        async::receive(handle, "cmd10 2", 6);
        async::receive(handle, "cmd11 2", 6);
        async::disconnect(handle);
    }};

    std::jthread thread3{[]() {
        std::size_t bulk = 3; 
        auto handle = async::connect(bulk);
        async::receive(handle, "cmd1 3", 6);
        async::receive(handle, "cmd2 3", 6);
        async::receive(handle, "{", 1);
        async::receive(handle, "cmd3 3", 6);
        async::receive(handle, "cmd4 3", 6);
        async::receive(handle, "}", 1);
        async::receive(handle, "{", 1);
        async::receive(handle, "cmd5 3", 6);
        async::receive(handle, "cmd6 3", 6);
        async::receive(handle, "{", 1);
        async::receive(handle, "cmd7 3", 6);
        async::receive(handle, "cmd8 3", 6);
        async::receive(handle, "}", 1);
        async::receive(handle, "cmd9 3", 6);
        async::receive(handle, "}", 1);
        async::receive(handle, "{", 1);
        async::receive(handle, "cmd10 3", 6);
        async::receive(handle, "cmd11 3", 6);
        async::disconnect(handle);
    }};

    std::jthread thread4{[]() {
        std::size_t bulk = 3; 
        auto handle = async::connect(bulk);
        async::receive(handle, "cmd1 4", 6);
        async::receive(handle, "cmd2 4", 6);
        async::receive(handle, "{", 1);
        async::receive(handle, "cmd3 4", 6);
        async::receive(handle, "cmd4 4", 6);
        async::receive(handle, "}", 1);
        async::receive(handle, "{", 1);
        async::receive(handle, "cmd5 4", 6);
        async::receive(handle, "cmd6 4", 6);
        async::receive(handle, "{", 1);
        async::receive(handle, "cmd7 4", 6);
        async::receive(handle, "cmd8 4", 6);
        async::receive(handle, "}", 1);
        async::receive(handle, "cmd9 4", 6);
        async::receive(handle, "}", 1);
        async::receive(handle, "{", 1);
        async::receive(handle, "cmd10 4", 6);
        async::receive(handle, "cmd11 4", 6);
        async::disconnect(handle);
    }};

    return 0;
}
