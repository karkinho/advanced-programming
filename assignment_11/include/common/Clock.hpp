#ifndef CLOCK_HPP
#define CLOCK_HPP

#include <chrono>

class Clock
{
private:
    using Clock_t = std::chrono::high_resolution_clock;
    Clock_t::time_point start , timer;
    double tick, timerValue;
    Clock();
    inline static Clock * clock = nullptr;
public:
    ~Clock();
    static Clock * GetClock();
    void Tick();
    double GetTick();
    void StartTimer();
    double StopGetTimer();
    double GetTimer();
};

#endif