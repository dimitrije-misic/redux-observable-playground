#pragma once
#include <lager/util.hpp>
#include "state.h"
#include "actions.h"

namespace counter
{
    state reducer(state s, action a)
    {
        return std::visit(lager::visitor
            {
                [&s](actions::increment)
                {
                    ++s.value;
                    return s;
                },
                [&s](actions::decrement)
                {
                    --s.value;
                    return s;
                },
                [&s](actions::reset r)
                {
                    s.value = r.value;
                    return s;
                }
            }, a);
    }
}