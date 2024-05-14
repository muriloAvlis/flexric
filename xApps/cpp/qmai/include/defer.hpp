/**
 * @file defer.hpp
 * @author Ginger Bill (bill@gingerbill.org)
 * @brief The defer library with my adjusts :)
 * @version 0.0.1
 * @date 2015-08-19
 */

#pragma once

template <typename F>
struct privDefer
{
    F f;
    privDefer(F f) : f(f) {}
    ~privDefer() { f(); }
};

template <typename F>
privDefer<F> defer_func(F f)
{
    return privDefer<F>(f);
}

#if !defined(DEFER_1) && !defined(DEFER_2) && !defined(DEFER_3) && !defined(defer)
#define DEFER_1(x, y) x##y
#define DEFER_2(x, y) DEFER_1(x, y)
#define DEFER_3(x) DEFER_2(x, __COUNTER__)
#define defer(code) auto DEFER_3(_defer_) = defer_func([&]() { code; })
#endif