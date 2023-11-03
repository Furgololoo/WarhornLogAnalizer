#ifndef SCOPEDTIMER_H
#define SCOPEDTIMER_H

#include <chrono>
#include <string>

class ScopedTimer
{
public:
    ScopedTimer(std::string_view function);
    ScopedTimer(const ScopedTimer &) = delete;
    ScopedTimer &operator=(const ScopedTimer &) = delete;
    ScopedTimer(ScopedTimer &&) noexcept = delete;
    ScopedTimer &operator=(ScopedTimer &&) noexcept = delete;

    ~ScopedTimer();

private:
    std::chrono::time_point<std::chrono::steady_clock> start;
    std::string_view functionName;
};

#endif // SCOPEDTIMER_H
