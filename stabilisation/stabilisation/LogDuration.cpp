#include "LogDuration.h"

LogDuration::LogDuration(const std::string& operation_name)
    : operation_name_(operation_name) {
}

LogDuration::~LogDuration() {
    using namespace std::chrono;
    using namespace std::literals;

    const auto end_time = Clock::now();
    const auto dur = end_time - start_time_;
    printf("%s: %d s\n", operation_name_, duration_cast<milliseconds>(dur).count());
    //std::cerr << operation_name_ << ": "s << duration_cast<milliseconds>(dur).count() << " ms"s << std::endl;
    }
