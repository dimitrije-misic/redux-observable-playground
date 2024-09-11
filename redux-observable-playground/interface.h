#pragma once
#include <optional>
#include <iostream>
#include "actions.h"
#include "state.h"

namespace counter
{
    std::optional<action> parse(char event)
    {
        switch (event)
        {
        case '+':
            return actions::increment{};
        case '-':
            return actions::decrement{};
        case '.':
            return actions::reset{};
        default:
            return std::nullopt;
        }
    }

    void render(state s)
    {
        std::cout << "Current counter value: " << s.value << std::endl;
    }
}