#include "bulk_handle.hpp"

#include "parser.hpp"

namespace async {
    BulkHandle::BulkHandle(std::size_t batchSize)
        : _size(batchSize),
          _sbulk(_size),
          _dbulk(_size)
    {}

    void BulkHandle::receive(std::string expression) {
        AsyncHandle::appendTask([this, expression] { // TODO: UB: this
            switch (Parser::identifyExpression(expression)) {
            case Parser::expression::openingBrace:
                _sbulk.end();
                _dbulk.addBlock();
                break;
            case Parser::expression::closingBrace:
                _dbulk.end();
                break;
            case Parser::expression::command:
                if (_dbulk.blockExists()) {
                    _dbulk.append(expression);
                    return;
                }
                
                _sbulk.append(expression);
                break;
            }

            if (_sbulk.size() == _size)
                _sbulk.end();
        });
    }

    void BulkHandle::endReceive() {
        AsyncHandle::appendTask([this] { // TODO: UB: this
            _sbulk.end();
        });
    }
}