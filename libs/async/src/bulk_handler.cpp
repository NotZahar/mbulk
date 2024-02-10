#include "bulk_handler.hpp"

#include <iostream>
#include <string>

#include "batch.hpp"
#include "parser.hpp"

namespace async {
    BulkHandler::BulkHandler(int size)
        : _size(size)
    {}

    void BulkHandler::exec() {
        SBatch<std::string> sbatch(_size);
        DBatch<std::string> dbatch(_size);
        for (std::string in; std::getline(std::cin, in);) {
            switch (Parser::identifyExpression(in)) {
            case Parser::expression::openingBrace:
                sbatch.end();
                dbatch.addBlock();
                break;
            case Parser::expression::closingBrace:
                dbatch.end();
                break;
            case Parser::expression::command:
                if (dbatch.blockExists()) {
                    dbatch.append(in);
                    continue;
                }
                
                sbatch.append(in);
                break;
            }

            if (sbatch.size() == _size)
                sbatch.end();
        }

        sbatch.end();
    }
}