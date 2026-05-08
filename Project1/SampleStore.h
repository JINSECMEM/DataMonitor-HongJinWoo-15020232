#pragma once
#include "Sample.h"
#include <vector>
#include <optional>

class SampleStore {
public:
    static SampleStore& instance();

    const std::vector<Sample>& all() const;
    std::optional<Sample>      find(int id) const;

private:
    SampleStore();
    std::vector<Sample> samples_;
};
