#pragma once

namespace async {
    class BulkHandler {
    public:
        BulkHandler() = delete;
        explicit BulkHandler(int batchSize);

        ~BulkHandler() = default;

        void exec();

    private:
        const int _size;
    };
}
