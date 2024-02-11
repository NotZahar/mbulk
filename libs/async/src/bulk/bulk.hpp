#pragma once

#include <cstddef>
#include <cassert>
#include <list>

#include "logger.hpp"
#include "helper.hpp"

namespace async {
    template <class T>
    class Bulk {
    public:
        Bulk() = delete;
        Bulk(std::size_t size)
            : _maxSize(size)
        {}

        ~Bulk() = default;

        virtual void append(T element) = 0;
        
        virtual void end() {
            if (_batch.empty())
                return;

            const auto log = serialize();
            Logger::instance().stdoutLog(log);
            Logger::instance().fileLog(log);
            clear();
        }

    protected:
        virtual void clear() = 0;
        
        virtual std::string serialize() const {
            std::string serializedBatch = "";
            if (_batch.empty())
                return serializedBatch;

            serializedBatch += messages::BULK_CONTENT;
            auto it = _batch.cbegin();
            serializedBatch += (" " + *it);
            for (++it; it != _batch.cend(); ++it)
                serializedBatch += (", " + *it);
            return serializedBatch;
        }

        const std::size_t _maxSize;
        std::list<T> _batch;
    };

    template <class T>
    class DBulk : public Bulk<T> {
    public:
        DBulk(std::size_t size)
            : Bulk<T>(size),
              _noNestingLevel(0),
              _nestingLevel(_noNestingLevel)
        {}

        ~DBulk() = default;
        
        void append(T element) override {
            assert(blockExists());
            Bulk<T>::_batch.push_back(element);
        }

        void addBlock() {
            _nestingLevel += 1;
        }

        bool blockExists() const {
            return _nestingLevel != _noNestingLevel;
        }

        void end() override {
            if (Bulk<T>::_batch.empty())
                return;

            _nestingLevel -= 1;
            if (!blockExists()) {
                const auto log = Bulk<T>::serialize();
                Logger::instance().stdoutLog(log);
                Logger::instance().fileLog(log);
                clear();                
            }
        }

    protected:
        void clear() override {
            Bulk<T>::_batch.clear();
            _nestingLevel = _noNestingLevel;
        }

    private:
        const int _noNestingLevel;
        int _nestingLevel;
    };
    
    template <class T>
    class SBulk : public Bulk<T> {
    public:
        SBulk(std::size_t size)
            : Bulk<T>(size)
        {}

        ~SBulk() = default;

        std::size_t size() const {
            return Bulk<T>::_batch.size();
        }
        
        void append(T element) override {
            assert(size() < Bulk<T>::_maxSize);
            Bulk<T>::_batch.push_back(element);
        }

    protected:
        void clear() override {
            Bulk<T>::_batch.clear();
        }
    };
}
