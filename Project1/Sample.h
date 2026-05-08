#pragma once
#include <string>

struct Sample {
    int         id;
    std::string name;
    double      avg_production_time; // minutes
    double      yield_rate;          // 0.0 ~ 100.0 (%)
};
