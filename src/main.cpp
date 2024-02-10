#include <cstddef>
#include <thread>

#include <async.hpp>

int main() {
    std::jthread thread1{[]() {
        std::size_t bulk1 = 5; 
        auto handle1 = async::connect(bulk1);
        async::receive(handle1, "1", 10);
        async::receive(handle1, "\n2\n3\n4\n5\n6\n{\na\n", 11);
        async::receive(handle1, "b\nc\nd\n}\n89\n", 12);
        async::receive(handle1, "b\nc\nd\n}\n89\n", 13);
        async::receive(handle1, "b\nc\nd\n}\n89\n", 14);
        async::disconnect(handle1);
    }};

    std::jthread thread2{[]() { 
        std::size_t bulk2 = 5;
        auto handle2 = async::connect(bulk2);
        async::receive(handle2, "1\n", 20);
        async::disconnect(handle2);
    }};

    std::jthread thread3{[]() {
        std::size_t bulk3 = 5; 
        auto handle3 = async::connect(bulk3);
        async::receive(handle3, "1\n", 30);
        async::disconnect(handle3);
    }};

    std::jthread thread4{[]() {
        std::size_t bulk4 = 5; 
        auto handle4 = async::connect(bulk4);
        async::receive(handle4, "1\n", 40);
        async::receive(handle4, "1\n", 41);
        async::receive(handle4, "1\n", 42);
        async::receive(handle4, "1\n", 43);
        async::disconnect(handle4);
    }};

    std::jthread thread5{[]() {
        std::size_t bulk5 = 5; 
        auto handle5 = async::connect(bulk5);
        async::receive(handle5, "1\n", 50);
        async::disconnect(handle5);
    }};

    std::jthread thread6{[]() {
        std::size_t bulk6 = 5; 
        auto handle6 = async::connect(bulk6);
        async::receive(handle6, "1\n", 60);
        async::disconnect(handle6);
    }};

    return 0;
}
