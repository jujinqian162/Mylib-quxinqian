#pragma once

#include <chrono>

struct TimeResult
{
    typedef long double time;
    time one_action_time;
    time sum_time;
};


template<typename Fn, typename ...Args>
TimeResult pressure(intmax_t times, Fn&& func, Args&&... args){
    auto begin = std::chrono::high_resolution_clock::now();
    for (intmax_t i = 0; i < times; ++i){
        func(args...);
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto _b = begin.time_since_epoch().count();
    auto _e = end.time_since_epoch().count();
    return {static_cast<long double>(_e - _b) / static_cast<long double>(times)
    , static_cast<long double>(_e - _b)
    };
}