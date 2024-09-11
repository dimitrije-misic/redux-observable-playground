#pragma once
#include <variant>

namespace counter
{
    namespace actions
    {
        struct increment {};
        struct decrement {};
        struct reset { int value = 0; };
    }

    using action = std::variant<actions::increment, actions::decrement, actions::reset>;
}