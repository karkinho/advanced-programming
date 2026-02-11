#include "common/Clock.hpp"

Clock::Clock() {
    start = std::chrono::high_resolution_clock::now();
}

Clock::~Clock() {

}

Clock * Clock::GetClock() {
    if( clock == nullptr ) {
        clock = new Clock();
    }
    return clock;
}

double Clock::GetTick() {
    return tick;
}

void Clock::Tick() {
    std::chrono::high_resolution_clock::time_point now;
    now = std::chrono::high_resolution_clock::now();
    tick = std::chrono::duration_cast<std::chrono::duration<double>>(now - start).count();
    start = now;
}

void Clock::StartTimer() {
    timer = std::chrono::high_resolution_clock::now();
}

double Clock::StopGetTimer() {
    std::chrono::high_resolution_clock::time_point now;
    now = std::chrono::high_resolution_clock::now();
    timerValue = std::chrono::duration_cast<std::chrono::duration<double>>(now - timer).count();
    return timerValue;
}

double Clock::GetTimer() {
    return timerValue;
}