#pragma once

#include <chrono>
#include <iostream>

class LogDuration {
    // ������� ��� ���� std::chrono::steady_clock 
    // � ������� using ��� �������� 
    using Clock = std::chrono::steady_clock;

    LogDuration(const std::string& operation_name);

    ~LogDuration();

private:
    const Clock::time_point start_time_ = Clock::now();
    std::string operation_name_;
};

