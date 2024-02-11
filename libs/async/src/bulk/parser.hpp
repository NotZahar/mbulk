#pragma once

#include <string_view>

namespace async {
    class Parser {
    public:
        enum class expression {
            openingBrace,
            closingBrace,
            command
        };

        Parser() = default;

        ~Parser() = default;

        static expression identifyExpression(const std::string_view string);

        static constexpr std::string_view openingBraceTkn = "{";
        static constexpr std::string_view closingBraceTkn = "}";
    };
}
