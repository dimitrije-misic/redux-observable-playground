// redux-observable-playground.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <lager/store.hpp>
#include <lager/event_loop/manual.hpp>

#include <zug/run.hpp>
#include <zug/transducer/read.hpp>
#include <zug/transducer/map.hpp>
#include <zug/transducer/filter.hpp>
#include <zug/transducer/sink.hpp>

#include <functional>

#include "interface.h"
#include "reducer.h"

int main()
{
    auto store = lager::make_store<counter::action>(
        counter::state{},
        lager::with_manual_event_loop{},
        lager::with_reducer(counter::reducer));

    watch(store, counter::render);

    zug::run(zug::read<char>(std::cin)
        | zug::map(counter::parse)
        | zug::filter([](auto optional) { return bool(optional); })
        | zug::map([](auto optional) { return *optional; })
        | zug::sink([&store](auto value) { store.dispatch(value); }));
}