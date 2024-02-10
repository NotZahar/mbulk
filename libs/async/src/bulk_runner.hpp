#pragma once

namespace async {
    class BulkRunner {
    public:
        BulkRunner() = delete;
        explicit BulkRunner(int batchSize);

        ~BulkRunner() = default;

        void exec();

    private:
        const int _size;
    };
}
