#pragma once

#include <chrono>
#include <iostream>

class LogDuration {
    // заменим имя типа std::chrono::steady_clock 
    // с помощью using для удобства 
    using Clock = std::chrono::steady_clock;

    LogDuration(const std::string& operation_name);

    ~LogDuration();

private:
    const Clock::time_point start_time_ = Clock::now();
    std::string operation_name_;
};

